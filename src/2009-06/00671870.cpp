// from server: 100% by why2
struct RBX_Backpack {
    int get_0x238(int* out);
};

int RBX_Backpack::get_0x238(int* out) {
    *out = *(int*)((char*)this + 0x238);
    return (int)out;
}
