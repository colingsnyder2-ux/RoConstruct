// from server: 100% by atomic.potato
struct CRobloxTreeCtrlNode
{
    void f(void* node);
};

void CRobloxTreeCtrlNode::f(void* node)
{
    struct Data
    {
        unsigned char pad0[12];
        unsigned char flags;
        unsigned char pad1[31];
        unsigned int value;
    };

    if (((Data*)node)->flags & 0x40)
        ((Data*)node)->value = ((unsigned char*)this)[0x68] != 0;
}
