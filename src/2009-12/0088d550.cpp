// from server: 100% by auto
extern "C" void __cdecl G1_func_0088d550(void*);
struct S_func_0088d550 {
    virtual ~S_func_0088d550();
    void* m_p;
};
S_func_0088d550::~S_func_0088d550()
{
    if (m_p)
        G1_func_0088d550(m_p);
}
