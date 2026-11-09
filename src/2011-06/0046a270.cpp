// from server: 65% by atomic.potato
extern "C" double sub_502c30(void*);

extern "C" void sub_65bc50(void*, double*);

struct TypedStatsItem
{
    void f();
    char pad[0xb8];
};

void TypedStatsItem::f()
{
    double value = sub_502c30(pad);
    sub_65bc50(this, &value);
}
