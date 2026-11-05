// from server: 60% by atomic.potato
extern "C" int sub_785920(void*);

struct S
{
    int f(void* value);
    void* field_2c;
};

int S::f(void* value)
{
    if (value != 0)
        return sub_785920(static_cast<void*>(
            static_cast<char*>(field_2c) +
            (reinterpret_cast<char*>(value) - reinterpret_cast<char*>(0x1c))));
    return sub_785920(field_2c);
}
