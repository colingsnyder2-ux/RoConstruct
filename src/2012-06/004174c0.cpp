// from server: 74% by atomic.potato
extern "C" void __fastcall sub_009826FC(void*);

struct ChatEnter {
    char pad_0000[0x88];
    int field_0088;
    int field_008C;
    int field_0090;
    int field_0094;
    int field_0098;
    int field_009C;
    int field_00A0;
    int field_00A4;
    int field_00A8;
    ChatEnter();
};

ChatEnter::ChatEnter()
{
    sub_009826FC(this);
    field_0088 = 0;
    *(int*)this = 0xb461d4;
    field_008C = 0;
    field_0090 = 0;
    field_0098 = 0;
    field_0094 = 0xb45fb0;
    field_009C = 0;
    field_00A0 = 0;
    field_00A4 = 0;
    field_00A8 = 0;
}
