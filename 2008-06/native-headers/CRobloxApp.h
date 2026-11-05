#pragma once
#include <afxwin.h>
#include <string>
#include <vector>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "util/boost.hpp"

// Log manager embedded in CRobloxApp at +0xa4 (constructed with "Roblox" by 0042a1c0).
// Layout from that constructor: vptr 008104cc at +0; ThreadLogManager base at +4 with vptr
// 008104c0, +8 = 0, +c = GetCurrentThreadId(), +10 std::string name; then +2c = 0 and
// +30 std::string. sizeof 0x4c, as CRobloxApp's next member sits at +0xf0.
class ThreadLogManager {
public:
    explicit ThreadLogManager(const char* name);
    virtual ~ThreadLogManager();
private:
    void* reserved4;       // +4 (0 after construction; role not recovered)
    DWORD threadId;        // +8
    std::string name;      // +c
};

class LogManagerSink {    // vptr-only first base (008104cc)
public:
    virtual ~LogManagerSink();
};

class MainLogManager : public LogManagerSink, public ThreadLogManager {
public:
    explicit MainLogManager(const char* name);   // 0042a1c0
    ~MainLogManager();
    void startCrashReporter();                    // 00428180
private:
    void* crashReporter;   // +2c (0 after construction)
    std::string reportUrl; // +30 (role provisional)
};

// Crash-report uploader owned through CRobloxApp+0x10c: 28 bytes (new(0x1c) in InitInstance).
// Constructor 0044d610 allocates the 72-byte state; destructor 0044a830.
class ErrorUploader {
    struct data;
    static RBX::worker_thread::work_result upload(boost::shared_ptr<data>);
    boost::shared_ptr<data> state;   // +0
    RBX::worker_thread thread;       // +8
public:
    ErrorUploader();
    ~ErrorUploader();
};

// CRuntimeClass via DECLARE_DYNAMIC (GetRuntimeClass 0044d440). Constructor 0044c3d0:
// CWinApp(NULL) (sizeof 0xa4), MainLogManager("Roblox") at +0xa4, std::string at +0xf0,
// scoped_ptr<ErrorUploader> at +0x10c; vptr 00816a64.
class CRobloxApp : public CWinApp {
    DECLARE_DYNAMIC(CRobloxApp)
public:
    CRobloxApp();
    virtual ~CRobloxApp();                         // 0044c440
    virtual BOOL InitInstance();                   // 0044d810 (slot 22)
    virtual int Run();                             // 0044d790 (slot 23)
    virtual int ExitInstance();                    // 0044ad60 (slot 28)
    BOOL initializeFramework(bool);                // 00449bf0
    void initializeSettings();                     // 0044c760
    void initializeEmptyDocument();                // 0044a2c0
    BOOL openFiles(std::vector<std::string>::iterator, std::vector<std::string>::iterator); // 0044d1b0
    int openFileFailed(std::string);                // 0044a950
    BOOL openFile(std::string);                     // 0044a1f0
    MainLogManager logManager;                     // +0xa4
    std::string version;                           // +0xf0
    boost::scoped_ptr<ErrorUploader> errorUploader; // +0x10c
};
