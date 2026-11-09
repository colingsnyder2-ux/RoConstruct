// from server: 43% by atomic.potato
struct Job {
    char pad0[0xc];
    void** items;
    int count;
    void process(int a, int b, int c, int d);
};

void Job::process(int a, int b, int c, int d) {
    for (int i = 0; i < count; i++) {
        void* p = items[i];
        ((void (__thiscall*)(void*, int, int, int, int))0x4d8e80)(p, a, b, c, d);
    }
}
