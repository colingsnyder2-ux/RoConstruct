// from server: 100% by auto
extern "C" void __cdecl G1_func_00773360(void*);
struct S_func_00773360 {
    virtual ~S_func_00773360();
    void* m_p;
};
S_func_00773360::~S_func_00773360()
{
    if (m_p)
        G1_func_00773360(m_p);
}
