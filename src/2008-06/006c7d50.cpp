// from server: 100% by auto
extern "C" void __cdecl G1_func_006c7d50(void*);
struct S_func_006c7d50 {
    virtual ~S_func_006c7d50();
    void* m_p;
};
S_func_006c7d50::~S_func_006c7d50()
{
    if (m_p)
        G1_func_006c7d50(m_p);
}
