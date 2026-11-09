// from server: 100% by auto
extern "C" void __cdecl G1_func_0080f0a0(void*);
struct S_func_0080f0a0 {
    virtual ~S_func_0080f0a0();
    void* m_p;
};
S_func_0080f0a0::~S_func_0080f0a0()
{
    if (m_p)
        G1_func_0080f0a0(m_p);
}
