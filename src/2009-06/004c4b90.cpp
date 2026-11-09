// from server: 100% by why2
struct S_func_004c4b90 {
    char pad[0xd4];
    void* field_d4;
    int f();
};

int S_func_004c4b90::f()
{
    char* p = *(char**)((char*)this + 0xd4);
    int a = *(int*)(p + 0x10);
    int b = *(int*)(p + 0xc);
    return (a - b) >> 3;
}
