// from server: 100% by king_originala
struct Entry {
    unsigned int data[2];
};

struct Storage {
    unsigned char padding[12];
    Entry* begin;
    Entry* end;
};

struct Object {
    unsigned char padding[264];
    Storage* storage;
};

int __cdecl hasEntries(Object* object)
{
    Storage* storage = object->storage;
    unsigned int count = storage ? storage->end - storage->begin : 0;
    return count > 0;
}
