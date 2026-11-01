// from server: 100% by colin
// from server: 97% by EspClaude
// from server: 63% by colin
// roc 2008-06 006a170a  unit: ActiveDocView  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a170a
// 006a170a  6a14                 push 0x14
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O1 /GS /MD
typedef void (__cdecl *_PVFV)(void);
typedef int (__cdecl *_onexit_t)(void);

extern "C" __declspec(dllimport) void * __cdecl _decode_pointer(void *);
extern "C" __declspec(dllimport) void * __cdecl _encode_pointer(void *);
extern "C" __declspec(dllimport) _onexit_t __cdecl _onexit(_onexit_t);
extern "C" _onexit_t __cdecl __dllonexit(_onexit_t, _PVFV **, _PVFV **);
extern "C" void __cdecl _lock(int);
extern "C" void __cdecl _unlock(int);
extern "C" _PVFV *__onexitbegin;
extern "C" _PVFV *__onexitend;

extern "C" _onexit_t __cdecl roc_onexit(_onexit_t func)
{
    _PVFV *onexitbegin;
    _PVFV *onexitend;
    _onexit_t retval;

    onexitbegin = (_PVFV *)_decode_pointer(__onexitbegin);

    if (onexitbegin == (_PVFV *)-1)
    {
        return _onexit(func);
    }

    _lock(8);

    __try
    {
        onexitbegin = (_PVFV *)_decode_pointer(__onexitbegin);
        onexitend = (_PVFV *)_decode_pointer(__onexitend);

        retval = __dllonexit((_onexit_t)_encode_pointer(func), &onexitbegin, &onexitend);

        __onexitbegin = (_PVFV *)_encode_pointer(onexitbegin);
        __onexitend = (_PVFV *)_encode_pointer(onexitend);
    }
    __finally
    {
        _unlock(8);
    }

    return retval;
}
