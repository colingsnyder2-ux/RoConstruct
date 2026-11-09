// from server: 79% by atomic.potato
struct WedgeBuilder {
    char pad0[4];
    int* begin;
    int* end;
    int* cap;
    void push_back(int* value);
};

void WedgeBuilder::push_back(int* value) {
    int* first = begin;
    int count;
    if (first == 0)
        count = 0;
    else
        count = (cap - first) >> 2;
    int* last = end;
    int used = (last - first) >> 2;
    if (used < count) {
        *last = *value;
        end = last + 1;
        return;
    }
    extern void __stdcall grow(int*, int, int*);
    grow(last, 1, value);
}
