// from server: 94% by atomic.potato
typedef long HRESULT;
typedef unsigned long DWORD;
typedef const void *REFIID;
typedef void *LPVOID;

extern "C" HRESULT __stdcall CoCreateInstance(
    REFIID rclsid,
    LPVOID pUnkOuter,
    DWORD dwClsContext,
    REFIID riid,
    LPVOID *ppv
);

struct CVideoStream
{
    HRESULT f(void *p);
};

HRESULT CVideoStream::f(void *p)
{
    return CoCreateInstance((REFIID)0xA5EEDC, 0, 1, (REFIID)0xA76A8C, (LPVOID *)p);
}
