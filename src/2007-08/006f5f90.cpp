// from server: 100% by auto
extern "C" void __cdecl G1_func_006f5f90(void*);
struct S_func_006f5f90 {
    virtual ~S_func_006f5f90();
    void* m_p;
};
S_func_006f5f90::~S_func_006f5f90()
{
    if (m_p)
        G1_func_006f5f90(m_p);
}
