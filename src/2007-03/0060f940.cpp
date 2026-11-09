// from server: 100% by tester
struct Edge {
    int field0;
    int field4;
    int field8;
    int fieldC;
    void set(int flag, int value);
};

void Edge::set(int flag, int value)
{
    if (flag == 0)
        field8 = value;
    else
        fieldC = value;
}
