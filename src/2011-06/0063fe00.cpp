// from server: 53% by atomic.potato
struct ArrowTool
{
    void* field0;
    char pad[4];
    int field8;
    int fieldC;
    void construct(int, int);
};

extern "C" bool __cdecl func_00704780(int*, int*);

void ArrowTool::construct(int a, int b)
{
    int local0 = a;
    int local1 = b;
    if (func_00704780(&local0, &local1))
    {
        field0 = 0;
        return;
    }
    int* p = (int*)((char*)this + 8);
    if (p)
    {
        p[0] = local0;
        p[1] = local1;
    }
    field0 = (void*)0xc51b28;
}
