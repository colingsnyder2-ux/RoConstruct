// from server: 100% by auto
extern "C" void __cdecl G1_func_00721190(void*);
struct S_func_00721190 {
    virtual ~S_func_00721190();
    void* m_p;
};
S_func_00721190::~S_func_00721190()
{
    if (m_p)
        G1_func_00721190(m_p);
}
