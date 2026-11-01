// from server: 100% by auto
extern "C" void __cdecl G1_func_00759450(void*);
struct S_func_00759450 {
    virtual ~S_func_00759450();
    void* m_p;
};
S_func_00759450::~S_func_00759450()
{
    if (m_p)
        G1_func_00759450(m_p);
}
