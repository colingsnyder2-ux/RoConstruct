// from server: 100% by auto
extern "C" void __cdecl G1_func_00856d10(void*);
struct S_func_00856d10 {
    virtual ~S_func_00856d10();
    void* m_p;
};
S_func_00856d10::~S_func_00856d10()
{
    if (m_p)
        G1_func_00856d10(m_p);
}
