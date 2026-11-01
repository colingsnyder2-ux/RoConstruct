// from server: 100% by colin
struct BoundFuncDesc {
    char pad[8];
    int value;
    void addTo(int amount);
};

void BoundFuncDesc::addTo(int amount)
{
    value += amount;
}
