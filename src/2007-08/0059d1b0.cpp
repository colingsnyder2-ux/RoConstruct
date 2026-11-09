// from server: 100% by colin
struct ChatEnter {
    char pad[0x100];
    void sub_59D0D0();
    ChatEnter* construct();
};

ChatEnter* ChatEnter::construct() {
    sub_59D0D0();
    *(int*)((char*)this + 0x00) = 0x7b1b54;
    *(int*)((char*)this + 0x04) = 0x7b1b48;
    *(int*)((char*)this + 0x10) = 0x7b1b40;
    *(int*)((char*)this + 0x14) = 0x7b1b30;
    *(int*)((char*)this + 0x2c) = 0x7b1b20;
    *(int*)((char*)this + 0x44) = 0x7b1b10;
    *(int*)((char*)this + 0x5c) = 0x7b1b00;
    *(int*)((char*)this + 0x74) = 0x7b1af0;
    *(int*)((char*)this + 0x8c) = 0x7b1ae0;
    *(int*)((char*)this + 0xe8) = 0x7b1ad8;
    return this;
}
