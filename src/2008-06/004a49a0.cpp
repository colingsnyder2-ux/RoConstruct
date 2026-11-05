// from server: 100% by king_originala
struct VDHTMLWindow_BoundFuncDesc {
    char pad0[0x38];
    int (__thiscall *field38)(int);
    int field3c;
    void method(int, int*);
};

extern "C" int __cdecl sub_56cbc0();
extern "C" void* __cdecl sub_6a0920(int);

void VDHTMLWindow_BoundFuncDesc::method(int a, int* out)
{
    int result = field38(field3c + a);
    int* p = out;
    *p = sub_56cbc0();
    int* slot = p + 1;
    void* obj = sub_6a0920(8);
    if (obj) {
        *(int*)obj = 0x8106cc;
        *(int*)((char*)obj + 4) = result;
    } else {
        obj = 0;
    }
    int old = (int)obj;
    if (&old != slot) {
        old = *slot;
        *slot = (int)obj;
    }
    if (old) {
        typedef void (__thiscall *Destroy)(int, int);
        (*(Destroy**)old)[0](old, 1);
    }
}
