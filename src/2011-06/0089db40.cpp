// from server: 100% by auto
extern "C" void __cdecl G1_func_0089db40(void*);
struct S_func_0089db40 {
    virtual ~S_func_0089db40();
    void* m_p;
};
S_func_0089db40::~S_func_0089db40()
{
    if (m_p)
        G1_func_0089db40(m_p);
}
