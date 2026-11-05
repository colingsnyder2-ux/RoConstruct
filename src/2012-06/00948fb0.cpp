// from server: 78% by atomic.potato
struct MoveAndJoinTool
{
    char pad0[0x20];
    int field20;
    char pad24[0x58];
    int field7c;
    char pad80[0x1c];
    char field9c;
    void f(int);
};

extern "C" void __stdcall sub_89b660(int);
extern "C" void __cdecl sub_702220(const char*, int);

void MoveAndJoinTool::f(int arg)
{
    if (field9c != 0)
    {
        sub_89b660(field7c);
        field7c = 0;
        int* vt = *(int**)this;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0];
        field9c = 0;
        fn(this);
        char* p = (char*)vt + 4;
        if (*(unsigned int*)(p + 0x18) >= 0x10)
            p = *(char**)(p + 4);
        else
            p = p + 4;
        sub_702220(p, field20);
    }
    int* vt2 = *(int**)this;
    void (__thiscall *fn2)(void*) = (void (__thiscall *)(void*))vt2[0x38 / 4];
    fn2(this);
}
