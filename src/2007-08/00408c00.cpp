// from server: 34% by colin
extern "C" void* __cdecl func_0062fef6(unsigned int size);
extern "C" void __cdecl func_00401990();
extern "C" int __cdecl func_00467d50();

struct S {
    char pad[0x20];
    void* field_20;
    char pad2[0x0c];
    int field_30;
    int f();
};

int S::f()
{
    S* p = 0;
    void* mem = func_0062fef6(0x44);
    if (mem != 0) {
        p = (S*)mem;
        func_00401990();
    }
    if (p != 0) {
        p->field_30 += 1;
        int r = func_00467d50();
        p->field_30 -= 1;
        if (r != 0) {
            void* v = p->field_20;
            int (*fn)(void*, int) = *(int (**)(void*, int))((char*)v + 0x14);
            fn((char*)p + 0x20, 1);
        }
    }
    return 0;
}
