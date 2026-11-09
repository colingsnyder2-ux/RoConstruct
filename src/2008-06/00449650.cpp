// from server: 100% by king_originala
extern char* func_0040df80();
extern char* func_0040dfa0();
extern char* func_00432fc0();

struct Item {
    unsigned char storage[0x6c];
    Item(int, char*, char*, char*);
};

struct Base {
    unsigned char padding[0x1c];
    Base();
    virtual ~Base();
    void attach(Item*);
};

struct S : Base {
    Item* item;
    S();
    virtual ~S();
};

S::S()
{
    item = new Item(0xb9, func_0040dfa0(),
                    func_00432fc0(), func_0040df80());
    attach(item);
}
