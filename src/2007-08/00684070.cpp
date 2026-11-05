// from server: 100% by auto
extern "C" void __cdecl G1_func_00684070(void*);
struct S_func_00684070 {
    virtual ~S_func_00684070();
    void* m_p;
};
S_func_00684070::~S_func_00684070()
{
    if (m_p)
        G1_func_00684070(m_p);
}
