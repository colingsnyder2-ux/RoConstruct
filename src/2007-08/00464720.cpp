// from server: 54% by colin
struct DxUserInput {
    char pad0[0x34];
    char pad34[0x34];
    char pad68;
    char pad69[0x180 - 0x69];
    int d180;
    int d18C;

    void method();
    void sub_464180(int* out);
};

struct CS {
    void* p;
    unsigned char flag;
};

extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" int __stdcall ClientToScreen(int, int*);
extern "C" int __stdcall InvalidateRect(int, int*, int);
extern "C" int __stdcall LoadCursorA(int, const char*);
extern "C" int __stdcall SetCursor(int);
extern "C" int __stdcall SetCursorPos(int, int);

extern "C" void __cdecl sub_41D870();
extern "C" void __cdecl sub_62FF02();
extern "C" int __cdecl sub_630D60();

extern "C" int dword_8BC0D0;
extern "C" int dword_8BC0D4;

void DxUserInput::method()
{
    CS cs;
    cs.p = (void*)((char*)this + 0x34);
    cs.flag = 0;
    sub_41D870();

    if (d18C != 0 && *(char*)((char*)this + 0x68) != 0) {
        int* p = (int*)d18C;
        int vt = *p;
        int (*fn)(int) = *(int (**)(int))(vt + 0x20);
        fn(d18C);

        int pt[2];
        sub_464180(pt);
        int x = sub_630D60();
        int y = sub_630D60();
        pt[0] = x;
        pt[1] = y;
        ClientToScreen(d180, pt);
        SetCursorPos(pt[0], pt[1]);

        if ((dword_8BC0D4 & 1) == 0) {
            dword_8BC0D4 |= 1;
            sub_62FF02();
            dword_8BC0D0 = LoadCursorA(0, (const char*)0x7F00);
        }
        SetCursor(dword_8BC0D0);
        InvalidateRect(d180, 0, 1);
        *(char*)((char*)this + 0x68) = 0;
    }

    if (cs.flag != 0) {
        LeaveCriticalSection(cs.p);
    }
}
