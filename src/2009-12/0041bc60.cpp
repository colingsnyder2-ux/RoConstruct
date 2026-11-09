// from server: 47% by atomic.potato


struct Inner {
    char pad0[0x18];
    int field18;
    int field1c;
    char pad20[4];
};

struct Outer {
    char pad0[0x18];
    int field18;
    int field1c;
    char pad20[4];
    char result;
    char pad25[3];
    int field28;

    int func(int arg);
    __declspec(noreturn) void _invalid_parameter_noinfo();
};

struct Guard {
    void* field0;
    int field4;
    int field8;
};

extern "C" int __stdcall sub_7e1e30(void*);
extern "C" int __stdcall sub_7e1e80(void*);
extern "C" int __stdcall sub_66c680(void*, void*);
extern "C" int __stdcall sub_4020a0(void*, void*);
extern "C" int __stdcall sub_41b6f0(void*);

int Outer::func(int arg)
{
    Guard g;
    sub_7e1e30(&this->pad20[0]);
    g.field8 = 0;
    if (this->field1c != 0) {
        int* p = (int*)this->field18;
        int* end = (int*)((char*)p + this->field1c);
        if (p > end) {
            _invalid_parameter_noinfo();
        }
        g.field0 = (void*)this->field18;
        g.field4 = (int)p;
        sub_66c680(&g, &g);
        char* src = (char*)&g;
        char* dst = (char*)&this->result;
        dst[0] = src[0];
        *(int*)(dst + 4) = *(int*)(src + 4);
        sub_4020a0(dst + 8, src + 8);
        sub_41b6f0(this);
        g.field8 = -1;
        sub_7e1e80(&g);
        return 1;
    }
    g.field8 = -1;
    sub_7e1e80(&g);
    return 0;
}
