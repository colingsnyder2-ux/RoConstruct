// from server: 71% by atomic.potato
struct S {
    void f(int);
};

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void* __cdecl sub_401910();
extern "C" void __cdecl sub_4150f0();

void S::f(int a) {
    sub_4150f0();
    if (a & 1) {
        void* p = sub_401910();
        EnterCriticalSection((void*)0x9ea374);
        *(int*)this = *(int*)((char*)p + 0x18);
        *(int*)((char*)p + 0x18) = (int)this;
        LeaveCriticalSection((void*)0x9ea370);
    }
}
