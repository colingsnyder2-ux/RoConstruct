// from server: 100% by king_originala
struct Interface {
    virtual void __stdcall slot0() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Helper {
    void sub_6a0a28();
};

struct CWebToolbox {
    char pad[0xf8];
    Helper* field_f8;
    Interface* field_fc;
    long func_0046a8e0(Interface** out);
};

long CWebToolbox::func_0046a8e0(Interface** out)
{
    if (field_f8)
        field_f8->sub_6a0a28();

    Interface* value = field_fc;
    if (value)
        value->AddRef();

    long result;
    if (!out) {
        result = (long)0x80004003UL;
    } else {
        *out = value;
        if (value)
            value->AddRef();
        result = 0;
    }

    if (value)
        value->Release();

    return result;
}
