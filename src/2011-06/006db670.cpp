// from server: 100% by sophus
struct S {
    char pad[0xb4];
    void* field_b4;
    int get();
};

int S::get()
{
    char* p = (char*)field_b4;
    char* q = *(char**)(p + 0x24);
    return *(int*)(q + 0x78);
}