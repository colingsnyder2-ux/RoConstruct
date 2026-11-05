// from server: 40% by atomic.potato
struct EqDisp {
    char pad[0xec];
    void* field_ec;
    void destroy();
    EqDisp* scalar_dtor(char);
};

extern "C" void __stdcall sub_98b6e4(void*);
extern "C" void __stdcall sub_675a70(void*);
extern "C" void __stdcall sub_7f385a(void*);

void EqDisp::destroy()
{
    sub_98b6e4(&field_ec);
    sub_675a70(this);
}

EqDisp* EqDisp::scalar_dtor(char flag)
{
    destroy();
    if (flag & 1)
        sub_7f385a(this);
    return this;
}
