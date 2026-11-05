// from server: 65% by atomic.potato
struct TextService {
    char pad0[0x68];
    int* begin;
    int* end;
    int getAlignment(int);
};

extern "C" int* __stdcall sub_5c33a0(int*);

int TextService::getAlignment(int a) {
    int* p = sub_5c33a0(&a);
    int idx = *p;
    if (idx < 0) return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count) return 0;
    return begin[idx];
}
