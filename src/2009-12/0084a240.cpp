// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);

struct CXTPControlSelector {
    void* vtable;
    int field4;
    int field8;
    int fieldC;
    void* field10;
    void* Init();
};

void* CXTPControlSelector::Init()
{
    vtable = (void*)0x9fb9bc;
    fieldC = 0;
    field4 = 0;
    field8 = 0;
    field10 = LoadLibraryA((const char*)0x9fb9c0);
    if (field10 != 0) {
        fieldC = (int)GetProcAddress(field10, (const char*)0x9fb9a8);
        field4 = (int)GetProcAddress(field10, (const char*)0x9fb99c);
        field8 = (int)GetProcAddress(field10, (const char*)0x9fb98c);
    }
    return this;
}
