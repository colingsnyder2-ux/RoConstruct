// from server: 100% by king_originala
struct Texture {
    int f(int, int, int);
};

extern "C" bool __cdecl func_0060a2f0(int*);

int Texture::f(int a, int b, int c)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    *(int*)this = 0;
    if (!func_0060a2f0(local)) {
        int* p = (int*)((char*)this + 8);
        if (p) {
            p[0] = local[0];
            p[1] = local[1];
        }
        *(int*)this = 0x826f7c;
        return (int)this;
    }
    *(int*)this = 0;
    return (int)this;
}
