// from server: 100% by king_originala
struct Item {
    void consume(int value);
};

struct List {
    Item* next();
};

struct Object {
    unsigned char padding[0x170];
    List* list;
    int value();
};

void __cdecl func_005fdfe0(Object* object)
{
    if (object) {
        List* list = object->list;
        if (list) {
            Item* item = list->next();
            while (item) {
                item->consume(object->value());
                item = list->next();
            }
        }
    }
}
