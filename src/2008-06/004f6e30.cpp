// from server: 100% by king_originala
extern unsigned char baseTable[];
extern unsigned char derivedTable[];

struct Handle {
    void* value;
    void assign(void* p);
};

struct S {
    unsigned long table;
    float x, y, z;
    unsigned long flags;
    Handle handle;
    float a, b, c;

    S(const S& other);
};

S::S(const S& other)
{
    table = reinterpret_cast<unsigned long>(baseTable);
    x = other.x;
    y = other.y;
    z = other.z;
    flags = other.flags;
    handle.value = 0;
    handle.assign(other.handle.value);
    a = other.a;
    *reinterpret_cast<volatile float*>(&b) = other.b;
    *reinterpret_cast<volatile unsigned long*>(&table) =
        reinterpret_cast<unsigned long>(derivedTable);
    c = other.c;
}
