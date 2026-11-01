// from server: 100% by auto
extern "C" void __cdecl G1_func_006da2c0(void*);
struct S_func_006da2c0 {
    virtual ~S_func_006da2c0();
    void* m_p;
};
S_func_006da2c0::~S_func_006da2c0()
{
    if (m_p)
        G1_func_006da2c0(m_p);
}
