// from server: 100% by king_originala
typedef unsigned long DWORD;

extern "C" {
    extern DWORD (__stdcall *GetLastError)();
    extern DWORD (__stdcall *FormatMessageA)(
        DWORD, const void*, DWORD, DWORD, char*, DWORD, void*);
}

struct S {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    ~S();
    void check(bool, const char*);
};

struct Error {
    char storage[40];

    Error(const S&);
    Error(const Error&);
    ~Error();
};

extern S __cdecl format(const char*, ...);

void S::check(bool success, const char* message)
{
    if (!success) {
        char text[256];
        DWORD error = GetLastError();

        if (!FormatMessageA(0x1000, 0, error, 0x800,
                            text, 0x100, 0)) {
            throw Error(format("%s: %s, err=0x%X",
                               capacity >= 16 ? storage.pointer : storage.buffer,
                               message, error));
        }

        throw Error(format("%s: %s, %s",
                           capacity >= 16 ? storage.pointer : storage.buffer,
                           message, text));
    }
}
