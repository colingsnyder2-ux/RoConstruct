// from server: 100% by auto
extern "C" void __cdecl G1_func_00820420(void*);
struct S_func_00820420 {
    virtual ~S_func_00820420();
    void* m_p;
};
S_func_00820420::~S_func_00820420()
{
    if (m_p)
        G1_func_00820420(m_p);
}
