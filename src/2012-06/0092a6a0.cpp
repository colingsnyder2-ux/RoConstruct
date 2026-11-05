// from server: 46% by Intel
struct EdgeEdgePair {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
};

extern "C" int __stdcall sub_4D7560(int);
extern "C" int __stdcall sub_8A8850(int, int);

int __stdcall EdgeEdgePair_ctor(EdgeEdgePair* this_, int a2, int a3, int a4) {
    this_->vftable = (void*)0xBFDB74;
    this_->field_C = *(int*)a2;
    this_->field_10 = *(int*)(a2 + 4);
    this_->field_14 = *(int*)(a2 + 8);
    this_->field_4 = a3;
    this_->field_8 = a4;
    this_->vftable = (void*)0xBFDC44;
    int v5 = sub_4D7560(*(int*)(a3 + 0x104));
    int v6 = *(int*)(v5 + 0x14);
    int v7 = sub_8A8850(v6 + 0x20, 0);
    this_->field_18 = v7;
    this_->field_1C = 0;
    return (int)this_;
}
