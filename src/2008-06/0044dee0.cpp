// from server: 100% by king_originala
struct Tail {
    unsigned int value;
};

struct Item {
    unsigned int first;
    unsigned int second;
    Tail tail;
};

extern Tail& (__thiscall *assignTail)(Tail*, const Tail*);

Item* __cdecl copyBackward(Item* first, Item* last, Item* result)
{
    if (first != last) {
        do {
            --last;
            --result;
            result->first = last->first;
            result->second = last->second;
            assignTail(&result->tail, &last->tail);
        } while (last != first);
    }
    return result;
}
