// from server: 100% by why2
struct CXTPPrintPageHeaderFooter
{
    int f(int a, int b);
};

int CXTPPrintPageHeaderFooter::f(int a, int b)
{
    int q = b / a;
    int r = b % a;
    return q + (r != 0);
}
