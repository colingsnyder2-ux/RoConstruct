// from server: 100% by auto
extern "C" void __cdecl G1_func_0080df70(void*);
struct S_func_0080df70 {
    virtual ~S_func_0080df70();
    void* m_p;
};
S_func_0080df70::~S_func_0080df70()
{
    if (m_p)
        G1_func_0080df70(m_p);
}
