// from server: 100% by atomic.potato
struct CXTPTabManagerItem
{
    int field0;
    int field4;
    int field8;
    CXTPTabManagerItem(int value);
};

struct CXTPTabManagerNavigateButton
{
    void Initialize(int value);
};

CXTPTabManagerItem::CXTPTabManagerItem(int value)
{
    field4 = 0;
    field0 = 0;
    field8 = value;
    ((CXTPTabManagerNavigateButton *)this)->Initialize(1);
}
