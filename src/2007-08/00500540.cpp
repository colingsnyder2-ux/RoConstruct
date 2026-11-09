// from server: 100% by colin
extern "C" bool __cdecl sub_00500300();
extern "C" bool __cdecl sub_00500310();
extern "C" bool __cdecl sub_005002f0();
extern "C" void __cdecl sub_004ff390();
extern "C" void __cdecl sub_00630d4c();

void sub_00500540()
{
    if (sub_00500300() && sub_00500310()) {
        sub_004ff390();
        return;
    }
    if (sub_005002f0() && sub_00500310()) {
        sub_004ff390();
        return;
    }
    sub_00630d4c();
}
