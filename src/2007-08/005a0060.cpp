// from server: 100% by colin
struct P8ModelInstance {
    char pad[0x18];
    int field_18;
    int field_1c;
    int field_20;
    void method(int, int);
};

void P8ModelInstance::method(int a, int b)
{
    int* p = (int*)a;
    if (p != 0)
        p = (int*)((char*)p - 4);
    else
        p = 0;
    int v = *(int*)b;
    int idx = field_20;
    int off = *(int*)((char*)p + 0xec);
    int val = *(int*)(off + idx);
    val += field_1c;
    int fn = field_18;
    int arg = val + (int)p + 0xec;
    ((void (__thiscall*)(void*, int))fn)((void*)arg, v);
}
