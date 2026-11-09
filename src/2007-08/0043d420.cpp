// from server: 38% by colin
struct EnumDescriptor {
    char pad[0x188];
    int value;
};

struct Type {
    void* vtable;
    void convertToValue(void* a, void* b);
};

struct PropertyGridItem {
    char pad[0x11c];
    EnumDescriptor* enumDesc;
    Type* type;
    void setValue(void* value, void* variant);
};

void __stdcall sub_439850(void* dest, int src);
void __stdcall sub_5595a0(void* p);

void PropertyGridItem::setValue(void* value, void* variant)
{
    void* local;
    sub_439850(&local, enumDesc->value);
    void* v = 0;
    if (value) {
        v = (char*)value + 4;
    }
    void* val = *(void**)variant;
    type->convertToValue(v, val);
    sub_5595a0(&local);
}
