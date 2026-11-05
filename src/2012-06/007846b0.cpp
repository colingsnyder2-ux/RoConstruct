// from server: 83% by colin
struct S {
    char pad[0x2c];
    unsigned int count;
    char pad2[0x90 - 0x30];
    int* array;
    bool get(unsigned int index, int* out);
};

extern "C" void __cdecl sub_4015a0(const char*, const char*);
extern "C" int __cdecl sub_770430();
extern "C" void __cdecl sub_76a470(int*);

bool S::get(unsigned int index, int* out) {
    int val;
    bool ok;
    if (index < count) {
        val = array[index];
        ok = true;
    } else {
        ok = false;
    }
    sub_4015a0((const char*)0xe4859c, (const char*)0x770490);
    int r = sub_770430();
    *out = r;
    sub_76a470(&val);
    return ok;
}
