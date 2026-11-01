// from server: 100% by auto
extern "C" void __cdecl G1_func_00663eb0(void*);
struct S_func_00663eb0 {
    virtual ~S_func_00663eb0();
    void* m_p;
};
S_func_00663eb0::~S_func_00663eb0()
{
    if (m_p)
        G1_func_00663eb0(m_p);
}
