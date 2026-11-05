// from server: 100% by king_originala
struct S {
    virtual void slot0();
    virtual int slot1();
};

extern char data_8501ec[];

extern "C" void __cdecl prepare(int, int);
extern "C" int __stdcall finish(int, int, int, int, const char *, int);

int __cdecl function_429360(int arg, S *object)
{
    int value = object->slot1();
    prepare(1, value);
    return finish(arg, value, 0, 0, data_8501ec, 0);
}
