// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Item {
    char padding[0x30];
    float depth;
    unsigned int layer;
};

int __cdecl compare(const Item* const& left, const Item* const& right)
{
    if (left->layer < right->layer ||
        (left->layer == right->layer && left->depth > right->depth))
        return 1;
    return 0;
}
