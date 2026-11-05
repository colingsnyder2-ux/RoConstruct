// from server: 100% by colin
struct AnchorTool {
    char pad[0x1c];
    void* m_p;
    void f(void* arg);
};

extern "C" void* __cdecl sub_630d36(void*, void*, void*, void*, void*);

void AnchorTool::f(void* arg)
{
    void* p = m_p;
    if (p) {
        void* r = sub_630d36(p, 0, (void*)0x881f4c, (void*)0x898ee8, 0);
        if (r) {
            void** vt = *(void***)r;
            void (__thiscall *fn)(void*, void*, int) = (void (__thiscall *)(void*, void*, int))vt[4];
            fn(r, arg, 1);
        }
    }
}
