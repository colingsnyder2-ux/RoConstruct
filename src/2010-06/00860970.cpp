// from server: 100% by auto
extern "C" void __cdecl G1_func_00860970(void*);
struct S_func_00860970 {
    virtual ~S_func_00860970();
    void* m_p;
};
S_func_00860970::~S_func_00860970()
{
    if (m_p)
        G1_func_00860970(m_p);
}
