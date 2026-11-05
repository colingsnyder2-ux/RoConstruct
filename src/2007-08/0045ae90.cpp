// from server: 25% by colin
struct Item {
    void constructFrom(void*);
};

struct TypedStatsItem : Item {
    void* func;
    TypedStatsItem(void* f);
};

extern "C" void* __stdcall malloc(unsigned int);
extern "C" void __stdcall sub_45ABD0(void*, void*);
extern "C" void __stdcall sub_459140(void*, void*, void*);

TypedStatsItem::TypedStatsItem(void* f)
{
    void* mem = malloc(0x120);
    if (mem) {
        sub_45ABD0(mem, f);
    } else {
        mem = 0;
    }
    sub_459140(this, mem, 0);
}
