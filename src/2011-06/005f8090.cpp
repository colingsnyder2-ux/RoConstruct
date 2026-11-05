// from server: 89% by atomic.potato
struct S
{
    S* f(int);
};

extern "C" void destroy_stream(S*);
extern "C" void helper(S*);

S* S::f(int flags)
{
    S* p = (S*)((char*)this - 0x54);
    destroy_stream(p);
    if ((flags & 1) != 0)
        helper(p);
    return p;
}
