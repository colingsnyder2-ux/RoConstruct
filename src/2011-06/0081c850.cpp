// from server: 100% by auto
extern "C" void __cdecl G1_func_0081c850(void*);
struct S_func_0081c850 {
    virtual ~S_func_0081c850();
    void* m_p;
};
S_func_0081c850::~S_func_0081c850()
{
    if (m_p)
        G1_func_0081c850(m_p);
}
