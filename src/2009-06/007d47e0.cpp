// from server: 100% by auto
extern "C" void __cdecl G1_func_007d47e0(void*);
struct S_func_007d47e0 {
    virtual ~S_func_007d47e0();
    void* m_p;
};
S_func_007d47e0::~S_func_007d47e0()
{
    if (m_p)
        G1_func_007d47e0(m_p);
}
