// from server: 90% by atomic.potato
extern "C" void __stdcall sub_00A99B78(void *, int);

struct CXTThemeManagerStyleHost
{
    void *vftable;
    int value04;
    int value08;
    int value0C;
    int value10;
    int value14;
    int value18;
    int value1C;
    int value20;
    int value24;
    int value28;
    CXTThemeManagerStyleHost();
};

CXTThemeManagerStyleHost::CXTThemeManagerStyleHost()
{
    vftable = (void *)0xC17870;
    sub_00A99B78(&value04, 10);
    value24 = 0;
    value20 = 0;
    value28 = 16;
}
