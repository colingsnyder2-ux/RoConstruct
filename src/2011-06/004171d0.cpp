// from server: 100% by atomic.potato
struct S {
    S* f(int);
    char pad[0x18];
};

extern "C" void (__stdcall *EnterCriticalSection)(void*);
extern "C" void (__stdcall *LeaveCriticalSection)(void*);
extern "C" void* __stdcall sub_401c30();
extern "C" void sub_4170c0();

S* S::f(int a) {
    sub_4170c0();
    if (a & 1) {
        void* p = sub_401c30();
        EnterCriticalSection(p);
        *(void**)this = *(void**)((char*)p + 0x18);
        *(void**)((char*)p + 0x18) = this;
        LeaveCriticalSection(p);
    }
    return this;
}
