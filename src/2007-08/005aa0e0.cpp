// from server: 62% by Intel
extern "C" void __cdecl sub_62FC62(void*);

struct VTableBase {
    void* gap0;
    void* gap4;
};

VTableBase vtable_7B5880;
VTableBase vtable_7B5890;

struct SignalDesc {
    const VTableBase* vfptr;
    int field4;
    void* field8;
    int fieldC;
    int field10;

    void dtor1();

    void dtor2();
};

void SignalDesc::dtor1() {
    this->vfptr = &vtable_7B5880;
    if (this->field8) {
        sub_62FC62(this->field8);
    }
    this->field8 = 0;
    this->fieldC = 0;
    this->field10 = 0;
}

void SignalDesc::dtor2() {
    this->vfptr = &vtable_7B5890;
    if (this->field8) {
        sub_62FC62(this->field8);
    }
    this->field8 = 0;
    this->fieldC = 0;
    this->field10 = 0;
}
