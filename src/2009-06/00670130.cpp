// from server: 100% by why2
struct RBX_Primitive {
    char pad[0xa4];
    int* data;
    int count;
    int get();
};

int RBX_Primitive::get() {
    if (count > 0)
        return *data;
    return 0;
}
