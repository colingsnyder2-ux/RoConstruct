// from server: 65% by Intel
struct VMegaClusterInstance {
    int FactoryProduct();
};

extern "C" void __stdcall sub_751730();

int VMegaClusterInstance::FactoryProduct() {
    if (*(char*)0xE31ABE != 0) {
        return 0xE4D1E0;
    }
    int v1 = *(int*)((char*)this + 0x84);
    int v2 = *(int*)v1;
    sub_751730();
    return 0;
}
