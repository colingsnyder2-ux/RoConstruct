// from server: 100% by auto
extern "C" void __cdecl G1_func_00842d80(void*);
struct S_func_00842d80 {
    virtual ~S_func_00842d80();
    void* m_p;
};
S_func_00842d80::~S_func_00842d80()
{
    if (m_p)
        G1_func_00842d80(m_p);
}
