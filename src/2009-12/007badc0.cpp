// from server: 62% by atomic.potato
struct S
{
    char padding[0x24];
    int *field;
    int f();
};

struct T
{
    char padding[0x78];
    int a;
    int b;
};

extern "C" int __stdcall sub_6cb0e0(int *p);
extern "C" S * __stdcall sub_701650();

bool __stdcall func_007badc0(T *self)
{
    S *s = sub_701650();
    int v[2];
    v[0] = s->field[0x78 / 4];
    v[1] = s->field[0x7c / 4];
    return sub_6cb0e0(v) == 0;
}
