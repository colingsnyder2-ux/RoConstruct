// from server: 100% by auto
extern "C" void __cdecl G1_func_0081eac0(void*);
struct S_func_0081eac0 {
    virtual ~S_func_0081eac0();
    void* m_p;
};
S_func_0081eac0::~S_func_0081eac0()
{
    if (m_p)
        G1_func_0081eac0(m_p);
}
