// from server: 100% by king_originala
typedef void (__cdecl *InvalidParameterHandler)();
extern InvalidParameterHandler invalid_parameter;

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    unsigned value;
};

struct Container {
    unsigned padding[6];
    Node* head;
};

struct Iterator {
    Container** owner;
    Node* node;

    bool different(const Iterator& other, InvalidParameterHandler handler) const;
    unsigned& value(InvalidParameterHandler handler) const;
    void increment();
};

struct Selection {
    void append(unsigned value);
};

struct CopyTag {};

extern void __cdecl copy_tail(
    void* result,
    Iterator first,
    Iterator last,
    Selection* output,
    Selection* outputCopy,
    Selection* outputEnd,
    CopyTag tag);

__forceinline bool Iterator::different(
    const Iterator& other, InvalidParameterHandler handler) const
{
    if (!owner || owner != other.owner)
        handler();
    return node != other.node;
}

__forceinline unsigned& Iterator::value(InvalidParameterHandler handler) const
{
    if (!owner)
        handler();
    Container* container = owner ? *owner : 0;
    if (node == container->head)
        handler();
    return node->value;
}

void* __cdecl difference(
    void* result,
    Iterator first,
    Iterator last,
    Iterator second,
    Iterator secondLast,
    Selection* volatile output)
{
    InvalidParameterHandler handler = invalid_parameter;

    while (first.different(last, handler) &&
           second.different(secondLast, handler)) {
        if (first.value(handler) < second.value(handler)) {
            output->append(first.value(handler));
            first.increment();
        } else if (second.value(handler) < first.value(handler)) {
            second.increment();
        } else {
            first.increment();
            second.increment();
        }
    }

    copy_tail(result, first, last, output, output, output, CopyTag());
    return result;
}
