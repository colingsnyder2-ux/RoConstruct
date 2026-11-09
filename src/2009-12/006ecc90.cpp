// from server: 73% by atomic.potato
struct RBX_Primitive {
    char pad[0xb4];
    int count_b4;
    int count_b8;
    int get_next(int* other);
};

int RBX_Primitive::get_next(int* other) {
    int idx;
    if (this == (RBX_Primitive*)other[4]) {
        idx = other[6];
    } else {
        idx = other[7];
    }
    idx = idx + 1;
    if (idx < count_b8) {
        return ((int*)count_b4)[idx];
    }
    return 0;
}
