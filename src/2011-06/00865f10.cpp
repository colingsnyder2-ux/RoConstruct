// from server: 100% by auto
extern "C" void __cdecl G1_func_00865f10(void*);
struct S_func_00865f10 {
    virtual ~S_func_00865f10();
    void* m_p;
};
S_func_00865f10::~S_func_00865f10()
{
    if (m_p)
        G1_func_00865f10(m_p);
}
