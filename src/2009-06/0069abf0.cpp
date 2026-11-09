// from server: 100% by why2
struct RBX_VHole_FactoryProduct {
    int get(int* out);
};

int RBX_VHole_FactoryProduct::get(int* out) {
    *out = *(int*)((char*)this + 0x1a0);
    return (int)out;
}
