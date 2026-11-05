// from server: 100% by auto
extern "C" void __cdecl G1_func_00864870(void*);
struct S_func_00864870 {
    virtual ~S_func_00864870();
    void* m_p;
};
S_func_00864870::~S_func_00864870()
{
    if (m_p)
        G1_func_00864870(m_p);
}
