// from server: 100% by king_originala
struct Node {
    unsigned char padding[12];
    unsigned int value;
};

struct Tree {
    unsigned char padding[24];
    Node* sentinel;
};

struct Owner {
    Tree* tree;
};

struct Iterator {
    Owner* owner;
    Node* node;
    void advance();
};

struct Sink {
    void append(unsigned int value);
};

struct Checked {
    bool value;
};

extern "C" void (__cdecl* invalid_parameter_noinfo)();

extern void __cdecl copy_remaining(
    Sink** result,
    Iterator first,
    Iterator last,
    Sink* output1,
    Sink* output2,
    Sink* output3,
    Checked checked
);

Sink** __cdecl set_difference(
    Sink** result,
    Iterator first,
    Iterator last,
    Iterator second,
    Iterator secondLast,
    Sink* volatile output
) {
    void (__cdecl* invalid)() = invalid_parameter_noinfo;

    for (;;) {
        if (!first.owner || first.owner != last.owner)
            invalid();
        if (first.node == last.node)
            break;

        if (!second.owner || second.owner != secondLast.owner)
            invalid();
        if (second.node == secondLast.node)
            break;

        if (!first.owner)
            invalid();
        Tree* firstTree = first.owner ? first.owner->tree : 0;
        if (first.node == firstTree->sentinel)
            invalid();
        unsigned int* firstValue = &first.node->value;

        if (!second.owner)
            invalid();
        Tree* secondTree = second.owner ? second.owner->tree : 0;
        if (second.node == secondTree->sentinel)
            invalid();

        if (*firstValue < second.node->value) {
            if (!first.owner)
                invalid();
            Tree* tree = first.owner ? first.owner->tree : 0;
            if (first.node == tree->sentinel)
                invalid();

            output->append(first.node->value);
            first.advance();
        } else {
            if (!second.owner)
                invalid();
            Tree* tree = second.owner ? second.owner->tree : 0;
            if (second.node == tree->sentinel)
                invalid();
            unsigned int* secondValue = &second.node->value;

            if (!first.owner)
                invalid();
            Tree* otherTree = first.owner ? first.owner->tree : 0;
            if (first.node == otherTree->sentinel)
                invalid();

            if (*secondValue < first.node->value) {
                second.advance();
            } else {
                first.advance();
                second.advance();
            }
        }
    }

    Checked checked;
    checked.value = false;
    copy_remaining(result, first, last, output, output, output, checked);
    return result;
}
