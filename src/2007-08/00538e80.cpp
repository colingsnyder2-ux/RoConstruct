// from server: 100% by colin
struct S {
    void f(int a, int b);
};

extern "C" char __cdecl sub_004879d0(int* p);
extern "C" void* __cdecl sub_0062fef6(unsigned int size);

void S::f(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!sub_004879d0(local)) {
        *(int*)((char*)this + 8) = 0x537da0;
        *(int*)this = 0x537dc0;
        void* p = sub_0062fef6(8);
        if (p) {
            *(int*)p = local[0];
            *(int*)((char*)p + 4) = local[1];
        }
        *(int*)((char*)this + 4) = (int)p;
    }
}
