// from server: 100% by auto
extern "C" void __cdecl G1_func_0082a340(void*);
struct S_func_0082a340 {
    virtual ~S_func_0082a340();
    void* m_p;
};
S_func_0082a340::~S_func_0082a340()
{
    if (m_p)
        G1_func_0082a340(m_p);
}
