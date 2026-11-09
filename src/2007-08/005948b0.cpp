// from server: 100% by colin
struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

extern "C" void* __cdecl sub_631392(void*);

extern type_info type_info_8a5014_;

extern "C" bool (__thiscall *sub_77e708)(const type_info*, const type_info*);

struct VHingeTool_TToolVerb {
    char pad[0xc];
    void* field_c;
    bool isEnabled() const;
};

bool VHingeTool_TToolVerb::isEnabled() const {
    void* p = *(void**)((char*)field_c + 0x188);
    void* q = *(void**)((char*)p + 0x318);
    if (q) {
        void* r = sub_631392(q);
        return sub_77e708(&type_info_8a5014_, (const type_info*)r);
    }
    return false;
}
