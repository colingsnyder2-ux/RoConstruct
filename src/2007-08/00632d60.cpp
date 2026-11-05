// from server: 100% by auto
extern "C" void __cdecl G1_func_00632d60(void*);
struct S_func_00632d60 {
    virtual ~S_func_00632d60();
    void* m_p;
};
S_func_00632d60::~S_func_00632d60()
{
    if (m_p)
        G1_func_00632d60(m_p);
}
