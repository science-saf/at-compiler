#pragma once
class Logger
{
private:
	Logger() {};
	~Logger() {};
public:
	static void log(const std::string& string);
};

