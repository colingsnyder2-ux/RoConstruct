// from server: 62% by atomic.potato
struct P8Humanoid_GetSetImpl {
    char pad[0x18];
    int (__stdcall *field18)(int, int);
    int field1c;
    int field20;
    int GetSetImpl(int a, int b);
};

int P8Humanoid_GetSetImpl::GetSetImpl(int a, int b)
{
    char *p = (char *)a;
    if (p != 0)
        p -= 0x1c;
    else
        p = 0;

    int idx = *(int *)b;
    int off = *(int *)(this->field20 + (int)p + 0x138);
    int base = off + this->field1c;
    int arg = *(int *)(base + (int)p + 0x138);
    return this->field18(arg, idx);
}
