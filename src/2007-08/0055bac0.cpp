// from server: 48% by Intel
struct VToolFactoryProductCreator {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
};

extern "C" void __stdcall __security_cookie_init(int);
void __cdecl sub_5598a0(VToolFactoryProductCreator*);

VToolFactoryProductCreator* __cdecl sub_55BAC0(VToolFactoryProductCreator* this_) {
    __try {
        this_->vftable = (void*)0x7A8A0C;
        this_->field_4 = -1;
        sub_5598a0(this_);
    }
    __finally {
    }
    return this_;
}
