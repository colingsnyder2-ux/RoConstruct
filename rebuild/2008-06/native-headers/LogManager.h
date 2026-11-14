#pragma once

#include "util/Log.h"
#include <boost/scoped_ptr.hpp>
#include <exception>
#include <string>

class RobloxCrashReporter;

class LogManager
{
protected:
    RBX::Log* log;
    const DWORD threadId;
    std::string name;

public:
    explicit LogManager(const char* label);
    virtual ~LogManager();
    RBX::Log* getLog();
    virtual std::string getLogPath() = 0;
    static void ReportException(const std::exception& error);
};

class MainLogManager : public RBX::ILogProvider, public LogManager
{
    boost::scoped_ptr<RobloxCrashReporter> crashReporter;
    std::string logIdentity;

public:
    explicit MainLogManager(const char* productName);
    virtual ~MainLogManager();
    virtual RBX::Log* provideLog();
    virtual std::string getLogPath();
    void startCrashReporter();
};

class ThreadLogManager : public LogManager
{
public:
    ThreadLogManager();
    virtual ~ThreadLogManager() {}
    virtual std::string getLogPath();
};
