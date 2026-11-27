// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct ContentFilter {
    bool a(int x);
    unsigned char b(int x);
    int f(int x);
};
int ContentFilter::f(int x)
{
    if (a(x)) {
        return b(x) ? 1 : 2;
    }
    return 0;
}
