// from server: 100% by auto
extern "C" void __cdecl G1_func_0089ff40(void*);
struct S_func_0089ff40 {
    virtual ~S_func_0089ff40();
    void* m_p;
};
S_func_0089ff40::~S_func_0089ff40()
{
    if (m_p)
        G1_func_0089ff40(m_p);
}
