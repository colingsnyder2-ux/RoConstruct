// from server: 100% by auto
extern "C" void __cdecl G1_func_0087db30(void*);
struct S_func_0087db30 {
    virtual ~S_func_0087db30();
    void* m_p;
};
S_func_0087db30::~S_func_0087db30()
{
    if (m_p)
        G1_func_0087db30(m_p);
}
