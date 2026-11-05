// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
extern "C" void* __cdecl allocate(unsigned int, unsigned int);
extern "C" void* __cdecl clear_memory(void*, int, unsigned int);
extern unsigned int table_vftable[];

struct Storage {
    unsigned int* vftable;
    int count;
    void* entries;
    int capacity;

    Storage();
    ~Storage();
};

__forceinline Storage::Storage() {
    vftable = table_vftable;
    capacity = 10;
    count = 0;
    entries = allocate(40, 16);
    clear_memory(entries, 0, capacity * 4);
}

struct Lock {
    unsigned char data[12];
    Lock();
    ~Lock();
};









struct S {
    Storage storage;
    Lock lock;
    std::map<int,int> materials;
    std::map<int,int> vectors;
    int value;

    S();
};

S::S()
    : materials(),
      vectors(),
      value(0)
{
}
