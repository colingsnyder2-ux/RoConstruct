// from server: 100% by king_originala
struct S
{
    int check1();
    int check2();
    int check3();
};

extern S* __cdecl resolve(void*);

int __stdcall classify(void* value)
{
    S* object = resolve(value);
    if (!object)
        return 2;
    if (!object->check1())
        return 3;
    if (object->check2() && object->check3())
        return 5;
    return 4;
}
