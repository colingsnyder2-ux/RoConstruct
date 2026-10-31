// from server: 86% by EspClaude
// from server: 100% by atomic.potato
// roc 2008-06 0057dc40  unit: RBX::EngineStatsCommand  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057dc40
//
// 0057dc40  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0057dc43  8b8804020000         mov ecx, dword ptr [eax + 0x204]
// 0057dc49  8b91e4020000         mov edx, dword ptr [ecx + 0x2e4]
// 0057dc4f  8b8a84000000         mov ecx, dword ptr [edx + 0x84]
// 0057dc55  e896ef0800           call 0x60cbf0
// 0057dc5a  c20400               ret 4

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
