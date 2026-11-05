// from server: 90% by atomic.potato
extern "C" int __cdecl sub_981ff4(unsigned char*, int);

struct BoundFuncDesc {
    unsigned char f();
};

unsigned char BoundFuncDesc::f() {
    int value = *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x88);
    if (value == 0)
        return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0xbc) == value;
    unsigned char result;
    if (sub_981ff4(&result, value) == 0x24)
        result = 1;
    return result;
}
