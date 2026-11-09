// from server: 100% by why2
struct CSHA1 {
    char pad[0x18];
    unsigned char field_18;
    CSHA1* reset();
};

CSHA1* CSHA1::reset()
{
    field_18 = 0;
    return this;
}
