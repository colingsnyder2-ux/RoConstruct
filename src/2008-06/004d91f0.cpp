// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl clearMemory(void*, int, unsigned int);
extern const unsigned char tableIdentity[];

struct Storage
{
    const void* identity;
    int count;
    void* buckets;
    int capacity;

    Storage();
    ~Storage();
};

__forceinline Storage::Storage()
{
    identity = tableIdentity;
    capacity = 10;
    count = 0;
    buckets = allocate(40, 16);
    clearMemory(buckets, 0, capacity * 4);
}

struct Resource
{
    unsigned char storage[12];
    Resource();
    ~Resource();
};













struct Table : Storage
{
    Resource resource;
    std::map<int,int> first;
    std::map<int,int> second;
    int value;

    Table();
};

Table::Table()
    : value(0)
{
}
