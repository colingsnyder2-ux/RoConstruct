// from server: 52% by atomic.potato
extern "C" void *__stdcall Ogre_removeChild(void *, const void *);

struct S {
    void *f(const void *);
};

void *S::f(const void *p)
{
    void *r = Ogre_removeChild(this, p);
    return r;
}
