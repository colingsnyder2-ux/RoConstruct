// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// Analog for 00545da0: distributes a range over hashed buckets; iterator
// helpers 00540f20 (!=), 00540f50 (++), 005462c0 (*), key 00540e80, bucket
// lookup 00546290 and list append 00546210.
class Item {
public:
    int key() const;
};

class Iter {
public:
    bool operator!=(const Iter& other) const;
    Iter& operator++();
    Item& operator*() const;
    void* node;
    void* owner;
};

class List {
public:
    void push_back(const int& value);
};

class Bucket {
public:
    char header[0x0c];
    List items;
};

class Buckets {
public:
    Bucket& operator[](unsigned index);
};

class Table {
public:
    void insert(Iter first, Iter last);
    unsigned size;
    unsigned numBuckets;
    Buckets buckets;
};

void Table::insert(Iter first, Iter last)
{
    unsigned index = 0;
    for (; first != last; ++first) {
        int value = (*first).key();
        buckets[index].items.push_back(value);
        ++index;
        index = index % numBuckets;
        ++size;
    }
}
