// from server: 14% by atomic.potato
struct Sky {
    char pad0[0xc];
    void** items;
    int count;
    void method(int);
};

void Sky::method(int arg) {
    int i = 0;
    while (i < count) {
        void* p = items[i];
        (*(void (__thiscall**)(void*, int))p)(p, arg);
        i++;
    }
}
