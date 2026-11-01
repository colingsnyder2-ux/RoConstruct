// from server: 37% by atomic.potato
struct CXTShadowHook
{
    int value;
    int pad[13];
    int check();
};

extern "C" int __cdecl CXTShadowHookCheck(CXTShadowHook *);
extern "C" int __cdecl CXTAuxDataCreate();

int CXTShadowHook::check()
{
    if (CXTShadowHookCheck(this))
        return 0;
    CXTAuxDataCreate();
    return *(int *)((char *)this + 0x144) == 0;
}
