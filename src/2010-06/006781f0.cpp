// from server: 100% by tester
struct RBX_Primitive {
    char pad[0xb4];
    int* data;
    int count;
    int get();
};

int RBX_Primitive::get() {
    if (count > 0)
        return *data;
    return 0;
}
