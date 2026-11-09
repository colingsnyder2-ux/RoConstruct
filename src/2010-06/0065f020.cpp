// from server: 100% by atomic.potato
struct RBX_Backpack {
    void set_0xA4(int* value);
};

void RBX_Backpack::set_0xA4(int* value) {
    if (*(unsigned char*)((char*)this + 0x94) != 0)
        *(int*)((char*)this + 0xA4) = *value;
}
