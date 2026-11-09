// from server: 84% by atomic.potato
extern "C" int __cdecl f424990(const char *, const char *, int);

struct S
{
    int f();
};

int S::f()
{
    return f424990("Unexpected exception", "&P*k", 0);
}
