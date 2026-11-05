// from server: 32% by colin
struct Primitive;

struct BuoyancyContact {
    BuoyancyContact(Primitive* p0, Primitive* p1);
};

struct BuoyancyBallContact : BuoyancyContact {
    float crossSectionArea;
    BuoyancyBallContact(Primitive* p0, Primitive* p1);
};

extern "C" void* __cdecl sub_98211a(unsigned int size);
extern "C" void* __cdecl sub_62e740();
extern "C" void* __cdecl sub_894170();
extern "C" void __cdecl sub_966370(void* a, void* b, void* c);
extern "C" void __cdecl sub_92d3c0(void* a, void* b);

BuoyancyBallContact::BuoyancyBallContact(Primitive* p0, Primitive* p1)
    : BuoyancyContact(p0, p1)
{
    void* mem = sub_98211a(0x90);
    void* obj = 0;
    if (mem) {
        void* a = sub_62e740();
        void* b = sub_894170();
        void* c = sub_894170();
        sub_966370(mem, c, b);
        obj = mem;
    }
    void* tmp = obj;
    sub_92d3c0((char*)this + 0x2c, &tmp);
}
