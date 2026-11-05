// from server: 52% by atomic.potato
extern "C" void *__stdcall Ogre_removeChild(void *, unsigned short);

struct S
{
    void *f(unsigned short);
};

void *S::f(unsigned short id)
{
    void *p = Ogre_removeChild(this, id);
    return p;
}
