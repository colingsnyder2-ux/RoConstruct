// from server: 100% by auto
extern "C" void __cdecl G1_func_006d7b30(void*);
struct S_func_006d7b30 {
    virtual ~S_func_006d7b30();
    void* m_p;
};
S_func_006d7b30::~S_func_006d7b30()
{
    if (m_p)
        G1_func_006d7b30(m_p);
}
