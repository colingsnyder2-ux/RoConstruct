// from server: 66% by atomic.potato
struct S_func_0046abe0 {
    char pad0[88];
    int m_x;
    int* f();
};

struct CScriptEditor {
    char pad0[0x20];
    int m_20;
    int f(int);
};

extern "C" int __stdcall GetFocus();
extern "C" int __cdecl _strupr(char*);
extern "C" char* __cdecl strstr(const char*, const char*);

extern int* __cdecl sub_7f3b2a(int);

int CScriptEditor::f(int arg)
{
    int* esi = ((S_func_0046abe0*)this)->f();
    int h = GetFocus();
    int* p = sub_7f3b2a(h);
    if (p == 0)
        return 0;
    int a = p[8];
    int b = (esi == 0) ? 0 : esi[8];
    if (a != b)
        return 0;

    int* edi = (int*)((char*)&arg + 0x28);
    int v = edi[3] - 7;
    int t = 0;
    int* pa = (v > 0) ? &v : &t;
    int x = *pa;
    int r = ((CScriptEditor*)esi)->f(1);
    int c = edi[3] + 7;
    int* pb = (r < c) ? &r : &c;
    int y = *pb;
    int buf[4];
    buf[0] = x;
    buf[1] = y;
    char* s = (char*)&buf[2];
    _strupr(s);
    if (strstr(s, "AUTHOR ") != 0)
        ((CScriptEditor*)esi)->f(edi[3]);
    return 0;
}
