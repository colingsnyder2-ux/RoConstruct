// from server: 100% by auto
extern "C" void __cdecl G1_func_00832c40(void*);
struct S_func_00832c40 {
    virtual ~S_func_00832c40();
    void* m_p;
};
S_func_00832c40::~S_func_00832c40()
{
    if (m_p)
        G1_func_00832c40(m_p);
}
