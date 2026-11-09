// from server: 27% by atomic.potato
extern "C" int __stdcall sub_007f4aaa(int, int, int, int, int);
extern bool sub_007469f0(int);

struct S {
    char pad[0x4c];
    int field_4c;
};

bool method(S* self)
{
    if (sub_007469f0((int)self))
        return true;
    int v = self->field_4c;
    while (v != 0) {
        if (sub_007f4aaa(v, 0, 0xaffe40, 0xb352dc, 0) == 0) {
            if (sub_007469f0(v))
                return true;
        }
        v = self->field_4c;
    }
    return false;
}
