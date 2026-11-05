// from server: 30% by atomic.potato
extern "C" int __cdecl EnumDesc();

struct TextBox
{
    int value;
};

int __stdcall TextBoxFunction(int a, int b, int c, int d, int e, int f, int g)
{
    int x;
    x = EnumDesc();
    return x;
}
