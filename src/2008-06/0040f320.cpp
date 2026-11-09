// from server: 100% by king_originala
struct Guid {
    unsigned long a, b, c, d;
};

struct Point;

struct PointTable {
    void* slot0;
    unsigned long (__stdcall *addRef)(Point*);
    void* slot2;
    long (__stdcall *getGuid)(Point*, Guid*);
};

struct Point {
    PointTable* table;
};

long __stdcall function(void* object, const Guid& requested, Point** output)
{
    if (!output)
        return (long)0x80004003UL;

    *output = 0;
    long result = (long)0x80040200UL;

    static int offsets[2];
    static unsigned int initialized;

    if (!(initialized & 1)) {
        initialized |= 1;
        offsets[0] = 4;
        offsets[1] = -1;
    }

    int* entry = offsets;
    while (*entry != -1) {
        if (*entry == -2) {
            typedef int* (__cdecl *GetEntries)(int);
            GetEntries getEntries = (GetEntries)entry[1];
            entry = getEntries(0);
        } else {
            Point* point = (Point*)((char*)object + *entry);
            Guid actual;

            if (point->table->getGuid(point, &actual) >= 0 &&
                requested.a == actual.a &&
                requested.b == actual.b &&
                requested.c == actual.c &&
                requested.d == actual.d) {
                *output = point;
                point->table->addRef(point);
                result = 0;
                break;
            }
            ++entry;
        }
    }

    return result;
}
