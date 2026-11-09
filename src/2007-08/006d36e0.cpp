// from server: 100% by auto
extern "C" void __cdecl G1_func_006d36e0(void*);
struct S_func_006d36e0 {
    virtual ~S_func_006d36e0();
    void* m_p;
};
S_func_006d36e0::~S_func_006d36e0()
{
    if (m_p)
        G1_func_006d36e0(m_p);
}
