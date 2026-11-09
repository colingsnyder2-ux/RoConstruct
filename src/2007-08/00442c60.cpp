// from server: 100% by colin
struct FactoryProduct {
    int method_00442bb0(int, int);
    int method_00442c60(int, int);
};

int FactoryProduct::method_00442c60(int a, int b) {
    int p = *(int*)((char*)this + 0xe8);
    if (p != 0) {
        return ((FactoryProduct*)p)->method_00442bb0(a, b);
    }
    return 0;
}
