#include <string>
#include "Message.h"

Message::Message() :
    data("")
{
}

void Message::setData(const std::string& deviceName, const std::string measurementName, const double& measurementValue)
{
    data = deviceName + "\t## " + measurementName + "\t## " + std::to_string(measurementValue);
}

Message& Message::getInstance()
{
    static Message instance;
    return instance;
}

void Message::sendMessage(const std::string& deviceName, const std::string measurementName, const double& measurementValue)
{
    std::lock_guard<std::mutex> lk(mutex);
    clearData();
    setData(deviceName, measurementName, measurementValue);

    messageQueue.push(data);
    cv.notify_one();
}

std::string Message::getMessage()
{
    std::unique_lock<std::mutex> lock(mutex);

    cv.wait(lock, [&]() { return not messageQueue.empty(); });
    std::string message = messageQueue.front();
    messageQueue.pop();

    return message;
}
