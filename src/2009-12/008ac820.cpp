// from server: 100% by auto
extern "C" void __cdecl G1_func_008ac820(void*);
struct S_func_008ac820 {
    virtual ~S_func_008ac820();
    void* m_p;
};
S_func_008ac820::~S_func_008ac820()
{
    if (m_p)
        G1_func_008ac820(m_p);
}
