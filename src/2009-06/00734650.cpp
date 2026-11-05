// from server: 100% by auto
extern "C" void __cdecl G1_func_00734650(void*);
struct S_func_00734650 {
    virtual ~S_func_00734650();
    void* m_p;
};
S_func_00734650::~S_func_00734650()
{
    if (m_p)
        G1_func_00734650(m_p);
}
