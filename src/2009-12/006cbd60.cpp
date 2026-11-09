// from server: 75% by atomic.potato
struct P_func_006edb90
{
    void g();
};

struct S_func_006edb90
{
    char pad[244];
    P_func_006edb90* m_p;
    int f();
};

int S_func_006edb90::f()
{
    m_p->g();
    return 0;
}

struct PartInstance
{
    int f();
};

int PartInstance::f()
{
    return ((S_func_006edb90*)*(int*)((char*)this + 0x168))->f() + 0x30;
}
