// from server: 100% by auto
extern "C" void __cdecl G1_func_0089ff80(void*);
struct S_func_0089ff80 {
    virtual ~S_func_0089ff80();
    void* m_p;
};
S_func_0089ff80::~S_func_0089ff80()
{
    if (m_p)
        G1_func_0089ff80(m_p);
}
