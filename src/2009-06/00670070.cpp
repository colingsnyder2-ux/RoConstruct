// from server: 100% by why2
struct Primitive {
    char pad[0x88];
    int* array;
    int get(int index);
};

int Primitive::get(int index) {
    return array[index];
}
