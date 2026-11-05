// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

struct CSourceStream {
    char pad0[4];
    void* field4;
    void* field8;
    char padC[8];
    int field14;
    char field18[0x18];
    char field30[0x18];
    CSourceStream* Init(int* p);
};

CSourceStream* CSourceStream::Init(int* p) {
    void* (__stdcall *pCreateEventA)(void*, int, int, const char*) = CreateEventA;
    void (__stdcall *pInitializeCriticalSection)(void*) = InitializeCriticalSection;

    field4 = pCreateEventA(0, 1, 0, 0);
    if (field4 == 0) {
        if (p != 0) {
            if (*p >= 0) {
                *p = 0x8007000e;
            }
        }
    }

    field8 = pCreateEventA(0, 0, 0, 0);
    if (field8 == 0) {
        if (p != 0) {
            if (*p >= 0) {
                *p = 0x8007000e;
            }
        }
    }

    pInitializeCriticalSection(&field18);
    pInitializeCriticalSection(&field30);

    field14 = 0;
    return this;
}
