// from server: 36% by colin
extern "C" {
    void* __cdecl __iob_func();
    char* __cdecl _tempnam(const char*, const char*);
    void* __cdecl fopen(const char*, const char*);
    int __cdecl fprintf(void*, const char*, ...);
    int __cdecl rand();
    int __cdecl sprintf(char*, const char*, ...);
    void* __cdecl tmpfile();
    char* __cdecl tmpnam(char*);
}

extern "C" void* __stdcall GetTempPathA(unsigned long, char*);
extern "C" void* __stdcall GetTempFileNameA(const char*, const char*, unsigned int, char*);
extern "C" void* __stdcall GetCurrentProcess();
extern "C" void* __stdcall GetModuleFileNameA(void*, char*, unsigned long);
extern "C" void* __stdcall GetEnvironmentStrings();
extern "C" void* __stdcall FreeEnvironmentStringsA(void*);
extern "C" void* __stdcall GetLastError();

struct S {
    void* f();
};

void* S::f() {
    char buf[256];
    char buf2[16];
    void* result;
    void* h;
    char* p;
    char* q;
    void* fp;
    void* env;
    void* proc;
    char* s;

    result = tmpfile();
    if (result != 0) {
        return result;
    }

    p = _tempnam("c:/temp", "L$ h");
    result = fopen(p, "w+b");
    if (result != 0) {
        return result;
    }

    p = _tempnam("c:/temp/", "L$ h");
    result = fopen(p, "w+b");
    if (result != 0) {
        return result;
    }

    p = _tempnam("c:/tmp", "L$ h");
    result = fopen(p, "w+b");
    if (result != 0) {
        return result;
    }

    p = _tempnam("c:/tmp/", "L$ h");
    result = fopen(p, "w+b");
    if (result != 0) {
        return result;
    }

    proc = GetCurrentProcess();
    GetModuleFileNameA(proc, buf, 256);
    sprintf(buf2, "%s/tmp%d", buf, rand());
    result = fopen(buf2, "w+b");
    if (result != 0) {
        return result;
    }

    proc = GetCurrentProcess();
    GetModuleFileNameA(proc, buf, 256);
    sprintf(buf2, "%s/tmp%d", buf, rand());
    result = fopen(buf2, "w+b");
    if (result != 0) {
        return result;
    }

    proc = GetCurrentProcess();
    GetModuleFileNameA(proc, buf, 256);
    sprintf(buf2, "%s/tmp%d", buf, rand());
    result = fopen(buf2, "w+b");
    if (result != 0) {
        return result;
    }

    proc = GetCurrentProcess();
    GetModuleFileNameA(proc, buf, 256);
    sprintf(buf2, "%s/tmp%d", buf, rand());
    result = fopen(buf2, "w+b");
    if (result != 0) {
        return result;
    }

    fprintf(__iob_func(), "Unable to create a temporary file; robustTmpfile returning NULL");
    return 0;
}
