// from server: 100% by king_originala
extern "C" long (__stdcall *SendMessageA)(void *, unsigned int, unsigned int, long);

struct Item {
    virtual void reserved();
    virtual ~Item();
};

struct FlagGuard {
    bool *flag;
    bool previous;

    FlagGuard(bool &value) : flag(&value), previous(value) {
        value = true;
    }

    ~FlagGuard() {
        *flag = previous;
    }
};

struct S {
    char padding0[0x20];
    void *window;
    char padding1[0x70];
    Item *item;
    char padding2[0x20];
    bool busy;

    void prepare();
    void clear();
};

void S::clear() {
    prepare();
    FlagGuard guard(busy);
    SendMessageA(window, 0x1101, 0, (long)0xffff0000);
    if (item) {
        delete item;
        item = 0;
    }
}
