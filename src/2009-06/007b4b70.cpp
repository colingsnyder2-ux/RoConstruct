// from server: 100% by auto
extern "C" void __cdecl G1_func_007b4b70(void*);
struct S_func_007b4b70 {
    virtual ~S_func_007b4b70();
    void* m_p;
};
S_func_007b4b70::~S_func_007b4b70()
{
    if (m_p)
        G1_func_007b4b70(m_p);
}
