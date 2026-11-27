// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Outer {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual long v8(void* p);
};
struct Iface { int x; };
long __stdcall Method(Iface* self, void* value)
{
    if (value == 0)
        return (long)0x80004003;
    long hr = ((Outer*)((char*)self - 0xc))->v8(value);
    if (hr < 0)
        hr = 1;
    return hr;
}
