// from server: 28% by atomic.potato
struct S {
    char pad[8];
    int (__stdcall *fn)(float, float, float);
    char pad2[4];
    int method(void* a, float* b);
};

int S::method(void* a, float* b) {
    S* p = (a != 0) ? (S*)((char*)a - 0x1c) : 0;
    float x = b[0];
    float y = b[1];
    float z = b[2];
    return fn(x, y, z);
}
