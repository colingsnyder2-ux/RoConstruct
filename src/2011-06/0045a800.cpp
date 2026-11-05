// from server: 80% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __stdcall ExternalRelease(void *);
extern "C" void Destroy(void *);
extern "C" void __cdecl DeleteObject(void *);

struct CRbxPlayDocTemplate
{
    char padding[0x94];
    void *value;
    void *Release(unsigned char);
};

void *CRbxPlayDocTemplate::Release(unsigned char flags)
{
    ExternalRelease(padding + 0x94);
    Destroy(this);
    if (flags & 1)
        DeleteObject(this);
    return this;
}
