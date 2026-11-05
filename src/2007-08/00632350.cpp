// from server: 100% by auto
extern "C" void __cdecl G1_func_00632350(void*);
struct S_func_00632350 {
    virtual ~S_func_00632350();
    void* m_p;
};
S_func_00632350::~S_func_00632350()
{
    if (m_p)
        G1_func_00632350(m_p);
}
