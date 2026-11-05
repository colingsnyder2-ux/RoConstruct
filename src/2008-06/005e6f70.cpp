// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

extern void __cdecl compare_elements();
extern void __cdecl sort_elements(unsigned int *, unsigned int *, int,
                                  void (__cdecl *)());

struct Container
{
    void *volatile owner;
    unsigned int reserved[2];
    unsigned int *first;
    unsigned int *last;

    void update(void **);
};

struct Clump
{
    unsigned char reserved[0x28];
    Container elements;

    void sort(void *);
};

void Clump::sort(void *argument)
{
    Container *container = &elements;
    container->update(&argument);

    unsigned int *last = container->last;
    if (container->first > last)
        invalid_parameter_noinfo();

    unsigned int *first = container->first;
    void *owner = container->owner;
    if (first > container->last)
        invalid_parameter_noinfo();

    void *otherOwner = container->owner;
    if (!owner || owner != otherOwner)
        invalid_parameter_noinfo();

    sort_elements(first, last, last - first, compare_elements);
}
