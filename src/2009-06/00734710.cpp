// from server: 100% by auto
extern "C" void __cdecl G1_func_00734710(void*);
struct S_func_00734710 {
    virtual ~S_func_00734710();
    void* m_p;
};
S_func_00734710::~S_func_00734710()
{
    if (m_p)
        G1_func_00734710(m_p);
}
