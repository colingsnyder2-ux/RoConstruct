// from server: 60% by atomic.potato
struct RbxManualResourceLoaderChain {
    void* vtable;
    void* field_4;
    void* field_8;
    void* destroy(char);
};

void __stdcall sub_7f385a(void*);

void* RbxManualResourceLoaderChain::destroy(char flag) {
    this->vtable = (void*)0x9b3e9c;
    void* p = (char*)this + 4;
    if (p != 0) {
        *(void**)p = (char*)p - 4;
    } else {
        *(void**)p = 0;
    }
    this->vtable = *(void**)0x98c060;
    if (flag & 1) {
        sub_7f385a(this);
    }

    return this;
}
