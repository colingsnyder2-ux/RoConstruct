// from server: 100% by king_originala
struct Bucket {
    bool __thiscall f(void* argument);
};

struct BucketPointer {
    Bucket* __thiscall get() const;
};

struct Node {
    unsigned char padding[12];
    BucketPointer second;
};

struct Iterator {
    int context;
    int* position;
    bool __thiscall operator!=(const Iterator& other) const;
    Node* __thiscall operator->() const;
    Iterator& __thiscall operator++();
};

struct Container {
    Iterator __thiscall begin();
    Iterator __thiscall end();
};

struct S {
    unsigned char padding[8];
    Container container;
    void __thiscall f(void* argument);
};

#pragma optimize("", off)
void S::f(void* argument)
{
    Iterator current = container.begin();
    Iterator finish = container.end();
    while (current != finish) {
        if (current->second.get()->f(argument))
            break;
        ++current;
    }
}
