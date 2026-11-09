// from server: 100% by king_originala
struct Vector {
    float x, y, z;
};

struct Geometry {
    virtual void slot0();
    virtual ~Geometry();
    virtual int getType();

    float x, y, z;
};

struct Primitive;

struct Observer {
    void notify(Primitive*);
};

Geometry* __cdecl createGeometry(int);

struct Primitive {
    char reserved0[0x58];
    Observer* observer;
    char reserved1[0x40];
    Geometry* geometry;
    char reserved2[0x50];
    unsigned char changed;

    void setVector(const Vector&);
    void func_005e86f0(int);
};

void Primitive::func_005e86f0(int type)
{
    if (geometry->getType() != type) {
        Vector saved;
        saved.x = geometry->x;
        saved.y = geometry->y;
        saved.z = geometry->z;

        delete geometry;
        geometry = createGeometry(type);

        if (observer)
            observer->notify(this);

        setVector(saved);
        changed = 1;
    }
}
