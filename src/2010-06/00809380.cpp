// from server: 100% by auto
extern "C" void __cdecl G1_func_00809380(void*);
struct S_func_00809380 {
    virtual ~S_func_00809380();
    void* m_p;
};
S_func_00809380::~S_func_00809380()
{
    if (m_p)
        G1_func_00809380(m_p);
}
