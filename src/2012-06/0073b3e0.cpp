// from server: 38% by Intel
struct String {
    char _buf[28];
};

extern "C" void __stdcall String_ctor_copy(String*, const String&);
extern "C" void __stdcall String_dtor(String*);

struct VTableBase {
    void (__thiscall *func4)(void*, String*);
};

struct VButton {
    char pad[0x80];
    VTableBase* vtable;

    String* FactoryProduct(int, int, int, int, int, int, int, String* outStr);
};

String* VButton::FactoryProduct(int, int, int, int, int, int, int, String* outStr)
{
    String temp;
    String_ctor_copy(&temp, *reinterpret_cast<const String*>(&outStr));
    VTableBase* vt = this->vtable;
    void (__thiscall *func)(void*, String*) = vt->func4;
    func(this, &temp);
    String_dtor(&temp);
    return outStr;
}
