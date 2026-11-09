// from server: 43% by colin
struct Sub1 {
    void ctor();
};

struct Sub2 {
    void ctor();
};

struct EventData {
    char pad0[0x2cc];
    Sub1 sub1;
    char pad1[0x18];
    Sub2 sub2;
    char pad2[0x18];
    int f304;
    int f308;
    int f30c;
    int f310;
    int f314;

    EventData();
};

extern "C" void __stdcall base_ctor();
extern "C" void __stdcall sub1_ctor();
extern "C" void __stdcall sub2_ctor();

EventData::EventData()
{
    base_ctor();
    sub1.ctor();
    sub2.ctor();
    *(int*)this = 0x792224;
    *(int*)((char*)this + 0x2cc) = 0x792210;
    *(int*)((char*)this + 0x2e8) = 0x7921fc;
    f304 = 0;
    f308 = 0;
    f30c = 0;
    f310 = 0;
    f314 = 0;
}
