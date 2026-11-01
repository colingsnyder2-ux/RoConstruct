// from server: 100% by auto
extern "C" void __cdecl G1_func_0077a570(void*);
struct S_func_0077a570 {
    virtual ~S_func_0077a570();
    void* m_p;
};
S_func_0077a570::~S_func_0077a570()
{
    if (m_p)
        G1_func_0077a570(m_p);
}
