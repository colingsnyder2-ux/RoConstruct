// from server: 38% by atomic.potato
extern "C" unsigned long __stdcall TlsSetValue(unsigned long, void*);

struct S
{
    S* f();
};

S* S::f()
{
    unsigned long value = *(unsigned long*)0x00c1afcc;
    TlsSetValue(*(unsigned long*)0x009ea214, (void*)value);
    return this;
}
