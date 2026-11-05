// from server: 44% by atomic.potato
struct VWorkspaceRefPropDescriptor {
    void* vtable0;
    void* vtable4;
    char pad8[0x10];
    void* vtable18;
    void* vtable1c;
    char pad20[0x88];
    void* field_a8;
    char field_b0;
    void construct(void* arg);
};

extern "C" void __stdcall sub_46be00();

void VWorkspaceRefPropDescriptor::construct(void* arg)
{
    sub_46be00();
    this->vtable0 = (void*)0xb79b94;
    this->vtable4 = (void*)0xb79b88;
    this->vtable18 = (void*)0xb79b7c;
    this->vtable1c = (void*)0xb79b70;
    this->field_a8 = 0;
    if (arg == 0) {
        this->field_a8 = arg;
        void** vt = *(void***)arg;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[0];
        fn(arg, &this->field_b0, 0);
    }
    void* p = this->field_a8;
    if (p != 0) {
        void** vt = *(void***)p;
        if (vt[0] != 0) {
            void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[0];
            fn(p, &p, 2);
        }
    }
}
