// from server: 100% by colin
struct CRobloxControlColorSelector {
    void notifyChange();
    void setValue(int value);
    char pad_0[0x108];
    int field_108;
};

void CRobloxControlColorSelector::setValue(int value)
{
    if (value != field_108) {
        field_108 = value;
        notifyChange();
    }
}
