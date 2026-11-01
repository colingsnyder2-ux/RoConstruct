// from server: 52% by atomic.potato
struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

struct VBrickColor_PropertyDescriptor {
    void* field0;
    void* getTypeInfo();
};

extern "C" void* __stdcall sub_98B768(void*, void*);

void* __fastcall sub_6428D0(VBrickColor_PropertyDescriptor* self)
{
    if (self == 0)
        return 0;

    void* ti;
    if (self->field0 != 0) {
        void** vtbl = *(void***)self->field0;
        void* (*fn)(void*) = (void* (*)(void*))vtbl[1];
        ti = fn(self->field0);
    } else {
        ti = (void*)0x00B0030C;
    }

    if (sub_98B768(ti, (void*)0x00B033DC) == 0)
        return 0;

    return (char*)self->field0 + 8;
}
