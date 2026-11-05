// from server: 44% by atomic.potato
struct S {
    char pad0[4];
    int count;
    int capacity;
    void grow(int);
    void clear();
};

void S::clear() {
    int n = count;
    if (n == 0)
        return;
    int cap = capacity;
    count = 0;
    if (cap < 0) {
        if (cap == 0)
            capacity = 0;
        else
            capacity = 10;
        grow(n);
    }
    if (n >= count)
        return;
    int i = n;
    int off = n << 4;
    while (i < count) {
        char* p = (char*)*(int*)this + off;
        if (p) {
            *(float*)(p) = 0.0f;
            *(float*)(p + 4) = 0.0f;
            *(float*)(p + 8) = 0.0f;
        }
        i++;
        off += 16;
    }
}
