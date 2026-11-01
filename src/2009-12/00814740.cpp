// from server: 100% by auto
extern "C" void __cdecl G1_func_00814740(void*);
struct S_func_00814740 {
    virtual ~S_func_00814740();
    void* m_p;
};
S_func_00814740::~S_func_00814740()
{
    if (m_p)
        G1_func_00814740(m_p);
}
