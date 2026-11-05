// from server: 59% by atomic.potato
extern "C" int __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" int __cdecl sub_8A3AD0();
extern "C" void __cdecl sub_6F45F0();
extern "C" void* __cdecl sub_B226C4(void*, void*, void*);

int g_flag = 0;

struct StudsTool {
    char pad0[0x1c];
    char field_1c;
    int method(int arg);
};

int StudsTool::method(int arg)
{
    int result;
    if (g_flag == 0)
        result = sub_67F480();
    else {
        sub_4015A0((void*)0x8A44F0, (void*)0xE52F60);
        result = sub_8A3AD0();
    }
    char buf[0x1c];
    sub_B226C4(buf, (void*)(result + 4), (void*)0xBA067C);
    sub_6F45F0();
    this->field_1c = buf[0];
    *(void**)this = (void*)0xBDF37C;
    return (int)this;
}
