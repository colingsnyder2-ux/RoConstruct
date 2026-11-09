// from server: 100% by atomic.potato
// roc 2009-12 0076fd60  unit: RBX::VGuiImageButton::?$FactoryProduct  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076fd60
//
// 0076fd60  8b442404             mov eax, dword ptr [esp + 4]
// 0076fd64  83f801               cmp eax, 1
// 0076fd67  7d07                 jge 0x76fd70
// 0076fd69  b801000000           mov eax, 1
// 0076fd6e  eb0a                 jmp 0x76fd7a
// 0076fd70  83f80a               cmp eax, 0xa
// 0076fd73  7e05                 jle 0x76fd7a
// 0076fd75  b80a000000           mov eax, 0xa
// 0076fd7a  398178010000         cmp dword ptr [ecx + 0x178], eax
// 0076fd80  7413                 je 0x76fd95
// 0076fd82  898178010000         mov dword ptr [ecx + 0x178], eax
// 0076fd88  c74424041883b900     mov dword ptr [esp + 4], 0xb98318
// 0076fd90  e9ebc2c9ff           jmp 0x40c080
// 0076fd95  c20400               ret 4
// library rbxgs/vgui/VGuiImageButton.cpp (function ?setSlice@VGuiImageButton@RBX@@QAEXH@Z)

extern "C" void __stdcall sub_40c080(int);

struct VGuiImageButton {
    char pad[0x178];
    int field_0x178;
    void setSlice(int value);
};

void VGuiImageButton::setSlice(int value) {
    if (value < 1) {
        value = 1;
    } else if (value > 10) {
        value = 10;
    }
    if (this->field_0x178 != value) {
        this->field_0x178 = value;
        sub_40c080(0xb98318);
    }
}
