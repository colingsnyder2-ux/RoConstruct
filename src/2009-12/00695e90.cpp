// from server: 100% by atomic.potato
struct ArrowTool
{
    int f();
};

int ArrowTool::f()
{
    if (reinterpret_cast<unsigned char *>(this)[4] ||
        reinterpret_cast<unsigned char *>(this)[5] ||
        reinterpret_cast<unsigned char *>(this)[6] ||
        reinterpret_cast<unsigned char *>(this)[7])
        return 1;
    return 0;
}
