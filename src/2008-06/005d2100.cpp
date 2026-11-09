// from server: 100% by colin
struct S
{
    char getValue(void*);
    int value8;
    int valueC;
};

char S::getValue(void* p)
{
    char* base = (char*)p;
    if (base)
        base -= 20;
    else
        base = 0;

    int* index = *(int**)(base + 0x134);
    int offset = *(int*)((char*)this + 0xC);
    int entry = *(int*)((char*)index + offset);
    entry += *(int*)((char*)this + 8);

    return *(char*)(entry + (int)base + 0x134);
}
