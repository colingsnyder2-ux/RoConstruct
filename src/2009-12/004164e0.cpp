// from server: 62% by atomic.potato
struct PasteVerb
{
    char pad0[0x1c];
    void *field1c;
    PasteVerb * __cdecl f(PasteVerb *other);
};

extern "C" void *__stdcall sub_416390(void *);
extern "C" void *__stdcall sub_98b6f0(void *, void *);

PasteVerb *PasteVerb::f(PasteVerb *other)
{
    void *tmp = sub_416390(other);
    sub_98b6f0(this, tmp);
    field1c = *(void **)((char *)tmp + 0x1c);
    return this;
}
