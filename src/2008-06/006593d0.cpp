// from server: 100% by king_originala
struct Box {
    int minX, minY, minZ;
    int maxX, maxY, maxZ;
};

struct Level {
    char padding[0x20];
    unsigned short value;
};

struct Node {
    char padding[0x64];
    Level* level;
    Box box;
};

bool __cdecl intersects(const Box* a, const Box* b);
void __cdecl convertBox(Box* result, int fromLevel, int toLevel, const Box* source);

bool __stdcall overlaps(Node* a, Node* b)
{
    Box converted;

    if (!a->level || !b->level)
        return false;

    int firstLevel = a->level->value;
    int secondLevel = b->level->value;

    if (firstLevel == secondLevel)
        return intersects(&a->box, &b->box);

    Node* larger;
    if (firstLevel > secondLevel) {
        larger = a;
    } else {
        larger = b;
        if (b != a)
            b = a;
    }

    convertBox(&converted, b->level->value, larger->level->value, &b->box);
    return intersects(&larger->box, &converted);
}
