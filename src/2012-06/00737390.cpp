// from server: 54% by colin
struct EnumDesc {
    char pad[0x2c];
    unsigned int count;
    char pad2[0x90 - 0x30];
    int* items;
    bool getItem(unsigned int index, int* out);
};

extern "C" int __cdecl sub_783A70();
extern "C" void __cdecl sub_737300(int* p);

bool EnumDesc::getItem(unsigned int index, int* out)
{
    bool found;
    int value;
    if (index < count) {
        value = items[index];
        found = true;
    } else {
        found = false;
    }
    int converted = sub_783A70();
    *out = converted;
    sub_737300(out + 1);
    return found;
}
