// from server: 100% by auto
extern "C" void __cdecl G1_func_007cf270(void*);
struct S_func_007cf270 {
    virtual ~S_func_007cf270();
    void* m_p;
};
S_func_007cf270::~S_func_007cf270()
{
    if (m_p)
        G1_func_007cf270(m_p);
}
