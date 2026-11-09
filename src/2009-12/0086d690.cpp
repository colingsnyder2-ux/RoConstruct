// from server: 100% by auto
extern "C" void __cdecl G1_func_0086d690(void*);
struct S_func_0086d690 {
    virtual ~S_func_0086d690();
    void* m_p;
};
S_func_0086d690::~S_func_0086d690()
{
    if (m_p)
        G1_func_0086d690(m_p);
}
