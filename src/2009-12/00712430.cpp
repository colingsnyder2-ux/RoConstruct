// from server: 87% by atomic.potato
struct S_func_00712430 {
};

extern "C" int __fastcall sub_006EC3A0(int);
extern "C" int __fastcall sub_00701780(int);
extern "C" int __fastcall sub_007123F0(int);
extern "C" int __fastcall sub_00701650(int);

int __cdecl f(int arg)
{
    int esi = sub_006EC3A0(arg);
    if (esi == 0)
        return 0;
    if (sub_00701780(esi))
        return 0;
    return sub_00701650(sub_007123F0(esi));
}
