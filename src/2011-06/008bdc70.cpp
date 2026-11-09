// from server: 100% by auto
extern "C" void __cdecl G1_func_008bdc70(void*);
struct S_func_008bdc70 {
    virtual ~S_func_008bdc70();
    void* m_p;
};
S_func_008bdc70::~S_func_008bdc70()
{
    if (m_p)
        G1_func_008bdc70(m_p);
}
