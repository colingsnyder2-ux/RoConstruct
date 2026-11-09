// from server: 100% by auto
extern "C" void __cdecl G1_func_00882090(void*);
struct S_func_00882090 {
    virtual ~S_func_00882090();
    void* m_p;
};
S_func_00882090::~S_func_00882090()
{
    if (m_p)
        G1_func_00882090(m_p);
}
