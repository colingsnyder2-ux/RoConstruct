// from server: 100% by colin
struct EnumPropDescriptor {
    int getValue() const;
};

int EnumPropDescriptor::getValue() const {
    int idx = *(int*)((char*)this + 4);
    int obj = *(int*)this;
    int vtbl = *(int*)(obj + 0x1d8);
    return *(int*)(vtbl + idx * 4 + 0x7c);
}
