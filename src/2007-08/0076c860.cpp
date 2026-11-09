// from server: 79% by Intel
struct String {
    void* vftable;
    int length;
    int capacity;
    char buffer[1];
};

extern "C" void __stdcall String_ctor(String* thisptr, const char* str);

extern "C" void __cdecl sub_419F80(int a1, int a2, int a3, int a4, int a5);
extern "C" void __cdecl sub_630D23(int a1);

int g_unk_418EF0;
int g_unk_77E698;
int g_unk_785D2C;
int g_unk_787974;
int g_unk_787980;
int g_unk_777520;
int g_unk_8BB010;

void func_0076C860()
{
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;

    v7 = 1;
    v1 = g_unk_785D2C;
    v2 = g_unk_418EF0;
    v3 = 0;
    v4 = v3;
    v5 = v3;
    v6 = v3;
    (*(void (__stdcall**)(int))g_unk_77E698)(v1);
    sub_419F80(g_unk_8BB010, g_unk_787974, g_unk_787980, 0, v2);
    sub_630D23(g_unk_777520);
}
