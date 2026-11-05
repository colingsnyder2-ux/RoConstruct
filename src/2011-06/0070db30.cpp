// from server: 61% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    int offset1c;
    int offset20;
    int method(int, int);
};

int S::method(int a, int b) {
    S* p = (S*)a;
    if (p) {
        p = (S*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    unsigned char c = *(unsigned char*)b;
    int idx = *(int*)((char*)this + 0x20);
    int* arr = *(int**)((char*)p + 0x94);
    int val = arr[idx];
    val += *(int*)((char*)this + 0x1c);
    int (__stdcall *f)(int, int) = *(int(__stdcall**)(int,int))((char*)this + 0x18);
    return f(val + (int)p + 0x94, c);
}
