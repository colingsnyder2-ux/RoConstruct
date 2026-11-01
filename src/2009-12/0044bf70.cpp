// from server: 55% by atomic.potato
struct S {
    int f();
    int pad58;
};

int S::f()
{
    int *a = *(int **)((char *)this + 0x58);
    int *b = *(int **)((char *)a + 0x2c);
    int (**v)(int *, int, int) = (int (**)(int *, int, int))(*(int **)b + 0x88);
    return (*v)(b, 0, 1);
}
