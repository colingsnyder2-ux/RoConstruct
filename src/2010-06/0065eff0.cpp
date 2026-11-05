// from server: 100% by tester
struct RBX_Backpack {
    int get_0x238(int* out);
};

int RBX_Backpack::get_0x238(int* out) {
    *out = *(int*)((char*)this + 0xa8);
    return (int)out;
}
