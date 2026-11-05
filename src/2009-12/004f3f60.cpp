// from server: 13% by atomic.potato
struct GfxBinding;

struct GfxAttachement {
    void* vftable;
    char pad0[0xc];
    int field10;
    char pad1[0x4];
    void* field18;
    char pad2[0x4];
    void* field20;
    char pad3[0x14];
    void* field38;
    void* field3c;
    void* field40;
    void* field44;
};

extern "C" void __stdcall sub_41ae90();
extern "C" char __stdcall sub_4f4a10(void*, void*, void*);

void GfxAttachement_ctor(GfxAttachement* self, void* a, void* b, void* c)
{
    sub_41ae90();
    self->vftable = (void*)0x9b0528;
    self->field10 = (int)c;
    self->field18 = 0;
    char ok = sub_4f4a10((void*)0xb125f8, a, b);
    if (ok) {
        self->field18 = (void*)0xb125f8;
    } else {
        self->field18 = 0;
    }
    self->field38 = 0;
    self->field3c = 0;
    self->field40 = 0;
    self->field44 = 0;
}
