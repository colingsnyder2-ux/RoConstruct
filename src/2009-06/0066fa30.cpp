// from server: 100% by why2
struct RBX_Geometry {
    char pad[0xe4];
    void* field_e4;
    char get_byte_at_3c();
};

char RBX_Geometry::get_byte_at_3c() {
    return *(char*)((char*)field_e4 + 0x3c);
}
