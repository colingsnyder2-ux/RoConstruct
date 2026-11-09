// from server: 34% by atomic.potato
typedef void * (__thiscall *Method)(void *);

struct MD5HasherImpl
{
    void f(void *);
};

void MD5HasherImpl::f(void *p)
{
    Method m = *(Method *)*(void **)p;
    void *value = m(p);
    ((void (__thiscall *)(MD5HasherImpl *, void *, void *))0x005b1b90)(this, p, value);
}
