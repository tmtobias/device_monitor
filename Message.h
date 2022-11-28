#pragma once
#include <string>
#include <mutex>
#include <condition_variable>
#include <queue>

class Message
{
	Message();
	void clearData() { data = ""; }
	void setData(const std::string& deviceName, const std::string measurementName, const double& measurementValue);

	std::string data;
	std::condition_variable cv;
	std::mutex mutex;
	std::queue<std::string> messageQueue;

public:
	Message(const Message&) = delete;
	Message& operator=(const Message&) = delete;

	static Message& getInstance();
	void sendMessage(const std::string& deviceName, const std::string measurementName, const double& measurementValue);
	std::string getMessage();
};
