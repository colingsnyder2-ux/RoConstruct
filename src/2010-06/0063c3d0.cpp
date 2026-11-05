// from server: 56% by colin
struct EventDesc {
    char pad[0x38];
    int offset38;
    int offset3c;
    int method(int, int);
};

int EventDesc::method(int a, int b)
{
    int* p = (int*)a;
    if (p != 0)
        p = (int*)((char*)p - 0x1c);
    else
        p = 0;

    int edx = *(int*)((char*)p + 0x98);
    int esi = *(int*)((char*)this + 0x3c);
    edx = *(int*)(edx + esi);
    edx += *(int*)((char*)this + 0x38);
    int ecx = (int)((char*)p + 0x98 + edx);
    return ((int (__thiscall*)(void*, int, int))0x4b12a0)((void*)ecx, a, b);
}
