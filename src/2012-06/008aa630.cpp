// from server: 100% by Intel
struct ConstraintSurfacePair {
    int* vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;

    ConstraintSurfacePair* ctor(int a1, int a2, int a3, int a4);
};

ConstraintSurfacePair* ConstraintSurfacePair::ctor(int a1, int a2, int a3, int a4) {
    this->vtable = (int*)0xBE0658;
    this->field4 = a1;
    this->field8 = a3;
    this->fieldC = *(int*)a2;
    this->field10 = *(int*)a4;
    this->vtable = (int*)0xBE0688;
    return this;
}
