// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);
extern void __cdecl release(void *);

struct COutputView {
    unsigned char padding[16];
    char **slots;
    unsigned capacity;
    unsigned first;
    unsigned count;

    void clear();
};

void COutputView::clear()
{
    while (count != 0) {
        if (count != 0) {
            unsigned index = first + count - 1;
            if (capacity <= index)
                index -= capacity;

            destroyString(slots[index] + 4);

            if (--count == 0)
                first = 0;
        }
    }

    unsigned i = capacity;
    while (i > 0) {
        --i;
        if (slots[i] != 0)
            release(slots[i]);
    }

    if (slots != 0)
        release(slots);

    capacity = 0;
    slots = 0;
}
