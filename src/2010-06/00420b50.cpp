// from server: 48% by atomic.potato
struct CRobloxTreeCtrlNode
{
    void f(void* node);
};

void CRobloxTreeCtrlNode::f(void* node)
{
    struct Data
    {
        unsigned char pad0[0x5c];
        unsigned char flags;
        unsigned char pad1[3];
        void* obj;
        unsigned char pad2[0x28];
        void* arg;
    };

    Data* self = (Data*)this;

    if (self->flags & 0x02)
    {
        self->flags &= ~0x02;
        return;
    }

    typedef int (__stdcall *Fn)(void*, int);

    void* obj = self->obj;
    Fn fn = *(Fn*)(*(void**)obj);
    fn = *(Fn*)((char*)fn + 0x144);

    int r = fn(self->arg, 8);
    if ((r | 0x20) == 0)
        return;

    self->flags |= 0x02;

    obj = self->obj;
    fn = *(Fn*)(*(void**)obj);
    fn = *(Fn*)((char*)fn + 0x144);

    r = fn(self->arg, 8);
    if ((r | 0x80) == 0)
        return;

    obj = self->obj;
    fn = *(Fn*)(*(void**)obj);
    fn = *(Fn*)((char*)fn + 0x14c);

    fn(self->arg, 8);
}
