// from server: 100% by auto
extern "C" void __cdecl G1_func_007c7ee0(void*);
struct S_func_007c7ee0 {
    virtual ~S_func_007c7ee0();
    void* m_p;
};
S_func_007c7ee0::~S_func_007c7ee0()
{
    if (m_p)
        G1_func_007c7ee0(m_p);
}
