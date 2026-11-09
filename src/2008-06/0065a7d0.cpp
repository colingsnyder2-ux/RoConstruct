// from server: 100% by king_originala
struct Key {
    int x, y, z;
};

extern int levelCount;

struct S {
    void append(int level, const Key& key, int value);
    void f(const Key& key, int value);
};

void S::f(const Key& key, int value)
{
    Key current = key;
    for (int level = 0; level < levelCount; ++level) {
        append(level, current, value);
        current.x >>= 1;
        current.y >>= 1;
        current.z >>= 1;
    }
}
