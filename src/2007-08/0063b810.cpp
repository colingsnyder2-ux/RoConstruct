// from server: 100% by auto
extern "C" void __cdecl G1_func_0063b810(void*);
struct S_func_0063b810 {
    virtual ~S_func_0063b810();
    void* m_p;
};
S_func_0063b810::~S_func_0063b810()
{
    if (m_p)
        G1_func_0063b810(m_p);
}
