// from server: 100% by king_originala
struct S {
    void *get();
};

extern S *__cdecl lookup(void *);

bool __cdecl func_0049fe20(void *arg)
{
    S *p = lookup(arg);
    return (p ? p->get() : 0) != 0;
}
