// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
void __cdecl operator delete(void *);

struct Item {
    ~Item();
};

struct Iterator {
    void *owner;
    unsigned int offset;
    Item *&operator*() const;
};

struct S {
    char padding0[0x174];
    void *owner;
    char padding1[0x10];
    unsigned int mapSize;
    unsigned int offset;
    unsigned int size;

    void pop_front();
};

void S::pop_front()
{
    unsigned int first = offset;
    if (first > first + size)
        invalid_parameter_noinfo();

    Iterator it;
    it.owner = owner;
    it.offset = first;
    Item *item = *it;

    if (size != 0) {
        ++offset;
        if (mapSize * 4 <= offset)
            offset = 0;
        if (--size == 0)
            offset = 0;
    }

    delete item;
}
