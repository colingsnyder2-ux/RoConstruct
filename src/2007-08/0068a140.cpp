// from server: 100% by auto
extern "C" void __cdecl G1_func_0068a140(void*);
struct S_func_0068a140 {
    virtual ~S_func_0068a140();
    void* m_p;
};
S_func_0068a140::~S_func_0068a140()
{
    if (m_p)
        G1_func_0068a140(m_p);
}
