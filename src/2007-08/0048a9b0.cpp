// from server: 46% by colin
struct S {
    void* field0;
    S(void* arg);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

S::S(void* arg)
{
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x79af88;
        *(void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
