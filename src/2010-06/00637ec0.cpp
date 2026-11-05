// from server: 17% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    int field1c;
    int field20;
    int method(int a, int b);
};

int S::method(int a, int b)
{
    S* p;
    if (a != 0)
        p = (S*)((char*)a - 0x1c);
    else
        p = 0;

    int* arr = (int*)b;
    int v1 = arr[1];
    int v0 = arr[0];

    int idx = *(int*)((char*)p + 0x98);
    int off = *(int*)(idx + this->field20);
    off += this->field1c;
    char* base = (char*)p + 0x98;
    int arg = off + (int)base;

    return this->fn(v0, v1);
}
