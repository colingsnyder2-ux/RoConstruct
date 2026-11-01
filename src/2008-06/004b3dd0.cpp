// from server: 100% by king_originala
struct Key {
    unsigned int first;
    unsigned int second;
    void Set(int, int);
};

struct S {
    virtual void notify();
    unsigned int padding;
    Key key;

    void begin();
    void end();
    void f(const Key& value);
};

void S::f(const Key& value)
{
    begin();
    key.Set(value.first, value.second);
    end();
    notify();
}
