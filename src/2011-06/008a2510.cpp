// from server: 100% by auto
extern "C" void __cdecl G1_func_008a2510(void*);
struct S_func_008a2510 {
    virtual ~S_func_008a2510();
    void* m_p;
};
S_func_008a2510::~S_func_008a2510()
{
    if (m_p)
        G1_func_008a2510(m_p);
}
