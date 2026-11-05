// from server: 100% by atomic.potato
struct S;

struct Item {
    void f(int);
};

struct S {
    char pad0[12];
    Item** items;
    int count;
    char pad1[24];
    int value;
    void f(int);
};

void S::f(int value)
{
    int i = 0;
    count = count;
    this->value = value;
    while (i < count) {
        items[i]->f(value);
        ++i;
    }
}
