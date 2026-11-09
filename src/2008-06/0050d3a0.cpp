// from server: 100% by king_originala
struct S {
    int unused;
    int* data;
    int width;
};

void __cdecl setValue(S* s, int x, int y, int value)
{
    s->data[y * s->width + x] = value;
}
