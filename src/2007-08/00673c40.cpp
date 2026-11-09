// from server: 100% by colin
struct CXTPCustomizeSheet_CCustomizeButton {
    void func_00673c40();
};

extern "C" int (__stdcall *SendMessageA)(int, unsigned int, int, int);

struct Sub_006465D0 {
    int get();
};

struct Sub_00643950 {
    int get();
};

struct Sub_00643750 {
    int get();
};

extern int func_0063a810();

void CXTPCustomizeSheet_CCustomizeButton::func_00673c40()
{
    int local[4];
    int result;
    int v;
    int edi;

    result = ((Sub_006465D0*)(*(int*)((char*)this + 0xfc)))->get();
    edi = result;
    v = ((Sub_00643950*)(*(int*)((char*)this + 0xfc)))->get();
    ((Sub_00643750*)v)->get();

    result = ((int (__thiscall*)(CXTPCustomizeSheet_CCustomizeButton*, int, int, int*))func_0063a810)(this, edi, 0x64, local);
    if (result == 0) {
        int hwnd = *(int*)((char*)this + 0x84);
        int id = *(int*)(edi + 0x20);
        SendMessageA(id, 0x111, hwnd, 0);
    }
}
