// from server: 67% by atomic.potato
struct ArrowTool
{
    int __thiscall Get(int);
};

int __thiscall ArrowTool::Get(int value)
{
    int* object = (int*)value;
    int* table = *(int**)((char*)object + 0x10);
    int index = *(int*)((char*)object + 8);
    int offset = *(int*)((char*)table + 0x94 + index * 4);
    return (int)((char*)table + 0x94 + offset + *(int*)((char*)object + 4));
}
