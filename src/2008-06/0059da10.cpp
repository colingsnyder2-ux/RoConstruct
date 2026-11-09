// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc 2008-06 0059da10  unit: VCRenderSettings::?$EnumPropDescriptor  size: 183 bytes

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    bool operator==(const Vector3& o) const { return x == o.x && y == o.y && z == o.z; }
};

struct Pair {
    Vector3 a;
    Vector3 b;
};

struct DataSource {
    char reserved[0xc4];
    Pair pair;
    const void* get();
    void setValue(const Pair&);
};

extern char descriptor[];

struct S {
    char reserved0[0x2c8];
    DataSource* dataSource;
    void method(const Vector3& value);
    void setValue(const void*);
};

void S::method(const Vector3& value) {
    DataSource* ds = dataSource;
    ds->get();
    Pair local = ds->pair;
    if (local.a == value)
        return;
    local.a = value;
    dataSource->setValue(local);
    setValue(descriptor);
}
