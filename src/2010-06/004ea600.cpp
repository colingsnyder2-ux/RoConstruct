// from server: 71% by atomic.potato
struct PingBackItem {
    int type;
    int unknown04;
    int unknown08;
    int unknown0c;
    int value10;
    int value14;
    void set(int, int);
};

void PingBackItem::set(int a, int b)
{
    unknown08 = 0;
    unknown0c = 0;
    value10 = a;
    type = 0xA1B1AC;
    value14 = b;
}
