// from server: 65% by atomic.potato
struct Shader {
    char pad0[0xc];
    unsigned int count;
    unsigned int capacity;
    char pad14[0x1c];
    void* buf30;
    char pad34[0x10];
    char field44;
    char pad45[3];
    void* field48;
    void release();
};

extern "C" void __stdcall invalid_parameter_noinfo();
extern "C" void __stdcall VertexData_dtor(void*);
extern "C" void __stdcall deallocBytes(void*);
extern "C" void __stdcall setNull(void*);
extern "C" void __stdcall sub_48cbf0(void*, void*, unsigned int, void*, unsigned int);

void Shader::release()
{
    unsigned int cap = capacity;
    if (count > cap)
        invalid_parameter_noinfo();
    unsigned int c = count;
    void* base = *(void**)this;
    if (c > capacity)
        invalid_parameter_noinfo();
    void* p = *(void**)this;
    void* tmp;
    sub_48cbf0(&tmp, p, c, base, cap);
    if (field48 != 0)
    {
        void* b = buf30;
        if (b != 0)
        {
            VertexData_dtor(b);
            deallocBytes(b);
        }
        buf30 = 0;
        setNull(&field44);
        return;
    }
}
