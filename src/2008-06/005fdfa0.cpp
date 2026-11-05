// from server: 100% by king_originala
struct Item {
    void consume(void* product);
};

struct Source {
    Item* next();
};

extern void* __cdecl func_005a3380(Source* source);

void __cdecl func_005fdfa0(Source* source)
{
    void* product = func_005a3380(source);
    if (product) {
        Item* item = source->next();
        while (item) {
            item->consume(product);
            item = source->next();
        }
    }
}
