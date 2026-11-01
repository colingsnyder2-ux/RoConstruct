// from server: 100% by auto
extern "C" void __cdecl G1_func_0088d510(void*);
struct S_func_0088d510 {
    virtual ~S_func_0088d510();
    void* m_p;
};
S_func_0088d510::~S_func_0088d510()
{
    if (m_p)
        G1_func_0088d510(m_p);
}
