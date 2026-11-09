// from server: 45% by colin
struct _EXCEPTION_POINTERS;

struct CrashReportControls {
    char appName[128];
    char appVersion[128];
};

struct CrashReporter {
    int threadResult;
    _EXCEPTION_POINTERS* exceptionInfo;
    char reportCrashEvent[16];
    void* watcherThread;
    bool hangReportingEnabled;
    bool isAlive;
    long deadlockCounter;
    bool destructing;
    bool immediateUploadEnabled;
    bool silentCrashReporting;
    CrashReportControls controls;
    static CrashReporter* singleton;
    CrashReporter();
    ~CrashReporter();
    void Start();
    void WatcherThreadFunc();
    virtual long ProcessException(_EXCEPTION_POINTERS* ExceptionInfo, bool noMsg);
    long ProcessExceptionInThead(_EXCEPTION_POINTERS* ExceptionInfo);
    void TheadFunc(_EXCEPTION_POINTERS* ExceptionInfo);
    void DisableHangReporting();
    void EnableImmediateUpload(bool enabled);
    void NotifyAlive();
    long GenerateDmpFileName(char* dumpFilepath, int cchdumpFilepath, bool fastLog, bool fullDmp);
};

struct RobloxCrashReporter : CrashReporter {
    static bool silent;
    RobloxCrashReporter(const char* outputPath, const char* appName, const char* crashExtention);
    long ProcessException(_EXCEPTION_POINTERS* info, bool noMsg);
    void logEvent(const char* msg);
};

extern "C" {
    int __stdcall SHGetFolderPathAndSubDirA(void* hwnd, int csidl, void* hToken, unsigned long dwFlags, const char* pszSubDir, char* pszPath);
}

extern "C" void __stdcall sub_77e644();
extern "C" void __stdcall sub_77e6a8();
extern "C" void __stdcall sub_77e6ac();
extern "C" void __stdcall sub_77ddb8();
extern "C" void __stdcall sub_77ebc4();
extern "C" void __cdecl sub_630a1e();

extern char byte_78a044[];
extern unsigned int dword_8b5188;

RobloxCrashReporter::RobloxCrashReporter(const char* outputPath, const char* appName, const char* crashExtention)
{
    char path[260];
    char subdir[260];
    char fullpath[260];
    char logpath[260];
    int result;

    sub_77e644();
    sub_77e6a8();

    result = SHGetFolderPathAndSubDirA(0, 0x801a, 0, 0, subdir, path);
    if (result != 0) {
        sub_77e6a8();
        SHGetFolderPathAndSubDirA(0, 0x8023, 0, 0, subdir, path);
    }

    sub_77ddb8();

    sub_77e6ac();
}
