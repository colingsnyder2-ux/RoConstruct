// from server: 100% by king_originala
struct Text {
    char storage[0x1c];
};

extern void (__thiscall *clearText)(Text*);
extern "C" void __cdecl sub_005f52e0(int*, int);

struct S {
    int* data;
    char pad04[0x20];
    Text field24;
    int field40;
    int field44;

    void sub_005f5750(int*, int);
};

void __cdecl f(S* self, int a, int b)
{
    int sink = a;
    if (b & 2) {
        self->sub_005f5750(&sink, 2);
        if (self->field44 & 1) {
            int value = self->data[2];
            sub_005f52e0(&sink, value);
            sub_005f52e0(&sink, value >> 8);
            sub_005f52e0(&sink, value >> 16);
            sub_005f52e0(&sink, value >> 24);

            value = self->data[3];
            sub_005f52e0(&sink, value);
            sub_005f52e0(&sink, value >> 8);
            sub_005f52e0(&sink, value >> 16);
            sub_005f52e0(&sink, value >> 24);
        }
    }
    clearText(&self->field24);
    self->field40 = 0;
    self->field44 = 0;
}
