// from server: 33% by atomic.potato
struct Inner {
    char pad0[0x14];
    int field14;
};

struct Outer {
    char pad0[0x10];
    int field10;
    Inner inner;
    int method(int);
};

extern "C" int __stdcall sub_664410(int);
extern "C" int __stdcall sub_770f30(int, int, int);
extern "C" int __stdcall sub_57ba80(int, int);
extern "C" int __stdcall sub_41af50(int);
extern "C" int __stdcall sub_68e8b0(int, int);

int Outer::method(int arg)
{
    if (!sub_664410((int)&inner)) {
        int v = sub_770f30(field10, 0x68e8b0, (int)this);
        sub_57ba80((int)&inner, v);
        sub_41af50((int)&arg);
        if (*(char*)&arg) {
            sub_68e8b0((int)this, 1);
        }
    }
    return arg;
}
