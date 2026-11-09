// from server: 94% by atomic.potato
extern "C" void* __cdecl sub_472A70();
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct RBX_BlockBlockContact {
};

int __cdecl f(int* value) {
    void* lock = sub_472A70();
    EnterCriticalSection(lock);
    *value = *(int*)((char*)lock + 0x18);
    *(int*)((char*)lock + 0x18) = (int)value;
    LeaveCriticalSection(lock);
    return 0;
}
