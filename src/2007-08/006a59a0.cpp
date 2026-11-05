// from server: 100% by tajop
// roc 2007-08 006a59a0  unit: seg_006a0000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a59a0

extern "C" __declspec(dllimport) int __stdcall SendMessageA(int, unsigned int, unsigned int, int*);
extern "C" int __cdecl sub_00646570();
extern "C" int __cdecl sub_00738364(int);
extern "C" int __cdecl sub_00630202(int);

struct CXTPMenuBar {
    char pad[0x1a8];
    int field_0x1a8;
    int sub_006a59a0(int);
};

int CXTPMenuBar::sub_006a59a0(int arg) {
    int local = 0;
    if (this->field_0x1a8 == 0) {
        return 0;
    }
    int a = sub_00646570();
    int b = sub_00738364(a);
    int c = sub_00630202(b);
    int d = *(int*)(c + 0xd4);
    int r = SendMessageA(d, 0x229, 0, &local);
    int* p = (int*)arg;
    if (p != 0) {
        *p = local;
    }
    return r;
}
