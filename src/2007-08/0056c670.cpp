// from server: 100% by colin
struct RBX_StandardOut {
    char pad0[0xc];
    void* field_c;
    void* field_10;
    void* field_14;
    void m();
};

void RBX_StandardOut::m()
{
    if (field_c == 0)
        return;

    if (field_14 != 0) {
        void* p = field_10;
        *(void**)((char*)field_14 + 0x10) = p;
    }

    if (field_10 != 0) {
        void* p = field_14;
        *(void**)((char*)field_10 + 0x14) = p;
    }

    void* p = field_c;
    if (*(void**)p == this) {
        void* q = field_14;
        *(void**)p = q;
    }

    field_14 = 0;
    field_10 = 0;
}
