// from server: 100% by auto
extern "C" void __cdecl G1_func_006a2e40(void*);
struct S_func_006a2e40 {
    virtual ~S_func_006a2e40();
    void* m_p;
};
S_func_006a2e40::~S_func_006a2e40()
{
    if (m_p)
        G1_func_006a2e40(m_p);
}
