// from server: 100% by auto
extern "C" void __cdecl G1_func_00729a50(void*);
struct S_func_00729a50 {
    virtual ~S_func_00729a50();
    void* m_p;
};
S_func_00729a50::~S_func_00729a50()
{
    if (m_p)
        G1_func_00729a50(m_p);
}
