// from server: 25% by atomic.potato
struct VLighting {
    char pad[0x1d0];
    int field1d0;
    int field1d4;
    void* method(int* a, int b);
};

void* VLighting::method(int* a, int b) {
    int local[2];
    local[0] = field1d0;
    local[1] = field1d4;
    return ((void* (*)(int*, int))0x713c40)(a, b);
}
