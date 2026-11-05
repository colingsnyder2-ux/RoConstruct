// from server: 100% by king_originala
extern "C" void __cdecl release(void*);

struct Entry
{
    typedef void (__cdecl *Callback)(void*, void*, int);
    Callback* manager;
    unsigned int reserved;
    char storage[1];
};

struct S
{
    unsigned char reserved[16];
    Entry** entries;
    unsigned int capacity;
    unsigned int first;
    unsigned int count;

    void clear();
};

void S::clear()
{
    while (count != 0)
    {
        if (count != 0)
        {
            unsigned int index = count + first - 1;
            if (capacity <= index)
                index -= capacity;

            Entry* entry = entries[index];
            if (entry->manager != 0)
            {
                Entry::Callback callback = *entry->manager;
                void* storage = entry->storage;
                if (callback != 0)
                    callback(storage, storage, 1);
                entry->manager = 0;
            }

            if (--count == 0)
                first = 0;
        }
    }

    unsigned int remaining = capacity;
    while (remaining > 0)
    {
        --remaining;
        if (entries[remaining] != 0)
            release(entries[remaining]);
    }

    if (entries != 0)
        release(entries);

    capacity = 0;
    entries = 0;
}
