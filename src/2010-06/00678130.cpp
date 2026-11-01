// from server: 100% by tester
struct RBX_Primitive {
    int get(int index);
    char pad[0x98];
    int* data;
};

int RBX_Primitive::get(int index) {
    return data[index];
}