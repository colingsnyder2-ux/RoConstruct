// from server: 100% by auto
extern "C" void __cdecl G1_func_006b5e30(void*);
struct S_func_006b5e30 {
    virtual ~S_func_006b5e30();
    void* m_p;
};
S_func_006b5e30::~S_func_006b5e30()
{
    if (m_p)
        G1_func_006b5e30(m_p);
}
