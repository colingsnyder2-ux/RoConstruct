// from server: 63% by atomic.potato
struct CRbxDocTemplate
{
    int f(int, int);
};

struct GlobalType
{
    int g(int);
};

extern GlobalType g_object;

int CRbxDocTemplate::f(int a, int b)
{
    g_object.g(1);
    return g_object.g(a);
}
