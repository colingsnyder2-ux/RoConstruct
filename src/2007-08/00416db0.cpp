// from server: 92% by colin
struct VCLuaFunction {
    char pad[4];
    int field4;
    void sub_415f00();
    void sub_416db0();
};

void VCLuaFunction::sub_416db0()
{
    char* p = (char*)this + 4;
    ((VCLuaFunction*)p)->sub_415f00();
    int v = *(int*)(p + 4);
    extern void __cdecl sub_62fc62(int);
    sub_62fc62(v);
    *(int*)(p + 4) = 0;
}
