// from server: 28% by atomic.potato
extern "C" int __cdecl sub_5A5F20();
extern "C" void __cdecl sub_5C9910(void*, int, int, int, int, int, int);
extern "C" void __cdecl sub_7A799A(int);

struct P8PartInstance_GetSetImpl {
    void f(int a, int b, int c, int d, int e, int f);
};

void P8PartInstance_GetSetImpl::f(int a, int b, int c, int d, int e, int f) {
    int* self = (int*)this;
    int v = sub_5A5F20();
    sub_5C9910(this, v, a, b, c, d, e);
    self[0] = (int)0xa365e0;
    self[7] = f;
    sub_7A799A(0);
}
