// from server: 100% by tajop
struct XItem {
    char pad[0x10c];
    int field_10c;
    int field_110;
    int field_114;
    int field_118;
    int field_11c;
    void method_0069a270();
    XItem* destroy(unsigned int flags);
};

extern "C" void __cdecl sub_0062fc62(void*);

XItem* XItem::destroy(unsigned int flags)
{
    XItem* p = this;
    int* esi;
    if (p != 0)
        esi = (int*)((char*)p + 0x10c);
    else
        esi = 0;

    if (esi[2] != 0)
    {
        sub_0062fc62((void*)esi[2]);
    }
    esi[2] = 0;
    esi[3] = 0;
    esi[4] = 0;
    p->method_0069a270();
    if (flags & 1)
    {
        sub_0062fc62(p);
    }
    return p;
}
