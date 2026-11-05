// from server: 100% by colin
struct Workspace {
    char pad[0x6c];
    void sub_00605b30(void*);
    void func_0057ceb0(int);
};

void Workspace::func_0057ceb0(int a)
{
    ((Workspace*)((char*)this + 0x6c))->sub_00605b30(&a);
}
