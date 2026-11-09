// from server: 17% by TrollStein
extern "C" void* __cdecl malloc(unsigned int size);

struct Item {
    void __cdecl construct(void* p);
};

struct TypedStatsItem : Item {
    void* func;
    void init(void* f);
};

void TypedStatsItem::init(void* f) {
    func = f;
}

void Item::construct(void* p) {
    void* mem = malloc(0x120);
    if (mem) {
        ((TypedStatsItem*)mem)->init(p);
    }
}
