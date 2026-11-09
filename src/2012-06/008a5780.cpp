// from server: 57% by Intel
extern "C" int __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" int __cdecl sub_8A4390();
extern "C" int __cdecl sub_6F45F0(int);
extern "C" int __stdcall sub_B226C4(int, int, int);

struct AdvMoveTool {
    int vtable;
    char pad[0x18];
    char field_1C;

    int __thiscall sub_8A5780(int arg);
};

int __thiscall AdvMoveTool::sub_8A5780(int arg)
{
    if (*(int*)0xC01520 == 0) {
        sub_67F480();
    } else {
        sub_4015A0((void*)0x8A4630, (void*)0xE52FB0);
        sub_8A4390();
    }

    int local[7];
    int* esp_val = local;
    *(int**)0x28 = local;

    sub_B226C4(0xBA067C, arg + 4, (int)local);

    sub_6F45F0((int)this);

    char dl = *(char*)0xC;
    vtable = 0xBDEFB8;
    field_1C = dl;

    return (int)this;
}
