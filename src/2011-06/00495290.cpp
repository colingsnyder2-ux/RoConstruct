// from server: 100% by sophus
struct Interface
{
    virtual void __stdcall method00() = 0;
    virtual void __stdcall method04() = 0;
    virtual void __stdcall method08() = 0;
    virtual void __stdcall method0c() = 0;
    virtual void __stdcall method10() = 0;
    virtual void __stdcall method14() = 0;
    virtual void __stdcall method18() = 0;
    virtual int __stdcall method1c() = 0;
    virtual void __stdcall method20() = 0;
    virtual void __stdcall method24() = 0;
    virtual void __stdcall method28() = 0;
    virtual void __stdcall method2c() = 0;
    virtual void __stdcall method30() = 0;
    virtual int __stdcall method34(void *, int) = 0;
};

struct DxUserInput
{
    unsigned char pad0[0x1c0];
    void *field1c0;
    unsigned char pad1[0x08];
    Interface *field1cc;
    unsigned char pad2[0x14];
    unsigned char field1e4;

    void f();
};

void DxUserInput::f()
{
    field1cc->method20();
    if (field1cc->method34(field1c0, 5) == 0)
    {
        if (field1cc->method1c() >= 0)
            field1e4 = 1;
    }
}
