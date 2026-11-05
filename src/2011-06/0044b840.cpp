// from server: 70% by atomic.potato
typedef int (__thiscall *Method)(int*, int);

struct XItem
{
    int* v;
    int* f();
};

extern "C" void __cdecl sub_47d070(int);

int* XItem::f()
{
    int* p = this->v;
    ((Method)p[1])(p, 0);
    sub_47d070(0);
    return (int*)0x44b82a;
}
