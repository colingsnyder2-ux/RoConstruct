// from server: 100% by auto
extern "C" void __cdecl G1_func_00703360(void*);
struct S_func_00703360 {
    virtual ~S_func_00703360();
    void* m_p;
};
S_func_00703360::~S_func_00703360()
{
    if (m_p)
        G1_func_00703360(m_p);
}
