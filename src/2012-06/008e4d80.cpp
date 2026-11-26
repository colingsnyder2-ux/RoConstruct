// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 0073ae00  unit: RBX::VBasePlayerGui::?$NonFactoryProduct  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0073ae00
//
// 0073ae00  8a442404             mov al, byte ptr [esp + 4]
// 0073ae04  388191000000         cmp byte ptr [ecx + 0x91], al
// 0073ae0a  7413                 je 0x73ae1f
// 0073ae0c  888191000000         mov byte ptr [ecx + 0x91], al
// 0073ae12  c7442404884be300     mov dword ptr [esp + 4], 0xe34b88
// 0073ae1a  e9819fcdff           jmp 0x414da0
// 0073ae1f  c20400               ret 4

// from server: 100% by atomic.potato
// roc 2012-06 007f2c10  unit: RBX::VGuiObject::?$EventDesc  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007f2c10
//
// 007f2c10  8a442404             mov al, byte ptr [esp + 4]
// 007f2c14  3881b0000000         cmp byte ptr [ecx + 0xb0], al
// 007f2c1a  7413                 je 0x7f2c2f
// 007f2c1c  8881b0000000         mov byte ptr [ecx + 0xb0], al
// 007f2c22  c744240424eee400     mov dword ptr [esp + 4], 0xe4ee24
// 007f2c2a  e97121c2ff           jmp 0x414da0
// 007f2c2f  c20400               ret 4

struct EventDesc {
    unsigned char pad[0x3a4];
    unsigned char field_b0;
    void setValue(unsigned char value);
};

extern "C" void __stdcall sub_414da0(const char* value);

void EventDesc::setValue(unsigned char value)
{
    if (field_b0 != value) {
        field_b0 = value;
        sub_414da0((const char*)0x00e4ee24);
    }
}
