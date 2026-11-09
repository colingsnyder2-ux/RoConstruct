// from server: 56% by atomic.potato
struct S {
    char pad[0x18];
    int field18;
    int field1c;
    int field20;
    int method(int, int);
};

int S::method(int a, int b) {
    S* p = (S*)a;
    if (p != 0) {
        p = (S*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int* q = (int*)b;
    int v1 = q[1];
    int v2 = q[0];
    int idx = *(int*)((char*)this + 0x20);
    int* arr = *(int**)((char*)p + 0x84);
    int base = arr[idx];
    base += *(int*)((char*)this + 0x1c);
    int (__stdcall *fn)(int, int, int) = *(int(__stdcall**)(int, int, int))((char*)this + 0x18);
    return fn(base + (int)p + 0x84, v2, v1);
}
