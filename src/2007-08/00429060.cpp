// from server: 33% by colin
typedef unsigned int DWORD;
typedef int HRESULT;
typedef const char* LPCSTR;
typedef const char* LPCTSTR;
typedef unsigned short WORD;

extern "C" {
    DWORD __stdcall GetCurrentThreadId();
    int __stdcall lstrlenA(LPCSTR lpString);
}

struct CLSID;

struct RBX_Log;

struct LogManager {
    RBX_Log* log;
    static bool logsEnabled;
    const DWORD threadID;
    void* name_data;
    unsigned int name_size;
    unsigned int name_capacity;
    static void* mainLogManager;
    RBX_Log* getLog();
    virtual ~LogManager();
    virtual void getLogFileName();
    LogManager(const char* name);
};

struct MainLogManager : public LogManager {
    void* crashReporter;
    void* fastLogChannels;
    const char* crashExtention;
    const char* crashEventExtention;
    MainLogManager(LPCTSTR productName, const char* crashExtention, const char* crashEventExtention);
    ~MainLogManager();
    RBX_Log* provideLog();
};

extern "C" void* __stdcall sub_8BAB64();
extern "C" int __stdcall sub_401770(void* a, int b, int c);
extern "C" void* __stdcall sub_4017C0(void* a, int b, const char* c, void* d);
extern "C" int __stdcall sub_402AC0(int a);
extern "C" void* __stdcall sub_4035E0(void* a, int b);
extern "C" int __stdcall sub_401150(void* a);
extern "C" int __stdcall sub_630C50(int a, int b, int c, int d);
extern "C" void* __stdcall sub_630BB0(int a);
extern "C" int __stdcall sub_630A1E();
extern "C" int __stdcall sub_428A30(void* a, void* b, const char* c, const char* d, void* e, void* f, void* g);

MainLogManager::MainLogManager(LPCTSTR productName, const char* crashExtention, const char* crashEventExtention)
    : LogManager(productName)
{
    this->crashExtention = crashExtention;
    this->crashEventExtention = crashEventExtention;
    this->crashReporter = 0;
    this->fastLogChannels = 0;

    if (productName == 0) {
        return;
    }

    void* guid = sub_8BAB64();

    int len = lstrlenA(productName) + 1;
    int size = sub_630C50(len, 0, 2, 0);
    if (size < 0) {
        sub_401150(&this->fastLogChannels);
        return;
    }

    void* buf;
    if (size <= 0x400 && sub_402AC0(size)) {
        buf = sub_630BB0(size);
    } else {
        buf = sub_4035E0(&this->fastLogChannels, size);
    }

    void* result = sub_4017C0(buf, size, productName, guid);
    if (result == 0) {
        sub_401150(&this->fastLogChannels);
        return;
    }

    if (crashExtention != 0) {
        int extLen = lstrlenA(crashExtention) + 1;
        int extSize = extLen;
        if (sub_401770(&extSize, extLen, 2) < 0) {
            sub_401150(&this->fastLogChannels);
            return;
        }
        void* extBuf;
        if (extSize <= 0x400 && sub_402AC0(extSize)) {
            extBuf = sub_630BB0(extSize);
        } else {
            extBuf = sub_4035E0(&this->fastLogChannels, extSize);
        }
        void* extResult = sub_4017C0(extBuf, extSize, crashExtention, guid);
        if (extResult == 0) {
            sub_401150(&this->fastLogChannels);
            return;
        }
    }

    sub_428A30(this, result, crashExtention, crashEventExtention, 0, 0, 0);
    sub_401150(&this->fastLogChannels);
}
