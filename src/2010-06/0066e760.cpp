// from server: 82% by atomic.potato
struct T4_0066e760 {
    void* f_0066c7d0();
    void* f_00669db0();
};

extern "C" void* __stdcall sub_0066c7d0();
extern "C" void* sub_00669db0(void*);
extern "C" void __stdcall sub_00598d90(void*, void*);

void __stdcall sub_0066e760(void* arg)
{
    void* p = sub_0066c7d0();
    if (p) {
        void* q = sub_00669db0(p);
        if (q) {
            void** vt = *(void***)q;
            ((void (__thiscall *)(void*))vt[1])(q);
        }
        sub_00598d90(arg, p);
    }
}
