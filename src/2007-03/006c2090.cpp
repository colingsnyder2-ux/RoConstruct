// from server: 100% by tester
struct CXTPDockingPaneLayout {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
};

extern "C" int __stdcall sub_6d8bf0(CXTPDockingPaneLayout* p);
extern "C" int __stdcall sub_6d88c0(CXTPDockingPaneLayout* p);

int __stdcall sub_6d8f00(CXTPDockingPaneLayout* p)
{
    if (p->field24 != 0)
    {
        return sub_6d88c0(p);
    }
    sub_6d8bf0(p);
    return 1;
}
