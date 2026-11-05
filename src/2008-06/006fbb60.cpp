// from server: 100% by auto
extern "C" void __cdecl G1_func_006fbb60(void*);
struct S_func_006fbb60 {
    virtual ~S_func_006fbb60();
    void* m_p;
};
S_func_006fbb60::~S_func_006fbb60()
{
    if (m_p)
        G1_func_006fbb60(m_p);
}
