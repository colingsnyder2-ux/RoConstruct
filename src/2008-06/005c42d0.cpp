// from server: 100% by king_originala
typedef unsigned long DWORD;

extern DWORD tlsIndex;
extern "C" int (__stdcall *TlsSetValue)(DWORD, void *);
extern double __cdecl currentTime();

struct Profiler
{
    char padding[0xC040];
    Profiler *excluded;

    void __thiscall record(unsigned char category, double elapsed);
};

struct Scope
{
    Profiler *profiler;
    Scope *parent;
    unsigned char category;
    char padding[7];
    double start;

    void __thiscall finish();
};

void __thiscall Scope::finish()
{
    if (tlsIndex)
    {
        TlsSetValue(tlsIndex, parent);
        double elapsed = currentTime() - start;
        profiler->record(category, elapsed);

        if (parent &&
            parent->profiler != profiler &&
            parent->profiler != profiler->excluded)
        {
            parent->start += elapsed;
        }
    }
}
