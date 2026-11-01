// from server: 100% by auto
extern "C" void __cdecl G1_func_007c8870(void*);
struct S_func_007c8870 {
    virtual ~S_func_007c8870();
    void* m_p;
};
S_func_007c8870::~S_func_007c8870()
{
    if (m_p)
        G1_func_007c8870(m_p);
}
