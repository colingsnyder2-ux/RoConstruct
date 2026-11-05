// from server: 100% by auto
extern "C" void __cdecl G1_func_0086c830(void*);
struct S_func_0086c830 {
    virtual ~S_func_0086c830();
    void* m_p;
};
S_func_0086c830::~S_func_0086c830()
{
    if (m_p)
        G1_func_0086c830(m_p);
}
