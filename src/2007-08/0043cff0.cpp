// from server: 43% by colin
struct VVector3 {
    float x;
    float y;
    float z;
};

struct EnumDescriptor {
    void* vtable;
    int pad[0x114/4 - 1];
    void* field114;
    void* field118;
    int convertToValue(int index, void* value) const;
};

struct Item {
    int convertToValue(void* value) const;
};

extern "C" void __stdcall sub_439850(void* dst, int val);
extern "C" void __stdcall sub_5595A0(void* p);

int Item::convertToValue(void* value) const
{
    EnumDescriptor* ed = *(EnumDescriptor**)((char*)this + 0x114);
    int idx = *(int*)((char*)ed + 0x188);
    sub_439850((void*)((char*)this + 0x0), idx);
    void* p = value;
    void* q = 0;
    if (p != 0)
        q = (char*)p + 4;
    void* r = *(void**)((char*)this + 0x118);
    void* s = *(void**)((char*)r + 0x18);
    void* t = *(void**)s;
    void* u = *(void**)((char*)t + 4);
    ((void (__thiscall*)(void*, void*, void*))u)(s, value, q);
    sub_5595A0((void*)((char*)this + 0x0));
    return (int)value;
}
