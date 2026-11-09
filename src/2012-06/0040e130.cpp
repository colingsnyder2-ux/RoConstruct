// from server: 100% by tajop
extern "C" void continuation();
extern "C" const int vt0, vt1, vt2, vt3;

struct S
{
    const int* a;
    const int* b;
    int c;
    int d;
    int e;
    int f2;
    const int* g;
    const int* h;

    void f();
};

int g_value;

void S::f()
{
    g_value = 0;
    a = &vt0;
    b = &vt1;
    g = &vt2;
    h = &vt3;
    continuation();
}
