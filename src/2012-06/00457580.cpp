// from server: 0% by atomic.potato
extern "C" void __cdecl func_006a2780();
extern "C" void* __cdecl func_00828ca0(int, int);
extern "C" void* __cdecl func_004def50(void*, void*, void*, void*, void*, void*, void*, void*);

struct S {
    char pad0[4];
    void* field4;
    void* field8;
    void* fieldC;
    void construct(void* src);
};

void S::construct(void* src)
{
    char* b = (char*)src;
    int n = (int)((*(char**)(b + 8) - *(char**)(b + 4)) >> 3);
    this->field4 = 0;
    this->field8 = 0;
    this->fieldC = 0;
    if (n != 0) {
        if ((unsigned)n > 0x1fffffff) {
            func_006a2780();
        }
        void* mem = func_00828ca0(n, 0);
        this->field4 = mem;
        this->field8 = mem;
        this->fieldC = (char*)mem + n * 8;
        void* end = func_004def50(mem, *(void**)(b + 4), *(void**)(b + 8), mem, 0, 0, 0, 0);
        this->field8 = end;
    }
}
