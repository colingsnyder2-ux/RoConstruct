// from server: 100% by auto
extern "C" void __cdecl G1_func_007ead80(void*);
struct S_func_007ead80 {
    virtual ~S_func_007ead80();
    void* m_p;
};
S_func_007ead80::~S_func_007ead80()
{
    if (m_p)
        G1_func_007ead80(m_p);
}
