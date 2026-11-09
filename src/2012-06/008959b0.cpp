// from server: 91% by atomic.potato
extern "C" void* __cdecl sub_472ad0();
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct RBX_BlockBlockContact {
};

void __cdecl f(int* value) {
    void* p = sub_472ad0();
    EnterCriticalSection(p);
    *value = *(int*)((char*)p + 0x18);
    *(int*)((char*)p + 0x18) = (int)value;
    LeaveCriticalSection(p);
}
