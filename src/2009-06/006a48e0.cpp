// from server: 100% by why2
struct P8PVInstance {
    char pad[0x9e];
    short field_9e;
    void sub_6a4810();
    int SetImpl();
};

int P8PVInstance::SetImpl() {
    sub_6a4810();
    return field_9e;
}
