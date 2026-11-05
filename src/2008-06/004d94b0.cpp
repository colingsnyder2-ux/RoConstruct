// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
extern "C" void* __cdecl allocate(unsigned int size, unsigned int alignment);
extern "C" void* __cdecl fill(void* destination, int value, unsigned int size);

struct Storage {
    int count;
    void* entries;
    int capacity;

    Storage();
    virtual ~Storage();
};

struct Lock {
    unsigned char data[12];

    Lock();
    ~Lock();
};









struct SurfaceTable {
    Storage storage;
    Lock lock;
    std::map<int,int> materials;
    std::map<int,int> vectors;
    int value;

    SurfaceTable();
};





__forceinline Storage::Storage()
{
    capacity = 10;
    count = 0;
    entries = allocate(40, 16);
    fill(entries, 0, capacity * 4);
}

SurfaceTable::SurfaceTable()
    : storage(),
      lock()
{
    value = 0;
}
