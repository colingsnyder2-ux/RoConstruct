// from server: 100% by king_originala
struct Source {
    void *first();
    void *second();
};

struct Base {
    unsigned int storage[83];
    Base();
    ~Base();
};

struct S : Base {
    void *firstValue;
    void *secondValue;
    S(Source *);
};

S::S(Source *source) : Base()
{
    storage[0] = 0x0084bcb4;
    storage[4] = 0x0084bca4;
    storage[5] = 0x0084bc9c;
    storage[8] = 0x0084bc94;
    storage[9] = 0x0084bc84;
    storage[17] = 0x0084bc74;
    storage[25] = 0x0084bc64;
    storage[33] = 0x0084bc54;
    storage[41] = 0x0084bc44;
    storage[49] = 0x0084bc34;
    storage[76] = 0x0084bc2c;
    storage[81] = 0x0084bc20;
    storage[82] = 0x0084bc14;
    firstValue = 0;
    secondValue = 0;
    firstValue = source ? source->first() : 0;
    secondValue = source ? source->second() : 0;
}
