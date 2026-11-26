// from server: 100% by Xemicl
// from server: 100% by Intel
// roc 2012-06 0053be40  unit: RBX::Network::Player  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0053be40
//
// 0053be40  8a442404             mov al, byte ptr [esp + 4]
// 0053be44  3a81e8000000         cmp al, byte ptr [ecx + 0xe8]
// 0053be4a  7413                 je 0x53be5f
// 0053be4c  8881e8000000         mov byte ptr [ecx + 0xe8], al
// 0053be52  c74424049c0fe200     mov dword ptr [esp + 4], 0xe20f9c
// 0053be5a  e9418fedff           jmp 0x414da0
// 0053be5f  c20400               ret 4

struct Player {
    char padding[0x189];
    unsigned char field_E8;
    void method(unsigned char);
};

extern "C" void __stdcall sub_414DA0(unsigned int);

void Player::method(unsigned char arg) {
    if (arg != field_E8) {
        field_E8 = arg;
        sub_414DA0(0xE20F9C);
    }
}
