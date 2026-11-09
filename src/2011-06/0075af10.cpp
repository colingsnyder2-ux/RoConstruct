// from server: 84% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);
extern "C" void *__cdecl AllocateNode();

struct GeoPairConnector
{
    void *next;
    GeoPairConnector *f(unsigned char);
};

GeoPairConnector *GeoPairConnector::f(unsigned char flag)
{
    GeoPairConnector *self = this;
    if (flag & 1)
    {
        GeoPairConnector *node = (GeoPairConnector *)AllocateNode();
        EnterCriticalSection(node);
        self->next = node->next;
        node->next = self;
        LeaveCriticalSection(node);
    }
    return self;
}
