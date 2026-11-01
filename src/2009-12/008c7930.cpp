// from server: 100% by auto
extern "C" void __cdecl G1_func_008c7930(void*);
struct S_func_008c7930 {
    virtual ~S_func_008c7930();
    void* m_p;
};
S_func_008c7930::~S_func_008c7930()
{
    if (m_p)
        G1_func_008c7930(m_p);
}
