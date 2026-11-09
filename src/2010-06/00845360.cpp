// from server: 100% by auto
extern "C" void __cdecl G1_func_00845360(void*);
struct S_func_00845360 {
    virtual ~S_func_00845360();
    void* m_p;
};
S_func_00845360::~S_func_00845360()
{
    if (m_p)
        G1_func_00845360(m_p);
}
