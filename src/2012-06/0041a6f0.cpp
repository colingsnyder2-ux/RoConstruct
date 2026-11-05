// from server: 100% by tajop
struct S {
    void sub_41a5e0();
    S* f(unsigned int flags);
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" void* __cdecl sub_401970();

S* S::f(unsigned int flags) {
    sub_41a5e0();
    if (flags & 1) {
        void* p = sub_401970();
        EnterCriticalSection(p);
        *(void**)this = *(void**)((char*)p + 0x18);
        *(void**)((char*)p + 0x18) = this;
        LeaveCriticalSection(p);
    }
    return this;
}
