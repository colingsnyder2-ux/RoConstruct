// from server: 100% by why2
struct RBX_Mechanism {
    char pad[0xb0];
    int* field_b0;
    int get_78();
};

int RBX_Mechanism::get_78() {
    int* p = field_b0;
    int* q = (int*)*p;
    return *(int*)((char*)q + 0x78);
}
