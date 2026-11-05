// from server: 100% by king_originala
struct Entry {
    void* value;
    void reset(void* value);
};

extern "C" void __cdecl alignedFree(void* memory);

struct S {
    Entry* entries;
    int count;
    int capacity;
    void clear();
};

#pragma optimize("", off)
void S::clear()
{
    for (int i = 0; i < count; i++)
        entries[i].reset(0);

    alignedFree(entries);
    entries = 0;
    count = 0;
    capacity = 0;
}
