// from server: 100% by why2
struct CSHA1 {
    char pad[0x9c8];
    int field_9c8;
    CSHA1* Reset();
};

CSHA1* CSHA1::Reset() {
    field_9c8 = -1;
    return this;
}
