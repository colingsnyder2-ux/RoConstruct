// native-flags: /O2 /Oy /GS- /Gd
struct S {
    int unused;
    int* data;
    int width;
};

void __cdecl setValue(S* s, int x, int y, int value)
{
    s->data[y * s->width + x] = value;
}
