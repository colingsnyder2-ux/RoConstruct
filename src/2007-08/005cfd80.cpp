// from server: 70% by atomic.potato
// roc 2007-08 005cfd80  unit: RBX::VLocalBackpack::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cfd80
//
// 005cfd80  a6                   cmpsb byte ptr [esi], byte ptr es:[edi]
// 005cfd81  7b00                 jnp 0x5cfd83
// 005cfd83  c7462cbca67b00       mov dword ptr [esi + 0x2c], 0x7ba6bc
// 005cfd8a  c74644aca67b00       mov dword ptr [esi + 0x44], 0x7ba6ac
// 005cfd91  c7465c9ca67b00       mov dword ptr [esi + 0x5c], 0x7ba69c
// 005cfd98  c746748ca67b00       mov dword ptr [esi + 0x74], 0x7ba68c
// 005cfd9f  c7868c0000007ca67b00 mov dword ptr [esi + 0x8c], 0x7ba67c
// 005cfda9  c786e800000074a67b00 mov dword ptr [esi + 0xe8], 0x7ba674
// 005cfdb3  8bc6                 mov eax, esi
// 005cfdb5  5e                   pop esi
// 005cfdb6  c3                   ret 

struct RBX_VLocalBackpack_FactoryProduct
{
    char pad[0x2c];
    void* field_0x2c;
    char pad2[0x14];
    void* field_0x44;
    char pad3[0x14];
    void* field_0x5c;
    char pad4[0x14];
    void* field_0x74;
    char pad5[0x14];
    void* field_0x8c;
    char pad6[0x58];
    void* field_0xe8;
};

extern char G_007ba6bc;
extern char G_007ba6ac;
extern char G_007ba69c;
extern char G_007ba68c;
extern char G_007ba67c;
extern char G_007ba674;

RBX_VLocalBackpack_FactoryProduct* func_005cfd80(RBX_VLocalBackpack_FactoryProduct* self)
{
    self->field_0x2c = &G_007ba6bc;
    self->field_0x44 = &G_007ba6ac;
    self->field_0x5c = &G_007ba69c;
    self->field_0x74 = &G_007ba68c;
    self->field_0x8c = &G_007ba67c;
    self->field_0xe8 = &G_007ba674;
    return self;
}
