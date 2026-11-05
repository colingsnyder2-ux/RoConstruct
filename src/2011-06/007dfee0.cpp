// from server: 66% by atomic.potato
extern "C" void sub_78BE20(void*, void*);

struct LockTool
{
    int* vtable;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;

    LockTool(void*);
};

LockTool::LockTool(void* arg)
{
    sub_78BE20(this, arg);
    vtable = (int*)0xABE69C;
    field04 = (int)0xABE674;
    field20 = 0;
    field24 = 0;
}
