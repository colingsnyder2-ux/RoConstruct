// from server: 100% by colin
struct ChatEnter {
    ChatEnter* construct();
};

extern char G1_007b1e64;
extern char G2_007b1e58;
extern char G3_007b1e50;
extern char G4_007b1e40;
extern char G5_007b1e30;
extern char G6_007b1e20;
extern char G7_007b1e10;
extern char G8_007b1e00;
extern char G9_007b1df0;
extern char G10_007b1de8;

void func_0059cf50();

ChatEnter* ChatEnter::construct()
{
    func_0059cf50();
    *(void**)((char*)this + 0) = &G1_007b1e64;
    *(void**)((char*)this + 4) = &G2_007b1e58;
    *(void**)((char*)this + 0x10) = &G3_007b1e50;
    *(void**)((char*)this + 0x14) = &G4_007b1e40;
    *(void**)((char*)this + 0x2c) = &G5_007b1e30;
    *(void**)((char*)this + 0x44) = &G6_007b1e20;
    *(void**)((char*)this + 0x5c) = &G7_007b1e10;
    *(void**)((char*)this + 0x74) = &G8_007b1e00;
    *(void**)((char*)this + 0x8c) = &G9_007b1df0;
    *(void**)((char*)this + 0xe8) = &G10_007b1de8;
    *(int*)((char*)this + 0x118) = 1;
    return this;
}
