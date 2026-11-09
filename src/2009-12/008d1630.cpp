// from server: 100% by auto
extern "C" void __cdecl G1_func_008d1630(void*);
struct S_func_008d1630 {
    virtual ~S_func_008d1630();
    void* m_p;
};
S_func_008d1630::~S_func_008d1630()
{
    if (m_p)
        G1_func_008d1630(m_p);
}
