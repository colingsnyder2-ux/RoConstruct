// from server: 100% by Intel
struct VObjectValueFactoryProductCreator {
    void* vtable;
    void method();
};

extern "C" void __stdcall sub_A7C0E2();

void VObjectValueFactoryProductCreator::method() {
    if (vtable != 0) {
        sub_A7C0E2();
    }
}
