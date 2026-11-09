// from server: 100% by king_originala
struct Tree {
    void insert(void *, unsigned int, void *, const void *, int);
};

struct S {
    char padding[4];
    Tree tree;
    void *f(void *, const void *);
};

void *S::f(void *result, const void *value)
{
    volatile union {
        unsigned int word;
        unsigned char byte;
    } tag;

    tag.word = 0;
    tag.byte = 0;
    tree.insert(result, tag.word, this, value, 0);
    return result;
}
