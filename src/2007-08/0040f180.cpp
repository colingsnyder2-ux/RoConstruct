// from server: 58% by Yeetserama
struct CChildFrame {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    void method_40f180(int* param);
};

extern "C" int __stdcall IsZoomed(void* hWnd);
extern void func_0063023e();
extern void* func_0062ff50();
extern int __cdecl func_0040f060(int* out);
extern int __cdecl func_00444dc0(int* out);

void CChildFrame::method_40f180(int* param)
{
    func_0063023e();
    void* p = func_0062ff50();
    if (p != 0 && *(unsigned char*)((char*)p + 0xe0) != 0)
    {
        param[8] = 0x7918;
        param[9] = 0x7918;
        param[2] = 0x7918;
        param[3] = 0x7918;
    }
    if (IsZoomed((void*)field20) == 0)
    {
        int local1 = 0;
        int local2 = 0;
        func_0040f060(&local1);
        func_00444dc0(&local2);
        int v1 = local1;
        int v2 = local2;
        int local3 = 0;
        int local4 = 0;
        void (__thiscall *fn)(CChildFrame*, int*, int) = *(void(__thiscall**)(CChildFrame*, int*, int))(*(int*)this + 0x70);
        fn(this, &local3, 0);
        param[8] = local3 - v1;
        param[9] = local4 - v2;
    }
}
