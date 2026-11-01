// from server: 100% by auto
extern "C" void __cdecl G1_func_00855340(void*);
struct S_func_00855340 {
    virtual ~S_func_00855340();
    void* m_p;
};
S_func_00855340::~S_func_00855340()
{
    if (m_p)
        G1_func_00855340(m_p);
}
