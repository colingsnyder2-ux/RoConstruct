// from server: 29% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

struct CTa {
    void* field_0;
    CTa* construct();
};

CTa* CTa::construct()
{
    InitializeCriticalSection(&field_0);
    return this;
}
