// from server: 100% by atomic.potato
struct type_info {
    bool operator==(const type_info& other) const;
};

struct SubObject {
    char pad[0x188];
    void* field_188;
};

struct Inner {
    char pad[0x318];
    void* field_318;
};

struct Outer {
    char pad[0xc];
    SubObject* field_c;
};

extern "C" void* __cdecl sub_631392(void*);
extern "C" bool (__thiscall *sub_77e708)(const type_info*, void*);

struct VArrowTool {
    bool isEnabled() const;
};

bool VArrowTool::isEnabled() const
{
    Outer* outer = (Outer*)this;
    Inner* inner = (Inner*)outer->field_c->field_188;
    void* p = inner->field_318;
    if (p) {
        void* q = sub_631392(p);
        return sub_77e708((const type_info*)0x8a19c4, q);
    }
    return false;
}
