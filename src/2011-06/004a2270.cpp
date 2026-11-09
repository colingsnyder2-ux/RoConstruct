// from server: 49% by atomic.potato
typedef unsigned int DWORD;
typedef long HRESULT;

struct _com_error;

struct CVideoStream
{
    HRESULT f(void *source, void **result);
};

extern "C" void *__cdecl operator_new(unsigned int size);

HRESULT CVideoStream::f(void *source, void **result)
{
    if (result == 0)
        return (HRESULT)0x80004003;

    _com_error *err = (_com_error *)operator_new(0x14);
    if (err != 0)
    {
        *(void **)((char *)err + 8) = (char *)source - 12;
        *(void **)err = (void *)0xa76848;
        *(DWORD *)((char *)err + 4) = 0;
        *(DWORD *)((char *)err + 0x10) = 1;
        void *p = (char *)source;
        void **vt = *(void ***)p;
        ((void (__stdcall *)(void *))vt[1])(p);
        void *q = *(void **)((char *)err + 8);
        void **vt2 = *(void ***)q;
        *(DWORD *)((char *)err + 0xc) = ((DWORD (__stdcall *)(void *))vt2[4])(q);
    }
    *result = err;
    return err != 0 ? (HRESULT)0 : (HRESULT)0x8007000e;
}
