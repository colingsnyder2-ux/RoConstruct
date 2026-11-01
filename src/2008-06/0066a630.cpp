// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Item {
    char storage[44];
    Item(int, int, int);
    ~Item();
};

struct Base {
    int words[7];
    int f(int);
    ~Base();
    Base(int);
};

Base::Base(int value) {
    f(value);
    words[0] = 0x84d02c;
    words[1] = 0x84d014;
}

struct Owner {
    Item* pointer;
    Owner();
    ~Owner();
    void reset(Item*);
};

Owner::Owner() : pointer(0) {}

Owner::~Owner() {
    delete pointer;
}

void Owner::reset(Item* value) {
    if (value != pointer && pointer)
        delete pointer;
    pointer = value;
}

struct S : Base {
    Owner item;
    float x;
    float y;
    volatile bool flag;
    volatile float a;
    float b;
    float c;

    S(int, int, int, int);
};

S::S(int first, int unused, int third, int fourth)
    : Base(fourth), x(0.0f), y(0.0f), flag(false),
      a(0.0f), b(0.0f), c(0.0f)
{
    item.reset(new Item(first, third, fourth));
}
