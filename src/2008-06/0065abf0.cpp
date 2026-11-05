// from server: 100% by king_originala
struct Item {
    char data[0x80];
};

struct ItemList {
    Item** items;
    int count;
};

struct S {
    void process(Item*, void*);
    void f(ItemList*);
};

void S::f(ItemList* list)
{
    for (int i = 0; i < list->count; ++i) {
        Item* item = list->items[i];
        process(item, reinterpret_cast<char*>(item) + 0x80);
    }
}
