// from server: 100% by auto
extern "C" void __cdecl G1_func_0081b200(void*);
struct S_func_0081b200 {
    virtual ~S_func_0081b200();
    void* m_p;
};
S_func_0081b200::~S_func_0081b200()
{
    if (m_p)
        G1_func_0081b200(m_p);
}
