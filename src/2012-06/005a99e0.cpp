// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Inner {
    char pad[0x10];
    Inner& operator=(const Inner&);
};
struct Row {
    int a;
    int b;
    Inner c;
};
void copy_rows(Row* dst, Row* end, Row* src)
{
    for (; dst != end; ++dst)
        *dst = *src;
}
