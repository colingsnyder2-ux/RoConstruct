// from server: 80% by atomic.potato
extern "C" void G1_func_007f44d2(void*);
extern "C" void G1_func_007f385a(void*);
extern "C" void G1_func_0098dec0(void*);

struct CRbxPlayDocTemplate
{
    char reserved[0x94];
    int f(unsigned int flags);
};

int CRbxPlayDocTemplate::f(unsigned int flags)
{
    G1_func_0098dec0((char*)this + 0x94);
    G1_func_007f44d2(this);
    if (flags & 1)
        G1_func_007f385a(this);
    return (int)this;
}
