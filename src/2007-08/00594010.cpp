// from server: 100% by colin
// roc 2007-08 00594010  unit: RBX::VResizeTool::?$TToolVerb  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00594010

extern "C" int __cdecl sub_631392(int);
extern "C" bool (__thiscall *off_77E708)(int, int);

struct type_info;

struct Verb {
    char pad[0xc];
    void* container;
};

struct VerbContainer {
    char pad[0x188];
    void* dataModel;
};

struct DataModel {
    char pad[0x318];
    void* something;
};

struct TToolVerb {
    bool isEnabled() const;
};

bool TToolVerb::isEnabled() const {
    Verb* self = (Verb*)this;
    VerbContainer* c = *(VerbContainer**)((char*)self + 0xc);
    DataModel* dm = *(DataModel**)((char*)c + 0x188);
    void* p = *(void**)((char*)dm + 0x318);
    if (p) {
        int r = sub_631392((int)p);
        return off_77E708(0x8a4bc8, r);
    }
    return false;
}
