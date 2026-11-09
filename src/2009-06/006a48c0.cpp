// from server: 100% by why2
struct P8PVInstance {
    char pad[0x9c];
    short field_9c;
    int SetImpl();
};

extern "C" int __fastcall sub_6a4810(P8PVInstance* self);

int P8PVInstance::SetImpl() {
    sub_6a4810(this);
    return field_9c;
}
