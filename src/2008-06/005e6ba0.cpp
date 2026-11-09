// from server: 100% by king_originala
struct Iterator {
    void* owner;
    void* value;

    __forceinline Iterator() : owner(0), value(0) {}
    void advance();
};

extern Iterator __cdecl beginIterator(void*);

struct Array {
    void** data;
    int size;
    int capacity;

    void resize(int, int);
    void append(void* const*);
};

struct Clump {
    char padding[28];
    void* collection;

    void collect(Array*);
};

void Clump::collect(Array* output)
{
    Iterator current = beginIterator(collection);
    static Iterator end;
    Iterator finish = end;

    while (current.value != finish.value || current.owner != finish.owner) {
        void* value = current.value;

        if (output->size < output->capacity) {
            void** slot = output->data + output->size;
            if (slot)
                *slot = value;
            ++output->size;
        } else {
            bool overlaps;
            {
                void* probe;
                overlaps =
                    (unsigned long)&probe >= (unsigned long)output->data &&
                    (unsigned long)&probe <
                        (unsigned long)(output->data + output->size);
            }
            if (overlaps) {
                void* temporary = value;
                output->append(&temporary);
            } else {
                output->resize(output->size + 1, 0);
                output->data[output->size - 1] = value;
            }
        }

        current.advance();
    }
}
