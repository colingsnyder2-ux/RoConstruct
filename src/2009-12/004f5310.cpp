// from server: 76% by atomic.potato
struct S
{
    char pad[0x130];
    int a;
    int b;
    void f(int* p);
};

extern "C" int* __cdecl func_7e5d40(int*);

void S::f(int* p)
{
    int* q = func_7e5d40((int*)&p);
    a = q[0];
    b = q[1];
}
