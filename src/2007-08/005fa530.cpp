// from server: 100% by colin
struct FactoryProduct {
};

void __cdecl invoke(void* arg1, void* arg2)
{
    char* p = (char*)arg1;
    void* vtable = *(void**)p;
    int offset = *(int*)(p + 8);
    char* base = *(char**)(p + 0x10);
    int delta = *(int*)(base + 0xec);
    int index = *(int*)(delta + offset);
    int total = index + *(int*)(p + 4);
    char* self = base + 0xec + total;
    ((void (__thiscall*)(void*, void*))vtable)(self, arg2);
}
