// from server: 60% by atomic.potato
struct CIDEDocManager
{
    int get(int a, int b, int c, int d, int e);
    int field24;
};

int CIDEDocManager::get(int a, int b, int c, int d, int e)
{
    if (!e)
        e = field24;
    return e;
}
