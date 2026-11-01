// from server: 100% by atomic.potato
struct CXTSplitterWnd
{
    unsigned char pad[264];
    unsigned char flags;
    int f(int, int);
};

extern int func_006a0c68();

int CXTSplitterWnd::f(int, int)
{
    if (flags & 8)
        return 18;
    return func_006a0c68();
}
