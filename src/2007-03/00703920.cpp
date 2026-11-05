// from server: 100% by tester
struct CXTShadowHook {
    void Method(int);
};

void CXTShadowHook::Method(int arg)
{
    int value = arg;
    if (value != 0) {
        value = *(int*)(value + 0x20);
    }
    void** vtbl = *(void***)this;
    typedef void (__thiscall *Fn)(CXTShadowHook*, int);
    Fn fn = (Fn)vtbl[7];
    fn(this, value);
}
