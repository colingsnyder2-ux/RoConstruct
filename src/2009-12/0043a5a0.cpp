// from server: 91% by atomic.potato
struct PairF {
    float value;
    unsigned short kind;
};

struct UDimComponentItem {
    char pad[0x130];
    int mode;
    bool equals(const PairF* a, const PairF* b);
};

bool UDimComponentItem::equals(const PairF* a, const PairF* b) {
    if (this->mode == 0)
        return a->value == b->value;
    return a->kind == b->kind;
}
