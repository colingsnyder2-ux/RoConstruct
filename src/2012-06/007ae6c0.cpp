// from server: 97% by atomic.potato
extern "C" void __cdecl Call983270(int, int, int, int);
extern "C" void __cdecl Call9823ba(int);

struct TextureContentProvider
{
    int value;
    void f();
};

void TextureContentProvider::f()
{
    int value = this->value;
    if (value != 0)
    {
        int base = *reinterpret_cast<int *>(value - 4);
        Call983270(value, 8, base, 0x6dde00);
        Call9823ba(value - 4);
    }
}
