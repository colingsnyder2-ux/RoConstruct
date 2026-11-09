// from server: 51% by colin
struct LogManager {
    void* log;
    unsigned long threadID;
    void* name[4];
    static bool logsEnabled;
    static void* mainLogManager;
    void* getLog();
    static void* getMainLogManager();
    static int ReportCOMError(const void* clsid, const char* lpszDesc, int hRes);
    static int ReportCOMError(const void* clsid, int hRes);
    static int ReportCOMError(const void* clsid, const wchar_t* lpszDesc, int hRes);
    static void ReportException(void* exp);
    static void ReportLastError(const char* message);
    static void ReportEvent(unsigned short type, const char* message);
    static void ReportEvent(unsigned short type, const char* message, const char* fileName, int lineNumber);
    static void ReportEvent(unsigned short type, int hr, const char* fileName, int lineNumber);
    void* GetLogPath() const;
    virtual ~LogManager();
    virtual void* getLogFileName();
protected:
    LogManager(const char* name);
};

struct MainLogManager : public LogManager {
    void* crashReporter;
    void* fastLogChannels[4];
    static void* fastLogChannelsLock;
    const char* crashExtention;
    const char* crashEventExtention;
    MainLogManager(const char* productName, const char* crashExtention, const char* crashEventExtention);
    ~MainLogManager();
    void* provideLog();
};

extern "C" {
    int __stdcall GetCurrentThreadId();
    int __stdcall GetLastError();
    int __stdcall FormatMessageA(unsigned long dwFlags, const void* lpSource, unsigned long dwMessageId, unsigned long dwLanguageId, char* lpBuffer, unsigned long nSize, void* Arguments);
    void* __stdcall LocalFree(void* hMem);
    int __stdcall MultiByteToWideChar(unsigned int CodePage, unsigned long dwFlags, const char* lpMultiByteStr, int cbMultiByte, wchar_t* lpWideCharStr, int cchWideChar);
    int __stdcall WideCharToMultiByte(unsigned int CodePage, unsigned long dwFlags, const wchar_t* lpWideCharStr, int cchWideChar, char* lpMultiByteStr, int cbMultiByte, const char* lpDefaultChar, int* lpUsedDefaultChar);
}

void __stdcall sub_6304C6(void* p);
void __stdcall sub_6304D8(void* p, int a, int b, int c);
void __stdcall sub_630A1E();
void __stdcall sub_427C40(void* a, void* b);

void* MainLogManager::provideLog()
{
    return 0;
}

MainLogManager::MainLogManager(const char* productName, const char* crashExtention, const char* crashEventExtention)
    : LogManager(productName)
{
    char buffer[1024];
    void* hMem;
    int result;
    int lastError;

    sub_6304C6(this);
    *(void**)this = (void*)0x78a024;
    *(void**)((char*)this + 0x10) = 0;
    *(const char**)((char*)this + 0x14) = productName;
    sub_6304D8((char*)this + 0x18, 0, 0x400, (int)buffer);
    sub_6304C6((char*)this + 0x0c);
    hMem = 0;
    lastError = GetLastError();
    result = FormatMessageA(0x1000, 0, lastError, 0, buffer, 0x400, 0);
    if (result == 0) {
        buffer[0] = 0;
    }
    sub_427C40((void*)0x78a060, buffer);
    sub_6304C6((char*)this + 0x0c);
}
