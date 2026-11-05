// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl CallTarget(void *, void *, void *, void *);

struct BoundFuncDesc
{
    char padding[0x30];
    void *field30;
    void *field34;
    void invoke(void *, void *);
};

void BoundFuncDesc::invoke(void *a, void *b)
{
    void *p = a ? static_cast<char *>(a) - 0x1c : 0;
    CallTarget(p, field30, field34, static_cast<char *>(b) + 4);
}
