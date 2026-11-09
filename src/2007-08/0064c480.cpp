// from server: 100% by colin
struct CXTPImageManagerIcon {
    char pad[0x30];
    int sub_64b2c0(int);
    int set(int);
};

int CXTPImageManagerIcon::set(int value) {
    ((CXTPImageManagerIcon*)((char*)this + 0x30))->sub_64b2c0(value);
    return value;
}
