// from server: 100% by auto
extern "C" void __cdecl G1_func_0074fbd0(void*);
struct S_func_0074fbd0 {
    virtual ~S_func_0074fbd0();
    void* m_p;
};
S_func_0074fbd0::~S_func_0074fbd0()
{
    if (m_p)
        G1_func_0074fbd0(m_p);
}
