// from server: 40% by atomic.potato
struct RbxManualResourceLoaderChain {
    void* vfptr;
    void* field_4;
    RbxManualResourceLoaderChain* field_8;
    void* destroy(char);
};

extern "C" void __stdcall sub_7A799A(void*);

void* RbxManualResourceLoaderChain::destroy(char flag) {
    field_4 = 0;
    field_8 = this;
    vfptr = *(void**)0x9eaf84;
    if (flag & 1) {
        sub_7A799A(this);
    }

    return this;
}
