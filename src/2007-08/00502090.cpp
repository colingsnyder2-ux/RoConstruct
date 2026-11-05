// from server: 35% by colin
// roc 2007-08 00502090  unit: G3D::Log  size: 670 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00502090

extern "C" {
    __declspec(dllimport) unsigned long __stdcall GetLastError(void);
    __declspec(dllimport) unsigned long __stdcall FormatMessageA(
        unsigned long dwFlags, const void* lpSource, unsigned long dwMessageId,
        unsigned long dwLanguageId, char* lpBuffer, unsigned long nSize, void* Arguments);
    __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(
        void* hModule, char* lpFilename, unsigned long nSize);
    __declspec(dllimport) void* __stdcall LocalFree(void* hMem);
    __declspec(dllimport) char* __cdecl strrchr(const char* s, int c);
}

namespace std {
    class string {
    public:
        string();
        string(const char*);
        string(const string&);
        ~string();
        string& operator=(const string&);
    };
    string operator+(const string&, const string&);
}

struct Log {
    void writeEntry(int severity, const char* message);
};

extern "C" void __cdecl sub_5017C0();
extern "C" void __cdecl sub_630A1E();

void Log::writeEntry(int severity, const char* message)
{
    char buffer[0x104];
    std::string name;
    std::string msg;
    std::string tmp;
    std::string result;
    unsigned long err;
    char* p;
    char fullPath[0x104];

    name = std::string("CDataModelPropGrid");

    err = GetLastError();
    if (err != 0) {
        FormatMessageA(0x1300, 0, err, 0, buffer, 0x104, 0);
        p = strrchr(buffer, '\\');
        if (p != 0) {
            p = p + 1;
        } else {
            p = buffer;
        }
        msg = std::string(p);
        tmp = std::string("Last Error (0x%08X): %s");
        result = tmp + msg;
        name = result;
    }

    GetModuleFileNameA(0, fullPath, 0x104);
    p = strrchr(fullPath, '\\');
    if (p != 0) {
        p = p + 1;
    } else {
        p = fullPath;
    }
    msg = std::string(p);
    tmp = std::string("Expression: %s%s%s:%d%s%s%s");
    result = tmp + msg;
    name = result;
}
