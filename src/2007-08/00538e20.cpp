// from server: 100% by colin
extern "C" char __cdecl func_004879d0(int*);
extern "C" int __cdecl func_0062fef6(int);

struct S {
    void f(int, int);
};

void S::f(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (func_004879d0(local) == 0) {
        *(int*)((char*)this + 8) = 0x537d20;
        *(int*)this = 0x537d40;
        int* p = (int*)func_0062fef6(8);
        if (p != 0) {
            p[0] = local[0];
            p[1] = local[1];
        }
        *(int*)((char*)this + 4) = (int)p;
    }
}
