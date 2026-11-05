// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Key {
    int x, y, z;
};

struct Node {
    int value;
    Node* next;
    int unused[3];
    Key key;
};

struct Bucket {
    Node* first;
    int unused;
};

struct Level {
    int unused[3];
    Bucket* begin;
    Bucket* end;
    Bucket* capacity;
};

struct Output {
    int* data;
    int size;
    int capacity;

    void append(const int& value);
    void resize(int count, int fill);
};

struct S {
    int unused[3];
    Level levels[1];

    void find(int level, const Key& key, Output& output);
};

void S::find(int level, const Key& key, Output& output)
{
    unsigned hash =
        (unsigned(key.x) * 0x0466f45dU) ^
        (unsigned(key.y) * 0x0127409fU) ^
        (unsigned(key.z) * 0x04f9ffb7U);

    hash &= 0xffff >> level;

    Level* table = &levels[level];
    if (hash >= unsigned(table->end - table->begin))
        invalid_parameter_noinfo();

    Node* node = table->begin[hash].first;
    while (node) {
        if (node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z) {
            if (output.size < output.capacity) {
                int* destination = output.data + output.size;
                if (destination)
                    *destination = node->value;
                ++output.size;
            } else if ((unsigned)node >= (unsigned)output.data &&
                       (unsigned)node < (unsigned)(output.data + output.size)) {
                int value = node->value;
                output.append(value);
            } else {
                output.resize(output.size + 1, 0);
                output.data[output.size - 1] = node->value;
            }
        }
        node = node->next;
    }
}
