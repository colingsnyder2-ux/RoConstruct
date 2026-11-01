// from server: 100% by king_originala
struct Key {
    unsigned int a, b, c;
};

struct Node {
    char padding[28];
    Key key;
    Node* next;
};

extern int levelLimit;

struct S {
    Node* find(int level, unsigned int hash, const Key& key);
    void remove(Node* node);
    void f(int level, const Key& key);
};

void S::f(int level, const Key& key)
{
    for (int current = level + 1; current < levelLimit; ++current) {
        int shift = current - level;
        Key parent;
        parent.a = (int)key.a >> shift;
        parent.b = (int)key.b >> shift;
        parent.c = (int)key.c >> shift;

        Node* node = find(
            current,
            ((parent.c * 0x04f9ffb7u) ^
             (parent.a * 0x0466f45du) ^
             (parent.b * 0x0127409fu)) & (0xffff >> current),
            parent);

        int bit = shift - 1;
        int index = (((int)key.a >> bit) & 1) +
                    2 * ((((int)key.b >> bit) & 1) +
                         2 * (((int)key.c >> bit) & 1));

        node->padding[18] &= (unsigned char)~(1 << index);
        ((unsigned short*)node)[index] = 0xffff;

        if (*(int*)(node->padding + 20) != 0 ||
            node->padding[18] != 0)
            break;

        remove(node);
    }
}
