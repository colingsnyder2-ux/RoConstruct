// from server: 100% by colin
struct S {
    void* field0;
    void* field4;
    void* field8;
    void construct(void* a, void* b);
};

extern "C" char __cdecl func_004879d0(void* a);
extern "C" void* __cdecl func_0062fef6(unsigned int size);

void S::construct(void* a, void* b)
{
    void* local[2];
    local[0] = a;
    local[1] = b;
    if (!func_004879d0(local)) {
        field8 = (void*)0x459760;
        field0 = (void*)0x459600;
        void* p = func_0062fef6(8);
        if (p) {
            *(void**)p = local[0];
            *(void**)((char*)p + 4) = local[1];
        }
        field4 = p;
    }
}
