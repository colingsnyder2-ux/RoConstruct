// from server: 100% by king_originala
struct S;

extern int guard;
extern S source;

extern void __cdecl callback();
extern void __cdecl initialize(void (__cdecl *)(), int *);

typedef S *(__thiscall *CopyFunction)(S *, const S &);
extern CopyFunction copyFunction;

S *__cdecl construct(S *destination)
{
    volatile int state = 0;
    initialize(callback, &guard);
    copyFunction(destination, source);
    return destination;
}
