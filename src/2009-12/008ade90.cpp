// from server: 100% by atomic.potato
struct CXTPDockingPaneWindowSelect
{
    int value0;
    int value4;
    int value8;
    int valueC;
    int value10;
    int value14;
    int value18;
    int value1C;
    int value20;
    int value24;
    int value28;
    CXTPDockingPaneWindowSelect();
};

struct WindowSelectInitializer
{
    void Initialize(int);
};

CXTPDockingPaneWindowSelect::CXTPDockingPaneWindowSelect()
{
    value0 = 0x00A06D2C;
    ((WindowSelectInitializer *)((char *)this + 8))->Initialize(10);
    value28 = 0;
    value4 = 0;
    value24 = 0;
}
