// from server: 100% by atomic.potato
struct P_func_0060cbf0
{
    void g();
};

struct S_func_0060cbf0
{
    P_func_0060cbf0* m_p;
    void f();
};

struct EngineStatsCommand
{
    void f(int);
    char pad0[12];
    struct A
    {
        char pad0[516];
        struct B
        {
            char pad0[740];
            struct C
            {
                char pad0[132];
                S_func_0060cbf0* m_p;
            }* m_p;
        }* m_p;
    }* m_p;
};

void EngineStatsCommand::f(int)
{
    m_p->m_p->m_p->m_p->f();
}
