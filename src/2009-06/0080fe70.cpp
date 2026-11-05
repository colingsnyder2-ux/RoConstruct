// from server: 100% by auto
extern "C" void __cdecl G1_func_0080fe70(void*);
struct S_func_0080fe70 {
    virtual ~S_func_0080fe70();
    void* m_p;
};
S_func_0080fe70::~S_func_0080fe70()
{
    if (m_p)
        G1_func_0080fe70(m_p);
}
