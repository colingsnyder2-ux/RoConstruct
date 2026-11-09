// from server: 41% by colin
struct EventData {
    char pad0[0x2cc];
    int field2cc;
    char pad2d0[0x18];
    int field2e8;
    char pad2ec[0x18];
    int field304;
    int field308;
    char field30c;
    EventData();
};

extern "C" void __stdcall sub_651ff0();
extern "C" void __stdcall sub_41e050();
extern "C" void __stdcall sub_41e120();

EventData::EventData()
{
    sub_651ff0();
    field2cc = 0;
    sub_41e050();
    field2e8 = 0;
    sub_41e120();
    *(int*)this = 0x787fcc;
    field2cc = 0x787fb4;
    field2e8 = 0x787fa0;
    field304 = 0;
    field308 = 0;
    field30c = 0;
}
