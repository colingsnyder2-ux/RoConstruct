// from server: 100% by auto
extern "C" void __cdecl G1_func_008d6720(void*);
struct S_func_008d6720 {
    virtual ~S_func_008d6720();
    void* m_p;
};
S_func_008d6720::~S_func_008d6720()
{
    if (m_p)
        G1_func_008d6720(m_p);
}
