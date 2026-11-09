// from server: 90% by atomic.potato
extern "C" void *__stdcall Ogre_removeChild(void *, void *);

struct S
{
    void *f(void *);
};

void *S::f(void *a)
{
    void *r = Ogre_removeChild(this, a);
    f(r);
    return r;
}
