// from server: 100% by king_originala
struct Value {
    char data[12];
    void set(int, int);
};

struct Clump {
    char padding[8];
    Value value;
    bool dirty;

    void update(Value*);
    Value* getValue();
};

Value* Clump::getValue()
{
    if (dirty) {
        value.set(0, 0);
        update(&value);
    }
    dirty = false;
    return &value;
}
