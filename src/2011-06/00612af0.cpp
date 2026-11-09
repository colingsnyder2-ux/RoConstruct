// from server: 24% by atomic.potato
struct ChangeHistoryService {
    char pad0[0x10];
    void* stream;
    void func(int, int, int);
};

extern "C" void* __stdcall sub_4322C0(void*, int);
extern "C" void* __stdcall sub_4213E0(void*);
extern "C" void* __stdcall sub_6036D0(void*, void*);
extern "C" void __stdcall sub_612A00(void*, void*);
extern "C" void __stdcall sub_A404D0(void*);
extern "C" void* __stdcall sub_A404E4(void*);

void ChangeHistoryService::func(int a, int b, int c) {
    int i;
    void* p;
    char buf[0x28];

    for (i = a; i > 0; i--) {
        sub_4322C0(stream, 9);
    }

    sub_A404E4(sub_4322C0(stream, 0x3c));

    p = *(void**)((char*)b + 0x20);
    while (p != 0) {
        sub_4213E0(sub_A404E4(sub_4322C0(stream, 0x20)));
        sub_6036D0((char*)p + 8, buf);
        sub_612A00(stream, *(void**)(buf + 4));
        sub_A404D0(buf);
        sub_4322C0(stream, 0x22);
        p = *(void**)p;
    }

    if (c != 0) {
        sub_4213E0(sub_A404E4(sub_4322C0(stream, 0x20)));
        sub_6036D0((char*)c + 8, buf);
        sub_612A00(stream, *(void**)(buf + 4));
        sub_A404D0(buf);
        sub_4322C0(stream, 0x22);
    }

    sub_4322C0(stream, 0x3e);
}
