// from server: 100% by auto
extern "C" void __cdecl G1_func_0086c870(void*);
struct S_func_0086c870 {
    virtual ~S_func_0086c870();
    void* m_p;
};
S_func_0086c870::~S_func_0086c870()
{
    if (m_p)
        G1_func_0086c870(m_p);
}
