// from server: 100% by colin
struct type_info {
    bool operator==(const type_info&) const;
};

struct VNullTool {
    char pad[0xc];
    void* field_c;
    bool isEnabled() const;
};

struct VNullToolInner {
    char pad[0x188];
    void* field_188;
};

struct VNullToolInner2 {
    char pad[0x318];
    void* field_318;
};

extern "C" void* __cdecl sub_631392(void*);
extern "C" bool (__thiscall *sub_77e708)(void*, const type_info*);
extern type_info type_info_8a570c;

bool VNullTool::isEnabled() const {
    VNullToolInner* p = *(VNullToolInner**)((char*)field_c + 0x188);
    VNullToolInner2* q = *(VNullToolInner2**)((char*)p + 0x318);
    if (q) {
        void* r = sub_631392(q);
        return sub_77e708(&type_info_8a570c, (const type_info*)r);
    }
    return false;
}
