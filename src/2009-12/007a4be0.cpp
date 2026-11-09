// from server: 84% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl Function558AB0(void *);
extern "C" void __cdecl Function6CB590(void *, void *, void *);

struct S
{
    void *f(void *, void *);
};

void *S::f(void *a, void *b)
{
    void *v = a;
    Function558AB0(v);
    Function6CB590(this, b, v);
    return v;
}
