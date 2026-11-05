// from server: 100% by king_originala
extern "C" void (__cdecl * _invalid_parameter_noinfo)();

struct Container {
    void *reserved[3];
    void **first;
    void **last;
};

struct IteratorBase {
    void *proxy;
    IteratorBase();
    void set_container(const Container *);
};

struct Iterator : IteratorBase {
    void **current;
    Iterator(void **p, const Container *container);
};

#pragma optimize("", off)

Iterator::Iterator(void **p, const Container *container)
{
    if (container == 0 || container->first > p || p > container->last)
        _invalid_parameter_noinfo();

    do {
    } while (0);

    set_container(container);
    current = p;
}
