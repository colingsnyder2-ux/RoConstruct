// from server: 100% by tester
struct FactoryProduct {
    int method_00442bb0(int, int);
    int method_00442c60(int, int);
};

int FactoryProduct::method_00442c60(int a, int b) {
    int p = *(int*)((char*)this + 0x94);
    if (p != 0) {
        return ((FactoryProduct*)p)->method_00442bb0(a, b);
    }
    return 0;
}
