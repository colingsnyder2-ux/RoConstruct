// from server: 69% by atomic.potato
extern "C" void * __stdcall imported_str(void *, void *);

struct Ogre_LogListener
{
    void *str(void *);
};

void *Ogre_LogListener::str(void *value)
{
    void *result = 0;
    imported_str((char *)this + 4, value);
    return value;
}
