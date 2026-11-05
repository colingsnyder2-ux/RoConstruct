// from server: 66% by atomic.potato
extern "C" void* __cdecl sub_0098211a(unsigned int size);

struct S_func_004f4e50 {
    void f(int a, int b, int c, float d);
};

struct S_func_004f6480 {
    void* __cdecl f(int a, int b, int c, float d);
};

void* S_func_004f6480::f(int a, int b, int c, float d)
{
    S_func_004f4e50* p = (S_func_004f4e50*)sub_0098211a(0x20);
    if (p == 0) {
        return 0;
    }
    p->f(a, b, c, d);
    return p;
}
