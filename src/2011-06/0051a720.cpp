// from server: 0% by atomic.potato
struct ErrComp
{
    char pad0[0xc];
    char field_c;
    char pad1[0x30 - 0xd];
    int count;
    int send(int, int);
};

extern "C" void __stdcall sub_80A058(int);
extern "C" int __fastcall sub_51A4E0(char *, int);

int ErrComp::send(int a, int b)
{
    (*(void (__thiscall **)(int))a)(b);
    if (sub_51A4E0(&field_c, b))
    {
        return 1;
    }
    sub_80A058(b);
    --count;
    return 0;
}
