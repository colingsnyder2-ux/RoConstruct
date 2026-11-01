// from server: 100% by king_originala
struct Pair {
    int first;
    int second;
};

struct Object {
    char padding[0x134];
    int* virtualBaseTable;
};

typedef Pair* (__thiscall *Getter)(void*, Pair*);

struct ArrowPanel {
    Pair cached;
    bool dirty;
    Object* object;
    Getter getter;
    int adjustment;
    int virtualBaseOffset;

    Pair get();
};

Pair ArrowPanel::get()
{
    if (dirty) {
        Pair temporary;
        cached = *getter(
            reinterpret_cast<char*>(object) +
            (*reinterpret_cast<int*>(
                reinterpret_cast<char*>(object->virtualBaseTable) +
                virtualBaseOffset) + adjustment) + 0x134,
            &temporary);
        dirty = false;
    }
    return cached;
}
