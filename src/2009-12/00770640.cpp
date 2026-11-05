// from server: 41% by atomic.potato
struct VGuiObject_EventDesc {
    char pad0[0x1c];
    int field1c;
    int field20;
    int field24;
    int Init(int, int, int, int, int, int, int, int);
};

extern "C" void __cdecl sub_401630(int, int);
extern "C" int __cdecl sub_652eb0();
extern "C" int __cdecl sub_651830();
extern "C" int __cdecl sub_662b90(int, int, int, int, int, int, int, int);
extern "C" int __cdecl sub_76da10();
extern "C" int __cdecl sub_7f385a(int);

int VGuiObject_EventDesc::Init(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    sub_401630(0xb8fce4, 0x652f10);
    int v = sub_652eb0();
    int w = sub_651830();
    sub_662b90(a1, a2, a3, a4, a5, a6, a7, a8);
    field1c = v;
    *(int*)this = 0x9e8514;
    int r = sub_76da10();
    int x = *(int*)r;
    *(int*)r = 0;
    field20 = x;
    sub_7f385a(a8);
    sub_401630(0xb8fce4, 0x652f10);
    field24 = sub_652eb0();
    return (int)this;
}
