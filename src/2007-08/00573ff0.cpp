// from server: 100% by colin
struct Primitive;

struct PartInstance {
    char pad[0x1d8];
    Primitive* primitive;
    void* getPrimitiveSomething();
};

struct Primitive {
    char pad[0x64];
    void* field64;
    char pad2[0xc0 - 0x68];
    char fieldC0;
};

struct Caller00530100 {
    void m();
};

extern Caller00530100 G00530100;

void* PartInstance::getPrimitiveSomething()
{
    Primitive* p = *(Primitive**)((char*)this + 0x1d8);
    void* q = *(void**)((char*)p + 0x64);
    ((Caller00530100*)q)->m();
    return (char*)q + 0xc0;
}
