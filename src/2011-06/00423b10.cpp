// from server: 100% by atomic.potato
struct CListCtrl
{
    char pad[0x90];
    unsigned char field_90;
    unsigned char field_91;
    unsigned char field_92;
    char pad2[1];
    unsigned char field_94;
    unsigned char field_95;

    unsigned char compare(CListCtrl* other);
};

unsigned char CListCtrl::compare(CListCtrl* other)
{
    if (other == 0)
        return 0;
    if (other->field_91 != 0 && field_94 == 0)
        return 0;
    if (other->field_92 != 0 && field_95 == 0)
        return 0;
    return other->field_90;
}
