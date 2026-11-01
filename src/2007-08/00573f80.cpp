// from server: 100% by colin
struct Primitive;

struct PartInstance {
    char pad[0x1d8];
    Primitive* primitive;
    Primitive* getPrimitive();
};

struct Primitive {
    char pad0[0x64];
    int field64;
    char pad1[0x84 - 0x68];
    int field84;
    void method530100();
};

Primitive* PartInstance::getPrimitive()
{
    Primitive* p = primitive;
    Primitive* q = (Primitive*)p->field64;
    q->method530100();
    return (Primitive*)((char*)q + 0x84);
}
