// from server: 58% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    int offset1c;
    int offset20;
    int method(int, char*);
};

int S::method(int a, char* b) {
    S* p;
    if (a != 0) {
        p = (S*)((char*)a - 0x1c);
    } else {
        p = 0;
    }
    unsigned char c = (unsigned char)*b;
    int idx = *(int*)((char*)p + 0x84);
    int val = *(int*)(idx + this->offset20);
    val += this->offset1c;
    int* ptr = (int*)((char*)p + 0x84 + val);
    return this->fn((int)ptr, (int)c);
}
