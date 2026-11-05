// from server: 85% by atomic.potato
extern "C" void __cdecl Ogre_NedAllocImpl_deallocBytes(void *);

void func_0097ee70()
{
    void *p = *(void **)0x00b7cd4c;
    if (p)
        Ogre_NedAllocImpl_deallocBytes(p);
}
