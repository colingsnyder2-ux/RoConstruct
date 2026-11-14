#pragma once

#include "util/Log.h"
#include <boost/scoped_ptr.hpp>
#include <exception>
#include <string>
#include <vector>

class RobloxCrashReporter;
class MainLogManager;

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
    static MainLogManager* getMainLogManger();
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
    bool hasCrashLogs() const;
    std::vector<std::string> archiveCrashLogs();
};

class ThreadLogManager : public LogManager
{
public:
    ThreadLogManager();
    virtual ~ThreadLogManager() {}
    virtual std::string getLogPath();
};
