// from server: 100% by auto
extern "C" void __cdecl G1_func_00855300(void*);
struct S_func_00855300 {
    virtual ~S_func_00855300();
    void* m_p;
};
S_func_00855300::~S_func_00855300()
{
    if (m_p)
        G1_func_00855300(m_p);
}
