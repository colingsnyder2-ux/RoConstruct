// from server: 40% by Intel
struct VForceFieldFactoryProductCreator {
    void __cdecl create(void* out);
};

void VForceFieldFactoryProductCreator::create(void* out) {
    static int init1 = 0;
    static int init2 = 0;
    static int data1[3];
    static int data2[3];

    if (!init1) {
        init1 = 1;
        data1[0] = 0x7FFFFFFF;
        data1[1] = 0x7FFFFFFF;
        data1[2] = 0x7FFFFFFF;
    }
    *static_cast<int*>(out) = data1[0];
    *reinterpret_cast<int*>(static_cast<char*>(out) + 4) = data1[1];
    *reinterpret_cast<int*>(static_cast<char*>(out) + 8) = data1[2];

    if (!init2) {
        init2 = 1;
        data2[0] = 0x80000000;
        data2[1] = 0x80000000;
        data2[2] = 0x80000000;
    }
    *reinterpret_cast<int*>(static_cast<char*>(out) + 12) = data2[0];
    *reinterpret_cast<int*>(static_cast<char*>(out) + 16) = data2[1];
    *reinterpret_cast<int*>(static_cast<char*>(out) + 20) = data2[2];
}
