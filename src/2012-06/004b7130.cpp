// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct GUID { unsigned long a; unsigned short b, c; unsigned char d[8]; };
extern "C" const GUID IID_IMemInputPin;
struct IPin
{
    virtual long __stdcall QueryInterface(const GUID &, void **);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall v3(); virtual long __stdcall v4(); virtual long __stdcall v5();
    virtual long __stdcall v6(); virtual long __stdcall v7(); virtual long __stdcall v8();
    virtual long __stdcall QueryDirection(int *);
};
struct CVideoStream {
    char pad0[0x1c];
    int m_dir;
    char pad1[0x7c];
    void *m_pInputPin;
    long CheckConnect(IPin *pPin);
};
long CVideoStream::CheckConnect(IPin *pPin)
{
    int dir;
    pPin->QueryDirection(&dir);
    if (dir == m_dir)
        return 0x80040208;
    long hr = pPin->QueryInterface(IID_IMemInputPin, &m_pInputPin);
    if (hr < 0)
        return hr;
    return 0;
}