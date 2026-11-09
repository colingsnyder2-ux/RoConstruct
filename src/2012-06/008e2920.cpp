// from server: 59% by atomic.potato
struct S {
    char pad[0x18];
    int field_18;
    int field_1c;
    int field_20;
    void method(int, float);
};

void S::method(int a, float b) {
    char* p = (char*)a;
    if (p != 0) {
        p -= 0x1c;
    } else {
        p = 0;
    }
    int idx = *(int*)((char*)this + 0x20);
    int* arr = *(int**)(p + 0x84);
    int base = arr[idx];
    base += *(int*)((char*)this + 0x1c);
    void (*fn)(void*, float) = *(void(**)(void*, float))((char*)this + 0x18);
    fn((void*)(base + (int)p + 0x84), b);
}
