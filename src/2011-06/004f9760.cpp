// from server: 92% by atomic.potato
struct PingBackItem
{
    int type;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    double timestamp;
    int field20;

    PingBackItem(int, int);
};

PingBackItem::PingBackItem(int value, int marker)
{
    field0c = 0;
    field10 = 0;
    field14 = value;
    timestamp = 0.0;
    type = 0xA7B4D0;
    field20 = marker;
}
