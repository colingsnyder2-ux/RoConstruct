// from server: 100% by auto
extern "C" void __cdecl G1_func_008f8330(void*);
struct S_func_008f8330 {
    virtual ~S_func_008f8330();
    void* m_p;
};
S_func_008f8330::~S_func_008f8330()
{
    if (m_p)
        G1_func_008f8330(m_p);
}
