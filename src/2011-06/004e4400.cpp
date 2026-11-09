// from server: 46% by atomic.potato
extern "C" void sub_411f60(void*, void*);

struct RefPropDescriptor
{
    int value;
    void set(int*);
};

void RefPropDescriptor::set(int* value)
{
    int v = *value;
    if (v != this->value)
    {
        this->value = v;
        sub_411f60(this, (void*)0xcb7c20);
    }
}
