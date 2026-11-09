// from server: 100% by auto
extern "C" void __cdecl G1_func_00841770(void*);
struct S_func_00841770 {
    virtual ~S_func_00841770();
    void* m_p;
};
S_func_00841770::~S_func_00841770()
{
    if (m_p)
        G1_func_00841770(m_p);
}
