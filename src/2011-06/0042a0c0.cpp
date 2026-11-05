// from server: 100% by atomic.potato
struct CRobloxTreeCtrlNode
{
    unsigned char pad[0x38];
    unsigned char value;
    void f(void* arg);
};

void CRobloxTreeCtrlNode::f(void* arg)
{
    unsigned char* p = (unsigned char*)arg;
    if (p[0x0c] & 0x40)
    {
        unsigned int v = 0;
        v = (value != 0);
        *(unsigned int*)(p + 0x2c) = v;
    }
}
