// from server: 100% by colin
struct G3D_DialogTemplate {
    char pad[0x6c];
    unsigned int flags;
    char pad2[0x110 - 0x70];
    void* field_110;
    char pad3[0x11c - 0x114];
    unsigned char byte_11c;
};

extern "C" void* __stdcall sub_0072d160(void*, void*, void*);

void G3D_DialogTemplate_method(G3D_DialogTemplate* self, void* a, void* b, void* c)
{
    if ((self->byte_11c & 0x20) != 0) {
        unsigned int v = self->flags & 0x300;
        if (v != 0x300)
            goto do_call;
        return;
    } else {
        if ((self->flags & 0x800) != 0)
            return;
    }
do_call:
    self->field_110 = sub_0072d160(self->field_110, a, b);
}
