// from server: 100% by colin
// roc 2007-08 0057cf30  unit: RBX::Workspace  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0057cf30

struct Workspace {
    char pad0[4];
    void* field4;
    void* field8;
    void init(void* a, void* b);
};

extern "C" char __cdecl sub_4879D0(void* a);
extern "C" void* __cdecl sub_62FEF6(unsigned int size);

void Workspace::init(void* a, void* b) {
    void* local[2];
    local[0] = a;
    local[1] = b;
    if (sub_4879D0(local) == 0) {
        field8 = (void*)0x57BF90;
        *(void**)this = (void*)0x57BB90;
        void* p = sub_62FEF6(8);
        if (p != 0) {
            *(void**)p = local[0];
            *(void**)((char*)p + 4) = local[1];
        }
        field4 = p;
    }
}
