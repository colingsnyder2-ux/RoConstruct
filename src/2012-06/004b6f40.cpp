// from server: 100% by atomic.potato
typedef long HRESULT;

struct CVideoStream
{
    HRESULT f(void *source, void **result);
};

struct Interface
{
    void **vtable;
};

typedef void (__stdcall *ReleaseFunction)(Interface *);

HRESULT CVideoStream::f(void *source, void **result)
{
    if (result == 0)
        return (HRESULT)0x80004003;

    Interface *value = *(Interface **)((char *)source + 12);
    *result = value;

    if (value != 0)
    {
        ReleaseFunction release = (ReleaseFunction)value->vtable[1];
        release(value);
        return 0;
    }

    return (HRESULT)0x80040209;
}
