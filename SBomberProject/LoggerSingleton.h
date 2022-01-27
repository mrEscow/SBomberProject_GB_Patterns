#pragma once

#include <fstream>
#include <string>
//=================================================================================
class LoggerSingleton
{
protected:
	std::ofstream logOut;
	std::string GetCurDateTime();

public:
	void __fastcall OpenLogFile(const std::string& FN);
	void CloseLogFile();

	virtual void __fastcall WriteToLog(const std::string& str) = 0;
	virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;
	virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;

	virtual ~LoggerSingleton() {};
};
//=================================================================================
class FileLoggerSingletone: public LoggerSingleton
{
public:

	static FileLoggerSingletone& getInstance()
	{
		static FileLoggerSingletone theInstance;
		return theInstance;
	}

	void __fastcall WriteToLog(const std::string& str) override;
	void __fastcall WriteToLog(const std::string& str, int n) override;
	void __fastcall WriteToLog(const std::string& str, double d) override;

private:
	FileLoggerSingletone() { }
	FileLoggerSingletone(const FileLoggerSingletone& root) = delete;
	FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
};
//=================================================================================
class ProxyLoggerSingletone : public LoggerSingleton
{
private:
	uint32_t ID{ 1 };
public:

	static ProxyLoggerSingletone& getInstance()
	{
		static ProxyLoggerSingletone theInstance;
		return theInstance;
	}

	void __fastcall WriteToLog(const std::string& str) override;
	void __fastcall WriteToLog(const std::string& str, int n) override;
	void __fastcall WriteToLog(const std::string& str, double d) override;

private:
	ProxyLoggerSingletone() { }
	ProxyLoggerSingletone(const ProxyLoggerSingletone& root) = delete;
	ProxyLoggerSingletone& operator=(const ProxyLoggerSingletone&) = delete;
};
//=================================================================================