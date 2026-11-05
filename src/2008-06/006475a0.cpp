// from server: 100% by king_originala
struct Primitive;

struct Geometry {
    Primitive* getFirstA();
    Primitive* getNext(Primitive*);
};

struct Primitive {
    char padding[12];
    Geometry* first;
    Geometry* second;
};

bool __cdecl matches(Geometry*, Geometry*, Primitive*, int);

Geometry* __cdecl findOther(Geometry* source, Geometry* target, int mode)
{
    Primitive* found = 0;
    Primitive* current = source->getFirstA();

    while (current) {
        Geometry* other = current->first;
        if (source == other)
            other = current->second;

        if (matches(source, other, current, mode)) {
            if (other == target)
                found = current;
            else if (found)
                return other;
        }

        current = source->getNext(current);
    }

    return 0;
}
