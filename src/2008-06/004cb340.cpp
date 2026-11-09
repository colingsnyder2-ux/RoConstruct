// from server: 100% by king_originala
struct Result
{
    void* node;
    unsigned* owner;
};

struct Link
{
    Link* next;
};

struct S
{
    unsigned padding0[2];
    unsigned count;
    unsigned padding1[2];
    Link** buckets;

    Result f(const unsigned& key, unsigned, unsigned);
};

Result S::f(const unsigned& key, unsigned, unsigned)
{
    unsigned value = key;
    unsigned bucket = (value + (value >> 3)) % count;
    Link* end = reinterpret_cast<Link*>(buckets + bucket);
    Link* current = end->next;

    while (current != end)
    {
        unsigned* object = current
            ? reinterpret_cast<unsigned*>(reinterpret_cast<char*>(current) - 0x70)
            : 0;

        if (value == *object)
        {
            Result result;
            result.owner = &count;
            result.node = current
                ? reinterpret_cast<char*>(current) - 0x70
                : 0;
            return result;
        }

        current = current->next;
    }

    Result result;
    result.owner = &count;
    result.node = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) - 8);
    return result;
}
