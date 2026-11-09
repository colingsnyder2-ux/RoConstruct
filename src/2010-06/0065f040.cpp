// from server: 100% by atomic.potato
struct RBX_Backpack {
    void set_0x238(int* value);
};

void RBX_Backpack::set_0x238(int* value) {
    if (*(unsigned char*)((char*)this + 0x94))
        *(int*)((char*)this + 0xa8) = *value;
}
