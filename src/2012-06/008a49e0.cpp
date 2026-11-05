// from server: 100% by tester
extern "C" int __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" int __cdecl sub_410520();

int g_flag = 0;

int sub_410770()
{
    if (g_flag == 0)
        return sub_67F480();
    sub_4015A0((void*)0x410590, (void*)0xE165D4);
    return sub_410520();
}
