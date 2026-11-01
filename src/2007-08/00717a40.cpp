// from server: 100% by colin
struct Inner
{
    int Method(int);
};

struct CXTPRibbonTabPopupToolBar
{
    char pad_0000[0x248];
    Inner inner;
    char pad_024c[0x25c - 0x24c];
    int field_025c;
    int Method();
};

int CXTPRibbonTabPopupToolBar::Method()
{
    return inner.Method(field_025c);
}
