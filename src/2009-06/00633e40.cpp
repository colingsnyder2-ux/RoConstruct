// from server: 100% by why2
struct FactoryProduct {
    int get() const;
    char pad[0x8c];
    void* field_8c;
};

int FactoryProduct::get() const {
    void* p = field_8c;
    if (p != 0) {
        return **(int**)((char*)p - 0xc);
    }
    return 0;
}
