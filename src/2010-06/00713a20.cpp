// from server: 62% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" void* __cdecl sub_450be0();
extern "C" void __fastcall sub_711210(void*);

struct S {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* f(void* arg);
};

void* S::f(void* arg) {
    sub_711210(this);
    if ((unsigned char)arg & 1) {
        void* p = sub_450be0();
        EnterCriticalSection((void*)0x9ea374);
        this->field0 = *(void**)((char*)p + 0x18);
        *(void**)((char*)p + 0x18) = this;
        LeaveCriticalSection((void*)0x9ea370);
    }
    return this;
}
