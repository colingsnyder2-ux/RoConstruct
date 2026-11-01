// from server: 100% by king_originala
struct Node
{
    Node* next;
};

struct Object
{
    char padding[0x290];
    Node link;
};

struct Flag
{
    bool value;
};

extern "C" int __cdecl sub_5122C0(unsigned int* p);

struct Receiver
{
    char padding0[8];
    unsigned int bucketCount;
    char padding1[8];
    Node** buckets;
    char padding2[8];
    unsigned int firstBucket;
    unsigned int count;

    void reserve(unsigned int n);
    bool find(unsigned int* key, unsigned int** position, Flag flag);
    Object* insert(unsigned int* key, Object* object);
    Object* receive(unsigned int* key, Object* object);
};

Object* Receiver::receive(unsigned int* key, Object* object)
{
    char* base = this ? reinterpret_cast<char*>(this) - 12 : 0;
    reserve(*reinterpret_cast<unsigned int*>(base + 0x30) + 1);

    unsigned int* savedKey = key;
    unsigned int bucket =
        static_cast<unsigned int>(sub_5122C0(savedKey)) % bucketCount;

    Flag flag;
    flag.value = false;
    key = reinterpret_cast<unsigned int*>(buckets + bucket);
    if (!find(savedKey, &key, flag))
        return key ? reinterpret_cast<Object*>(
                         reinterpret_cast<char*>(key) - 0x290) : 0;

    Object* result = insert(savedKey, object);
    if (result == object)
    {
        Node* node = object ? &object->link : 0;
        Node** position = reinterpret_cast<Node**>(key);
        node->next = *position;
        *position = node;
        if (firstBucket > bucket)
            firstBucket = bucket;
    }
    return result;
}
