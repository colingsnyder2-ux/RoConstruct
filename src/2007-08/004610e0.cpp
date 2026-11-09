// from server: 33% by colin
struct EventData {
    char pad0[0xec];
    void* field_ec;
    char pad_f0[0x1c];
    void* field_10c;
    char pad_110[0x18];
    void* field_128;
    void* field_12c;
    void* field_130;
    void* field_134;
    void* field_138;
    void* field_13c;
    void* field_140;
    char field_144;
    char field_145;
    char field_146;
    void* field_148;
    void* field_14c;

    EventData();
};

extern "C" void __cdecl sub_45deb0();
extern "C" void __cdecl sub_460a70();
extern "C" void __cdecl sub_460b40();

EventData::EventData()
{
    sub_45deb0();
    field_ec = (void*)0x794a20;
    sub_460a70();
    sub_460b40();
    *(void**)this = (void*)0x794bd4;
    field_ec = (void*)0x794bc8;
    *(void**)((char*)this + 0xf0) = (void*)0x794bb4;
    *(void**)((char*)this + 0x10c) = (void*)0x794ba0;
    field_128 = 0;
    field_12c = 0;
    field_130 = 0;
    field_134 = 0;
    field_138 = 0;
    field_13c = 0;
    field_140 = 0;
    field_144 = 0;
    field_145 = 0;
    field_146 = 0;
    field_14c = 0;
    field_148 = (void*)0x794a08;
}
