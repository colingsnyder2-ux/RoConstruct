// from server: 100% by why2
struct CSHA1 {
    int field_0;
    int field_4;
    int field_8;
    CSHA1* clear();
};

CSHA1* CSHA1::clear()
{
    field_8 = 0;
    field_0 = 0;
    field_4 = 0;
    return this;
}
