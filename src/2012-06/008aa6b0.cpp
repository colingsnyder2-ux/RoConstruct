// from server: 73% by Intel
struct ConstraintSurfacePair {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    ConstraintSurfacePair* initialize(int a1, int a2, int a3, int a4);
};

ConstraintSurfacePair* ConstraintSurfacePair::initialize(int a1, int a2, int a3, int a4) {
    this->field_4 = a1;
    this->vftable = (void*)0x00BE0658;
    this->field_8 = a4;
    int v5 = *(int*)a2;
    int v6 = *(int*)a3;
    this->field_C = v5;
    this->field_10 = v6;
    this->vftable = (void*)0x00BE06A8;
    return this;
}
