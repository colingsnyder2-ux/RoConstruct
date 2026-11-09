// from server: 46% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    int value;
};

struct Outer {
    char pad[0xb0];
    Inner* begin;
    Inner* end;
    int get(int index);
};

extern "C" int* __cdecl sub_64AA80(int* p);

int Outer::get(int index) {
    int* p = sub_64AA80(&index);
    int i = *p;
    if (i < 0) {
        return 0;
    }
    int count = (int)(end - begin);
    if ((unsigned)i >= (unsigned)count) {
        return 0;
    }
    if ((unsigned)i >= (unsigned)((int)(end - begin))) {
        _invalid_parameter_noinfo();
    }
    return begin[i].value;
}
