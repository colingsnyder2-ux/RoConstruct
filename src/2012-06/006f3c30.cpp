// from server: 64% by atomic.potato
struct S;

typedef int (__thiscall S::*Method)();

struct V
{
    int pad[1];
    Method method;
};

struct S
{
    S* owner;
    int pad[2];
    V* value;
    int f();
};

int S::f()
{
    S* p = owner;
    V* v = *(V**)((char*)p + 0x150);
    int result = (p->*v->method)();
    return *(int*)((char*)result + 0x148) == 3;
}
