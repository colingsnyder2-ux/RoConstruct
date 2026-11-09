// from server: 100% by atomic.potato
struct CRobloxTreeCtrlNode
{
    void f(int *value);
};

void CRobloxTreeCtrlNode::f(int *value)
{
    if (*(unsigned char *)((char *)value + 12) & 64)
        *(int *)((char *)value + 44) = ((unsigned char *)((char *)this + 104))[0] != 0;
}
