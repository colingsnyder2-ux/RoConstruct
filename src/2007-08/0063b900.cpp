// from server: 100% by auto
extern "C" void __cdecl G1_func_0063b900(void*);
struct S_func_0063b900 {
    virtual ~S_func_0063b900();
    void* m_p;
};
S_func_0063b900::~S_func_0063b900()
{
    if (m_p)
        G1_func_0063b900(m_p);
}
