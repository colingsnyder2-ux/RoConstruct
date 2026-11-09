// from server: 20% by atomic.potato
extern "C" void __stdcall fn_00b2263c();
extern "C" void __cdecl fn_00675af0();
extern "C" void __cdecl fn_00685090();

struct S_0055f950 {
    char pad0[0x80];
    char pad80[0x18];
    char pad98[4];
    void destroy();
};

void S_0055f950::destroy()
{
    fn_00b2263c();
    fn_00675af0();
    *(void**)this = (void*)0xb73eac;
    *(void**)((char*)this + 4) = (void*)0xb73ea0;
    *(void**)((char*)this + 0x18) = (void*)0xb73e94;
    *(void**)((char*)this + 0x1c) = (void*)0xb73e88;
    fn_00685090();
}
