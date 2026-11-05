// from server: 93% by atomic.potato
struct BoundPropGetSet
{
    int get(int* value);
    int base;
    int index;
};

int BoundPropGetSet::get(int* value)
{
    int offset = value ? ((char*)value - (char*)0) - 0x1c : 0;
    int* table = *(int**)((char*)offset + 0x98);
    int entry = *(int*)((char*)table + index);
    int address = entry + base;
    return *(int*)((char*)address + offset + 0x98);
}
