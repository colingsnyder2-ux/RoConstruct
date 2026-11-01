// from server: 100% by auto
extern "C" void __cdecl G1_func_00878350(void*);
struct S_func_00878350 {
    virtual ~S_func_00878350();
    void* m_p;
};
S_func_00878350::~S_func_00878350()
{
    if (m_p)
        G1_func_00878350(m_p);
}
