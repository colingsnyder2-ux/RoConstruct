// from server: 100% by auto
extern "C" void __cdecl G1_func_006bc240(void*);
struct S_func_006bc240 {
    virtual ~S_func_006bc240();
    void* m_p;
};
S_func_006bc240::~S_func_006bc240()
{
    if (m_p)
        G1_func_006bc240(m_p);
}
