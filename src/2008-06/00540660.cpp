// from server: 100% by king_originala
#pragma optimize("", off)

struct Bucket;

struct Iterator {
    Iterator(void* node, Bucket* owner);
    void* node;
    Bucket* owner;
};

struct Bucket {
    unsigned char padding[16];
    void* node;
    Iterator f();
};

Iterator Bucket::f()
{
    return Iterator(node, this);
}
