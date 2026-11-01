// from server: 100% by king_originala
struct S {
    unsigned long* data;
    unsigned long count;
};

unsigned long __stdcall f(S* container, const unsigned long* value)
{
    if (value && *value) {
        unsigned long target = *value;
        unsigned long index = 1;
        unsigned long* current = container->data;
        unsigned long* end = current + container->count;
        while (current < end) {
            if (*current == target)
                return index;
            ++current;
            ++index;
        }
    }
    return 0;
}
