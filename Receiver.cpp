#include <iostream>
#include "Receiver.h"
#include "Message.h"

void Receiver::readMessages() const
{
	Message& message = Message::getInstance();
	while (true)
	{
		const std::string msg = message.getMessage();
		std::cout << msg << std::endl;
	}
}

void Receiver::Start()
{
	t = std::thread(&Receiver::readMessages, this);
}

void Receiver::Join()
{
	if (t.joinable())
	{
		t.join();
	}
}
