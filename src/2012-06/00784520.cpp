// from server: 83% by colin
struct EnumDesc {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x90 - 0x30];
    const char** names;
    bool get(unsigned int index, const char** out) const;
};

extern "C" void __cdecl sub_4015A0(const char*, const char*);
extern "C" int __cdecl sub_770200();
extern "C" void __cdecl sub_7697A0(const char**);

bool EnumDesc::get(unsigned int index, const char** out) const {
    bool found;
    const char* name;
    if (index < count) {
        name = names[index];
        found = true;
    } else {
        found = false;
    }
    sub_4015A0((const char*)0xe48588, (const char*)0x770260);
    int v = sub_770200();
    *out = (const char*)v;
    sub_7697A0(&name);
    return found;
}
