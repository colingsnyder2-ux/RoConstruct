// from server: 49% by colin
struct S {
    void* field0;
    void* f(void* arg1, void* arg2);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

void* S::f(void* arg1, void* arg2) {
    void* p;
    field0 = 0;
    p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x7871B8;
        *(void**)((char*)p + 0xC) = arg1;
    } else {
        p = 0;
    }
    field0 = p;
    return this;
}
