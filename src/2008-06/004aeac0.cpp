// from server: 100% by king_originala
extern "C" {
    extern void (__cdecl* _invalid_parameter_noinfo)();
}

struct Iterator {
    void* owner;
    void* node;

    bool operator!=(const Iterator& other) const;
};

__forceinline bool Iterator::operator!=(const Iterator& other) const
{
    if (!owner || owner != other.owner)
        _invalid_parameter_noinfo();
    return node != other.node;
}

struct Container {
    void* owner;
    char padding[20];
    void* end;

    Iterator find(const unsigned int* key);
};

struct S {
    char padding[0x2c90];
    Container container;

    bool f(unsigned int key);
};

bool S::f(unsigned int key)
{
    Container& container = this->container;
    Iterator last;
    last.node = container.end;
    last.owner = container.owner;
    return container.find(&key) != last;
}
