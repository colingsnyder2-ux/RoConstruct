// from server: 72% by atomic.potato
struct EventDesc
{
    int f(void* p);
};

extern "C" int __cdecl sub_004C0590(EventDesc*, void*);

int EventDesc::f(void* p)
{
    char* value;
    int index;
    int base;

    if (p)
        value = (char*)p - 28;
    else
        value = 0;

    base = *(int*)((char*)value + 148);
    index = *(int*)((char*)this + 44);
    base = *(int*)((char*)base + index);
    base += *(int*)((char*)this + 40);

    return sub_004C0590(this, (char*)base + (int)value + 148);
}
