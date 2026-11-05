// from server: 100% by auto
extern "C" void __cdecl G1_func_00819e80(void*);
struct S_func_00819e80 {
    virtual ~S_func_00819e80();
    void* m_p;
};
S_func_00819e80::~S_func_00819e80()
{
    if (m_p)
        G1_func_00819e80(m_p);
}
