// from server: 52% by colin
// roc 2012-06 004654b0  unit: VCRenderSettingsItem::?$FactoryProduct  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004654b0

void* __cdecl sub_98211a(unsigned int size);
void __cdecl sub_982114(void* p);

extern void* g_vtable;

struct Creator {
    void* vtable;
    void* field4;
    void* field8;
    void* fieldC;
};

void* __cdecl makeCreator(void** out, void* a1, void* a2, void* a3)
{
    Creator* c = (Creator*)sub_98211a(0x10);
    if (c != 0) {
        c->vtable = &g_vtable;
        c->field4 = a1;
        c->field8 = a2;
        c->fieldC = a3;
    } else {
        c = 0;
    }
    *out = c;
    sub_982114(0);
    return out;
}
