// from server: 72% by atomic.potato
struct T4_0066e730 {
    void f_0066e730();
};

extern "C" void* __cdecl sub_0066c7d0();
extern "C" void* __fastcall sub_0066de20(void*);
extern "C" void __stdcall sub_00598d90(void*, void*);

void T4_0066e730::f_0066e730()
{
    void* p = sub_0066c7d0();
    if (p) {
        void* q = sub_0066de20(p);
        if (q) {
            void** vt = *(void***)q;
            ((void (__fastcall*)(void*))vt[1])(q);
        }
        sub_00598d90(*(void**)((char*)this + 8), p);
    }
}
