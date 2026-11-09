// from server: 100% by colin
struct Primitive;

struct PartInstance {
    char pad[0x1d8];
    Primitive* primitive;
    void* getSomething();
};

struct Primitive {
    char pad0[0x64];
    void* field64;
    char pad1[0xa8 - 0x68];
    char fieldA8;
};

struct Caller00530100 {
    void m();
};

void* PartInstance::getSomething()
{
    Primitive* p = *(Primitive**)((char*)this + 0x1d8);
    void* q = *(void**)((char*)p + 0x64);
    ((Caller00530100*)q)->m();
    return (char*)q + 0xa8;
}
