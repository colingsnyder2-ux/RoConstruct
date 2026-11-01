// from server: 100% by king_originala
typedef void (__cdecl *Callback)(void *, void *, int);

struct Entry {
    Callback *callbacks;
    unsigned reserved;
    unsigned char storage[1];
};

struct S {
    unsigned char reserved[16];
    Entry **entries;
    unsigned capacity;
    unsigned index;
    unsigned count;

    void f();
};

void S::f()
{
    if (count != 0) {
        Entry *entry = entries[index];
        if (entry->callbacks != 0) {
            Callback callback = entry->callbacks[0];
            void *storage = entry->storage;
            if (callback != 0)
                callback(storage, storage, 1);
            entry->callbacks = 0;
        }

        ++index;
        if (capacity <= index)
            index = 0;

        if (--count == 0)
            index = 0;
    }
}
