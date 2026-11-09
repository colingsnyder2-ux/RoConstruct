// from server: 83% by atomic.potato
struct Weld
{
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_80;

    void set();
};

extern "C" void __declspec(noreturn) Weld_set_tail();

void Weld::set()
{
    field_0 = 0xbc6674;
    field_4 = 0xbc6668;
    field_18 = 0xbc665c;
    field_1c = 0xbc6650;
    field_80 = 0xbc6624;
    Weld_set_tail();
}
