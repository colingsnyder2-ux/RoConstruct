// from server: 100% by auto
extern "C" void __cdecl G1_func_0083f820(void*);
struct S_func_0083f820 {
    virtual ~S_func_0083f820();
    void* m_p;
};
S_func_0083f820::~S_func_0083f820()
{
    if (m_p)
        G1_func_0083f820(m_p);
}
