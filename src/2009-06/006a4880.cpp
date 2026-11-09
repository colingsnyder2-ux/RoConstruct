// from server: 100% by why2
struct P8PVInstance {
    char pad[0x94];
    short field_94;
    int sub_6a4810();
    int SetImpl();
};

int P8PVInstance::SetImpl() {
    sub_6a4810();
    return field_94;
}
