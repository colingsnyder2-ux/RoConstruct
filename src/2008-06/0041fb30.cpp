// from server: 100% by king_originala
struct CListCtrl {
    char pad_0x000[0x104];
    int field_0x104;
    char pad_0x108[0x154 - 0x108];
    int field_0x154;
    int sub_41fb30();
};

extern char sourceType;
extern char destinationType;
extern "C" CListCtrl* __cdecl sub_6a17c6(int, int, void*, void*, int);

int CListCtrl::sub_41fb30()
{
    CListCtrl* p = this;
    if (p->field_0x154 == -1) {
        if (sub_6a17c6(p->field_0x104, 0, &sourceType, &destinationType, 0)) {
            p = (CListCtrl*)p->field_0x104;
            p = sub_6a17c6((int)p, 0, &sourceType, &destinationType, 0);
            if (p->sub_41fb30() != 0)
                return 1;
        }
        return 0;
    }
    int r = 0;
    int* value = &p->field_0x154;
    if (*value < 0)
        value = &r;
    return *value;
}
