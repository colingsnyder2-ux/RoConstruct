// from server: 34% by Intel
struct TypeInfo {
    int vftable;
};

extern "C" int __stdcall type_info_equal(const TypeInfo*, const TypeInfo*);

struct String {
    char _pad[28];
};

extern "C" void __stdcall string_ctor(String*, const char*);

extern "C" void __cdecl raise_exception(void*);

struct EventDesc {
    TypeInfo* type;

    void func_0055f050(int arg);
};

void EventDesc::func_0055f050(int arg)
{
    TypeInfo* eax = this->type;
    TypeInfo* ecx;

    if (eax)
        ecx = reinterpret_cast<TypeInfo*>(eax->vftable);
    else
        ecx = reinterpret_cast<TypeInfo*>(0x00D60AC8);

    if (ecx != reinterpret_cast<TypeInfo*>(0x00D881C0)) {
        TypeInfo* eax2;
        if (eax)
            eax2 = reinterpret_cast<TypeInfo*>(eax->vftable);
        else
            eax2 = reinterpret_cast<TypeInfo*>(0x00D60AC8);

        type_info_equal(eax2, reinterpret_cast<TypeInfo*>(0x00D881C0));
    }

    String str;
    string_ctor(&str, "bad cast");
    raise_exception(&str);
}
