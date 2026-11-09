// from server: 100% by colin
struct S {
    void m(int, int);
};

void func_0042b8c0(int* p, int a)
{
    int b = p[3];
    int c = p[2];
    void (*fn)(void*, int, int) = *(void (**)(void*, int, int))p;
    fn((void*)a, c, b);
}
