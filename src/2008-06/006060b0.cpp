// from server: 100% by colin
struct Vector {
    float x, y, z;
};

struct Geometry {
    unsigned char pad0[8];
    unsigned char dirty;
    unsigned char pad1[0x87];
    float x, y, z;

    void update();
};

struct Holder {
    unsigned char pad[0x2C];
    Geometry *geometry;
};

struct S {
    unsigned char pad[0x10];
    Holder *holder;

    void translate(const Vector &offset);
};

void S::translate(const Vector &offset)
{
    Geometry *g = holder->geometry;
    if (g) {
        if (g->dirty)
            g->update();
        g->x = g->x + offset.x;
        g->y = offset.y + g->y;
        g->z = offset.z + g->z;
    }
}
