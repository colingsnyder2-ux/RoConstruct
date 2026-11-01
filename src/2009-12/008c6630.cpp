// from server: 100% by auto
extern "C" void __cdecl G1_func_008c6630(void*);
struct S_func_008c6630 {
    virtual ~S_func_008c6630();
    void* m_p;
};
S_func_008c6630::~S_func_008c6630()
{
    if (m_p)
        G1_func_008c6630(m_p);
}
