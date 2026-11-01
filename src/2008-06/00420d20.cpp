// from server: 100% by king_originala
extern "C" void (__cdecl* invalid_parameter_handler)();

struct Container
{
    char padding[16];
    unsigned int* end;
};

struct Iterator
{
    Container** owner;
    unsigned int* current;
};

struct CInstanceExplorer
{
    void clear();
    void append(unsigned int value);
    void assign(Iterator first, Iterator last);
};

void CInstanceExplorer::assign(Iterator first, Iterator last)
{
    clear();
    void (__cdecl* report)() = invalid_parameter_handler;

    for (;;)
    {
        if (!first.owner || first.owner != last.owner)
            report();

        if (first.current == last.current)
            break;

        if (!first.owner)
            report();

        Container* container = first.owner ? *first.owner : 0;
        if (first.current >= container->end)
            report();

        append(*first.current);

        if (!first.owner)
            report();

        container = first.owner ? *first.owner : 0;
        if (first.current >= container->end)
            report();

        ++first.current;
    }
}
