// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Allocator {
    Allocator();
};

inline Allocator::Allocator() {}

struct Container {
    char padding[16];
    unsigned int* end;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    Proxy* proxy;
    unsigned int* current;
};

struct Result {
    void* data[3];
};

struct Base {
    Base(const Allocator&, const Iterator&);
    ~Base();
};

struct S : Base {
    S(Iterator first, Iterator last);
    Result append(const unsigned int&);
};

S::S(Iterator first, Iterator last)
    : Base(Allocator(), first)
{
    void (__cdecl* invalid)() = _invalid_parameter_noinfo;

    for (;;) {
        if (!first.proxy || first.proxy != last.proxy)
            invalid();

        if (first.current == last.current)
            break;

        if (!first.proxy)
            invalid();

        Container* container = first.proxy ? first.proxy->container : 0;
        if (first.current >= container->end)
            invalid();

        append(*first.current);

        if (!first.proxy)
            invalid();

        container = first.proxy ? first.proxy->container : 0;
        if (first.current >= container->end)
            invalid();

        ++first.current;
    }
}
