// from server: 44% by colin
struct Item {
    char pad[4];
    int field4;
    int field8;
};

struct TypedStatsItem : Item {
    void update(int* out);
};

extern "C" void __cdecl sub_413C00(char* buf);
extern "C" void __cdecl sub_414170(char* buf);

void TypedStatsItem::update(int* out)
{
    if (*(int*)this == 0) {
        char buf[128];
        sub_413C00(buf);
        sub_414170(buf);
    }
    int a = this->field4;
    int b = this->field8;
    char buf2[128];
    int (*fn)(int, char*) = (int (*)(int, char*))b;
    int r = fn(a, buf2);
    char* src = (char*)r;
    char* dst = (char*)out;
    for (int i = 0; i < 0x16; i++) {
        ((int*)dst)[i] = ((int*)src)[i];
    }
}
