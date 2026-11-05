// from server: 100% by colin
struct IUnknown {
    virtual long __stdcall QueryInterface(const void *riid, void **ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

extern "C" const unsigned char g_iid1[16];
extern "C" const unsigned char g_iid2[16];

extern "C" long __stdcall Proxy_QueryInterface(void *self, const void *riid, void **ppvObject)
{
    if (ppvObject == 0)
        return (long)0x80004003UL;

    *ppvObject = 0;

    const unsigned int *guid = (const unsigned int *)riid;
    const unsigned int *g1 = (const unsigned int *)g_iid1;
    const unsigned int *g2 = (const unsigned int *)g_iid2;

    bool match = false;
    if (guid[0] == 0xb196b286 && guid[1] == g1[0] && guid[2] == g1[1] && guid[3] == g1[2])
        match = true;
    else if (guid[0] == 0 && guid[1] == 0 && guid[2] == 0xc0 && guid[3] == 0x46000000)
        match = true;

    if (!match)
        return (long)0x80004002UL;

    *ppvObject = self;
    IUnknown *unk = (IUnknown *)self;
    unk->AddRef();
    return 0;
}
