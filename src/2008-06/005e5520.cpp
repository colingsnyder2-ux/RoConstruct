// from server: 100% by king_originala
extern char sourceType;
extern char targetType;

extern "C" void* __cdecl runtimeCast(
    void*, int, const void*, const void*, int);

struct Item;

struct Collection {
    void remove(Item*);
};

struct S {
    char padding[0x138];
    Collection collection;

    void baseRemove(void**);
    void remove(void**);
};

void S::remove(void** value)
{
    Item* item = static_cast<Item*>(
        runtimeCast(*value, 0, &sourceType, &targetType, 0));
    if (item)
        collection.remove(item);
    baseRemove(value);
}
