// from server: 100% by tajop
struct InstanceBase {
    char pad[0x1c];
};

struct DescBase {
    int field_0;
};

struct Signal {
    int f();
};

struct EventClass : InstanceBase, DescBase {
};

struct EventDesc {
    char pad[0x2c];
    Signal EventClass::* sig;
    int invoke(DescBase* source);
};

int EventDesc::invoke(DescBase* source)
{
    return (static_cast<EventClass*>(source)->*sig).f();
}
