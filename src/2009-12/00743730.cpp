// from server: 76% by atomic.potato
struct RefPropDescriptor {
    int padding[41];
    int value;
    void Set(int);
};

void RefPropDescriptor::Set(int value)
{
    if (this->value != value) {
        this->value = value;
        Set(value);
    }
}
