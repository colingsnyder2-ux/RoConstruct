// from server: 37% by atomic.potato
extern "C" int __stdcall DialogToneEnumDesc();

struct TextBox
{
    int value;
};

TextBox* __stdcall TextBoxFunction(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g)
{
    TextBox* p = (TextBox*)0;
    p->value = DialogToneEnumDesc();
    return p;
}
