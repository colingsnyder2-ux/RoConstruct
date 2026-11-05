// from server: 100% by auto
extern "C" void __cdecl G1_func_0071c530(void*);
struct S_func_0071c530 {
    virtual ~S_func_0071c530();
    void* m_p;
};
S_func_0071c530::~S_func_0071c530()
{
    if (m_p)
        G1_func_0071c530(m_p);
}
