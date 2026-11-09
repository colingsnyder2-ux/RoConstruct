// from server: 100% by colin
struct CXTShadowHook {
    void* vtable;
    void* field4;
    void sub_720770(int);
    void destroy();
};

extern "C" int (__stdcall *IsWindow)(void*);

void CXTShadowHook::destroy()
{
    void* p = field4;
    vtable = (void*)0x7e22ac;
    if (p != 0) {
        if (IsWindow(p) != 0) {
            sub_720770(0);
        }
    }
}
