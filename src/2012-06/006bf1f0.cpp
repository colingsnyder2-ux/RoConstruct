// from server: 51% by Intel
struct TypeInfo {
    int gap0[4];
    bool (__stdcall *equals)(TypeInfo*, TypeInfo*);
};

extern "C" bool __stdcall type_info_equals(TypeInfo*, TypeInfo*);

struct Descriptor {
    TypeInfo* type;
    int gap4[1];
};

int __cdecl sub_6BF1F0(Descriptor* desc) {
    if (!desc)
        return 0;

    TypeInfo* t = desc->type;
    if (!t)
        t = (TypeInfo*)0xD60AC8;

    if (t != (TypeInfo*)0xD60BD8) {
        return (int)(desc + 1);
    }

    if (!t)
        t = (TypeInfo*)0xD60AC8;

    TypeInfo* target = (TypeInfo*)0xD60BD8;
    if (type_info_equals(t, target)) {
        return (int)(desc + 1);
    }

    return 0;
}
