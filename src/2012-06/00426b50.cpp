// from server: 70% by atomic.potato
extern "C" void sub_9828D6(void *, void *);

struct XOleCommandTarget
{
    int vtable;
    int field_EC;
    int field_F0;
    XOleCommandTarget(void *);
};

XOleCommandTarget::XOleCommandTarget(void *arg)
{
    sub_9828D6(this, arg);
    vtable = 0x00B4D954;
    field_EC = 0x00B4D8EC;
    field_F0 = 0x00B4D938;
}
