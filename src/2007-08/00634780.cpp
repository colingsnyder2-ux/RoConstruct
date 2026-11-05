// from server: 100% by colin
struct MyXTPCommandBars
{
    char pad[0x5c];
    int field_5c;
    char pad2[0x24];
    int field_84;

    void method_6329e0(int);
    void* method_632910(int);
    void method_632520(int);
    void method_6338d0(int);
    void func(int);
};

void MyXTPCommandBars::func(int arg)
{
    *(int*)(*(int*)((char*)this + 0x74) + 0x4c) = 1;
    field_5c = arg;
    method_6329e0(0);
    int i = 0;
    if (field_84 > 0)
    {
        do
        {
            void* p = method_632910(i);
            (*(void(__thiscall**)(void*))(*(int*)p + 0x13c))(p);
            (*(void(__thiscall**)(void*, int, int))(*(int*)p + 0x1e0))(p, 1, 1);
            i++;
        } while (i < field_84);
    }
    method_632520(0);
    method_6338d0(field_5c);
}
