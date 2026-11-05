// from server: 100% by king_originala
extern unsigned long tlsIndex;
extern double __cdecl currentTime();
extern "C" void* (__stdcall *TlsGetValue)(unsigned long);
extern "C" int (__stdcall *TlsSetValue)(unsigned long, void*);

struct S
{
    const char* name;
    void* previous;
    bool enabled;
    double startTime;

    S(const char* nameValue, bool enabledValue);
};

S::S(const char* nameValue, bool enabledValue)
{
    name = nameValue;
    enabled = enabledValue;
    if (tlsIndex != 0)
    {
        startTime = currentTime();
        previous = TlsGetValue(tlsIndex);
        TlsSetValue(tlsIndex, this);
    }
}
