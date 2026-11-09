// from server: 98% by atomic.potato
struct VPlayers_RefPropDescriptor {
    char pad0[0x94];
    unsigned char field_94;
};

extern "C" void __fastcall sub_67A560(void* self, void* desc);

VPlayers_RefPropDescriptor* __fastcall VPlayers_RefPropDescriptor_ctor(VPlayers_RefPropDescriptor* self, void*)
{
    sub_67A560(self, (void*)0xA3D730);
    self->field_94 = 1;
    *(void**)self = (void*)0xA3D6DC;
    *(void**)((char*)self + 4) = (void*)0xA3D6D4;
    *(void**)((char*)self + 0x18) = (void*)0xA3D6C8;
    *(void**)((char*)self + 0x1C) = (void*)0xA3D6BC;
    return self;
}
