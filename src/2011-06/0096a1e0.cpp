// from server: 56% by atomic.potato
extern "C" void OgreNode_removeAllChildren(void *);

struct S
{
    void f();
};

void S::f()
{
    void **list = *(void ***)((char *)this + 0x10);
    void *node = *list;

    while (node != list)
    {
        OgreNode_removeAllChildren((char *)node + 0x24);
        node = *(void **)node;
    }
}
