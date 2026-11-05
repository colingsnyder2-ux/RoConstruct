// from server: 16% by atomic.potato
struct RefPropDescriptor
{
    int value;
    RefPropDescriptor* f(int);
};

RefPropDescriptor* RefPropDescriptor::f(int value)
{
    this->value = value;
    return this;
}
