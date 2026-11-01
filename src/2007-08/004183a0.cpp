// from server: 100% by colin
struct S {
    int f(int a, int b);
};

extern "C" char __cdecl sub_4879d0(int *p);
extern "C" void *__cdecl sub_62fef6(unsigned int size);

int S::f(int a, int b)
{
    int *self = (int *)this;
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    int tmp = a;
    if (!sub_4879d0(&tmp)) {
        self[2] = 0x4142e0;
        self[0] = 0x415d00;
        void *p = sub_62fef6(4);
        if (p) {
            *(int *)p = tmp;
        }
        self[1] = (int)p;
    }
    return (int)this;
}
