// from server: 38% by Intel
struct NodeVisitor {
    void* vfptr;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;

    NodeVisitor* Initialize();
};

extern "C" void* __stdcall sub_50D4B0();

NodeVisitor* NodeVisitor::Initialize() {
    NodeVisitor* this_ptr = this;
    void* vfptr = this_ptr->vfptr;
    int zero = 0;

    if (vfptr != 0) {
        this_ptr->vfptr = *(void**)vfptr;
    } else {
        vfptr = sub_50D4B0();
    }

    if (vfptr == 0) {
        return 0;
    }

    this_ptr->field_8 = zero;
    this_ptr->field_C = zero;
    this_ptr->field_10 = zero;
    this_ptr->field_4 = -1;
    *(short*)&this_ptr->vfptr = 0;
    this_ptr->field_28 = zero;
    this_ptr->field_2C = zero;
    *(char*)&this_ptr->field_24 = 0;

    int val = 0xFFFF0000 | 0xFFFF;
    this_ptr->field_14 = val;
    this_ptr->field_18 = val;
    this_ptr->field_1C = val;
    this_ptr->field_20 = val;

    return this_ptr;
}
