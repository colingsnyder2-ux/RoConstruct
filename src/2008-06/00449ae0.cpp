// from server: 100% by king_originala
struct CIDEDocManager {
    unsigned char padding[36];
    int defaultValue;

    int forward(int a, int b, int c, int d, int e);
    int f(int a, int b, int c, int d, int e);
};

int CIDEDocManager::f(int a, int b, int c, int d, int e)
{
    if (!e)
        e = defaultValue;
    return forward(a, b, c, d, e);
}
