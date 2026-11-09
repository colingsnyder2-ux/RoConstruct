// from server: 73% by atomic.potato
struct VAuthoringSettings {
    void* field_48;

    int BoundPropGetSet();
};

extern "C" int __cdecl sub_80B2EA(void* a1, int a2, int a3, int a4, int a5);

int VAuthoringSettings::BoundPropGetSet() {
    if (!field_48)
        return 0;

    void** data = static_cast<void**>(field_48);
    void** begin = static_cast<void**>(data[1]);
    void** end = static_cast<void**>(data[2]);

    while (begin != end) {
        int result = sub_80B2EA(*begin, 0, 0xC071F8, 0xC09CA8, 0);
        if (result)
            return result;
        begin = reinterpret_cast<void**>(reinterpret_cast<char*>(begin) + 8);
    }

    return 0;
}
