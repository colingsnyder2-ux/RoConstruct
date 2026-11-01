// from server: 100% by king_originala
struct Value
{
    char data[0x58];
};

struct Item
{
    Value getValue();
};

struct S
{
    char padding[0x158];
    Item item;

    void setValue(const Value &value);
    void update();
};

void S::update()
{
    setValue(item.getValue());
}
