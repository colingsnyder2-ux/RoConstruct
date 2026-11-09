// from server: 41% by atomic.potato
extern "C" int sub_69df10(int);

struct S
{
    int value;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    int pad5;
    int pad6;
    int pad7;
    int pad8;
    int pad9;
    int pad10;
    int pad11;
    int pad12;
    int pad13;
    int pad14;
    int pad15;
    int pad16;
    int pad17;
    int pad18;
    int pad19;
    int pad20;
    void *descriptor;
    int f(int);
};

int S::f(int value)
{
    int converted = sub_69df10(value);
    void **table = (void **)descriptor;
    typedef int (__cdecl *Function)(void *, int, int);
    Function function = (Function)table[0x10 / sizeof(void *)];
    return function(descriptor, value, converted);
}
