// from server: 100% by king_originala
extern unsigned char flag89;
extern unsigned char flag8a;
extern unsigned char flag8b;
extern unsigned char flag8c;
extern unsigned char flag8d;
extern unsigned char flag8e;
extern unsigned char flag8f;

typedef bool (__thiscall *Callback)(void *);

struct Object {
    char padding[0x134];
    int *table;
};

struct S {
    char padding0[0x10];
    int state;
    char padding1[0x1d0];
    bool cached;
    bool dirty;
    char padding2[2];
    Object *object;
    Callback callback;
    int adjustment;
    int tableOffset;

    int f();
};

int S::f()
{
    if (state == 2)
        return 1;

    if (dirty) {
        cached = callback(
            reinterpret_cast<char *>(object) + 0x134 +
            *reinterpret_cast<int *>(
                reinterpret_cast<char *>(object->table) + tableOffset) +
            adjustment);
        dirty = false;
    }

    if (cached || flag89 || flag8a || flag8b ||
        flag8d || flag8c || flag8e || flag8f)
        return 1;

    return 0;
}
