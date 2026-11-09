// from server: 100% by auto
extern "C" void __cdecl G1_func_007e0ec0(void*);
struct S_func_007e0ec0 {
    virtual ~S_func_007e0ec0();
    void* m_p;
};
S_func_007e0ec0::~S_func_007e0ec0()
{
    if (m_p)
        G1_func_007e0ec0(m_p);
}
