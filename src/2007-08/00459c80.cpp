// from server: 100% by colin
struct S {
    void m(int a, int b);
    int pad0;
    int field4;
    int field8;
};

extern "C" char __cdecl func_004879d0(int* p);
extern "C" void* __cdecl func_0062fef6(unsigned int size);

void S::m(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!func_004879d0(local)) {
        field8 = 0x589420;
        *(int*)this = 0x459660;
        void* p = func_0062fef6(8);
        if (p) {
            *(int*)p = local[0];
            *(int*)((char*)p + 4) = local[1];
        }
        field4 = (int)p;
    }
}
