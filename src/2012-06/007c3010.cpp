// from server: 62% by Intel
struct VMegaClusterInstance {
    int FactoryProduct();
};

extern "C" void __stdcall sub_751750();

int VMegaClusterInstance::FactoryProduct() {
    extern unsigned char byte_E31ABE;
    extern int dword_E4CEA0;

    if (byte_E31ABE) {
        return dword_E4CEA0;
    }

    int v1 = *(int *)((char *)this + 0x84);
    int v2 = *(int *)v1;
    sub_751750();
    return 0;
}
