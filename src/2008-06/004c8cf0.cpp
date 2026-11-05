// from server: 100% by colin
//

struct Link;

struct Tag {
    bool value;
};

struct Position {
    Tag tag;
    Link *link;
};

struct Object {
    char reserved[0x8];
    void *key;
};

struct Product;

extern "C" void __cdecl insert(Link *node, Position position, Link *owner);

struct Factory {
    bool find(void *key, Position *position, Tag tag);
    Product *construct(void *argument, void *storage);
    Product *create(Object *argument, Product *storage);
};

Product *Factory::create(Object *argument, Product *storage)
{
    Position position;
    position.tag.value = false;

    if (!find(argument->key, &position, position.tag)) {
        if (position.link)
            return reinterpret_cast<Product *>(
                reinterpret_cast<char *>(position.link) - 0x280);
        return 0;
    }

    Product *result = construct(argument, storage);
    if (result == storage) {
        char *base = this ? reinterpret_cast<char *>(this) - 0x0C : 0;
        Product *owner = *reinterpret_cast<Product **>(base + 4);
        Link *ownerLink = owner
            ? reinterpret_cast<Link *>(reinterpret_cast<char *>(owner) + 0x280)
            : 0;
        Link *storageLink = storage
            ? reinterpret_cast<Link *>(reinterpret_cast<char *>(storage) + 0x280)
            : 0;
        insert(storageLink, position, ownerLink);
    }

    return result;
}
