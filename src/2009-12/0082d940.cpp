// from server: 100% by auto
extern "C" void __cdecl G1_func_0082d940(void*);
struct S_func_0082d940 {
    virtual ~S_func_0082d940();
    void* m_p;
};
S_func_0082d940::~S_func_0082d940()
{
    if (m_p)
        G1_func_0082d940(m_p);
}
