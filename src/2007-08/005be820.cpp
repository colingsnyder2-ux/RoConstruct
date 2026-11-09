// from server: 100% by colin
struct Inner {
    char pad[0x40];
    unsigned int field40;
    unsigned int field44;
};

struct Outer {
    char pad0[8];
    unsigned int* field8;
    char padC[4];
    Inner* field10;
};

extern "C" void __cdecl sub_60fe00(Outer*);
extern "C" int __cdecl sub_5c8710(Outer*);
extern "C" void __cdecl sub_5be7c0(int, Outer*);

int __cdecl sub_5be820(Outer* obj)
{
    Inner* inner = obj->field10;
    if (inner->field44 >= inner->field40)
    {
        sub_60fe00(obj);
    }
    int result = sub_5c8710(obj);
    unsigned int* p = obj->field8;
    *p = (unsigned int)result;
    p[2] = 8;
    obj->field8 = (unsigned int*)((char*)obj->field8 + 0x10);
    sub_5be7c0(result, (Outer*)((char*)obj - 0xc));
    return result;
}
