// from server: 100% by king_originala
extern const unsigned long table0[];
extern const unsigned long table10[];
extern const unsigned long table14[];
extern const unsigned long table20[];
extern const unsigned long table24[];
extern const unsigned long table44[];
extern const unsigned long table64[];
extern const unsigned long table84[];
extern const unsigned long tableA4[];
extern const unsigned long tableC4[];

struct Base
{
    const unsigned long* volatile data[76];

    Base(const char*);
    ~Base();
};

struct Zero
{
    unsigned long value;

    Zero();
    ~Zero();
};

Zero::Zero() : value(0)
{
    if (value)
        this->~Zero();
}

struct S : Base
{
    Zero first;
    volatile unsigned long tail[3];

    S();
};

S::S() : Base(reinterpret_cast<const char*>(0x95c530)), first()
{
    data[0] = table0;
    data[4] = table10;
    data[5] = table14;
    data[8] = table20;
    data[9] = table24;
    data[17] = table44;
    data[25] = table64;
    data[33] = table84;
    data[41] = tableA4;
    data[49] = tableC4;
    tail[1] = 0;
    tail[2] = 0;
    tail[0] = 0;
}
