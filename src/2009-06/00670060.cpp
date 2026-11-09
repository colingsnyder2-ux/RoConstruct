// from server: 100% by why2
struct RBX_Primitive {
    int get(int index);
    char pad[0xa4];
    int* data;
};

int RBX_Primitive::get(int index) {
    return data[index];
}
