// from server: 100% by king_originala
typedef long HRESULT;
typedef unsigned long DWORD;

struct IID {
    unsigned long a;
    unsigned short b;
    unsigned short c;
    unsigned char d[8];
};

struct Unknown {
    virtual HRESULT __stdcall QueryInterface(const IID& iid, Unknown** result) = 0;
    virtual DWORD __stdcall AddRef() = 0;
    virtual DWORD __stdcall Release() = 0;
    virtual HRESULT __stdcall GetConnectionInterface(IID* iid) = 0;
};

struct Entries {
    DWORD Add(Unknown* object);
};

struct S : Unknown {
    Entries entries;
    HRESULT __stdcall Advise(Unknown* sink, DWORD* cookie);
};

HRESULT __stdcall S::Advise(Unknown* sink, DWORD* cookie)
{
    if (cookie)
        *cookie = 0;

    if (!sink || !cookie)
        return (HRESULT)0x80004003UL;

    IID iid;
    GetConnectionInterface(&iid);

    Unknown* object;
    HRESULT result = sink->QueryInterface(iid, &object);

    if (result >= 0) {
        *cookie = entries.Add(object);
        result = *cookie ? 0 : (HRESULT)0x80040201UL;
        if (result != 0)
            object->Release();
    } else if (result == (HRESULT)0x80004002UL) {
        result = (HRESULT)0x80040202UL;
    }

    if (result < 0)
        *cookie = 0;

    return result;
}
