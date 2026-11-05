// from server: 50% by colin
// roc 2007-08 00665c30  unit: CRobloxTreeCtrl  size: 858 bytes

extern "C" {
    unsigned int __stdcall GetDlgCtrlID(void* hWnd);
    long __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);
    int __stdcall UpdateWindow(void* hWnd);
}

struct CRobloxTreeCtrl {
    int field0;
    int field4;
    char pad8[0x2c];
    void* field34;
    int sub_665c30(int a, int b, int c);
};

int CRobloxTreeCtrl::sub_665c30(int a, int b, int c)
{
    if (field4 == 0) {
        void* p = field34;
        return ((int (__thiscall*)(void*, int, int, int, int, int, int, int, int))0x63063a)(p, a, 8, 0, 0, 0, b, c, 0);
    }

    void* hwnd = *(void**)((char*)field34 + 0x20);
    int v = SendMessageA(hwnd, 0x110a, 9, 0);

    int flag1 = (v == c) ? 1 : 0;
    int flag2 = 0;
    if (v != 0) {
        int r = ((int (__thiscall*)(void*, int, int))0x73863a)(field34, v, 2);
        flag2 = 1;
        if ((r & 2) == 0)
            flag2 = 0;
    }

    int r2 = ((int (__thiscall*)(void*, int, int))0x73863a)(field34, c, 2);
    int ebp = (r2 >> 1) & 1;

    int eax2 = a & 0xfffffffe;
    int ebx = b & 0xfffffffe;

    int r3 = ((int (__thiscall*)(void*))0x671140)(0);
    int r4 = ((int (__thiscall*)(void*, int))0x671a80)((void*)r3, 0);
    int al = (unsigned char)r4;

    if ((b & 1) != 0) {
        if ((a & 1) != 0) {
            if (al != 0) {
                if (flag2 == 0 && v != 0) {
                    ((void (__thiscall*)(void*, int))0x6653d0)(field34, 0);
                    ((void (__thiscall*)(void*, int, int, int))0x6653f0)(field34, v, 2, 2);
                }
                int r5 = SendMessageA(*(void**)((char*)field34 + 0x20), 0x110b, 9, c);
                if (r5 == 0)
                    return 0;
                if (flag2 == 0 && v != 0) {
                    int t = flag1;
                    t = -t;
                    t = (t >> 31) & 2;
                    ((void (__thiscall*)(void*, int, int, int))0x6653f0)(field34, v, t, 2);
                }
            } else {
                if (flag2 == 0 && flag1 != 0) {
                    ((void (__thiscall*)(void*, int))0x6653d0)(field34, 0);
                    ((void (__thiscall*)(void*, int, int, int))0x6653f0)(field34, v, 2, 2);
                    UpdateWindow(*(void**)((char*)field34 + 0x20));
                }
                int r6 = SendMessageA(*(void**)((char*)field34 + 0x20), 0x110b, 9, c);
                if (r6 == 0)
                    return 0;
            }

            if ((b & 2) != 0) {
                if ((a & 2) == 0)
                    goto L_e88;
                if (al != 0)
                    goto L_e88;
                if (flag2 != 0) {
                    if (flag1 == 0)
                        goto L_e88;
                } else {
                    if (flag1 == 0)
                        goto L_e80;
                }
                goto L_e80;
            } else {
                if (ebp != 0)
                    goto L_e88;
                eax2 &= 0xfffffffd;
                ebx |= 2;
                goto L_e88;
            }
        } else {
            if (flag2 == 0)
                goto L_e88;
            SendMessageA(*(void**)((char*)field34 + 0x20), 0x110b, 9, 0);
            if ((b & 2) != 0) {
                if ((a & 2) == 0)
                    goto L_e88;
                if (ebp == 0)
                    goto L_e80;
                ((void (__thiscall*)(void*, int, int, int))0x6653f0)(field34, c, 2, 2);
                goto L_e88;
            } else {
                if (ebp == 0)
                    goto L_e88;
                ((void (__thiscall*)(void*, int, int, int))0x6653f0)(field34, c, 2, 2);
                goto L_e88;
            }
        }
    }

L_e88:
    if (ebx == 0)
        return 1;

    if ((ebx & 2) == 0)
        goto L_f4b;

    {
        void* hwnd2 = *(void**)((char*)field34 + 0x20);
        int saved = (int)hwnd2;
        int r7 = GetDlgCtrlID(hwnd2);
        int* p;
        int buf1[8];
        int buf2[8];
        buf1[0] = 0;
        buf1[1] = 0;
        buf1[2] = 0;
        buf1[3] = 0;
        buf1[4] = 0;
        buf1[5] = 0;
        buf1[6] = 0;
        buf1[7] = 0;
        buf2[0] = 0;
        buf2[1] = 0;
        buf2[2] = 0;
        buf2[3] = 0;
        buf2[4] = 0;
        buf2[5] = 0;
        buf2[6] = 0;
        buf2[7] = 0;
        if ((eax2 & 2) != 0)
            p = buf1;
        else
            p = buf2;
        p[0] = 0x14;
        p[1] = c;
        int r8 = ((int (__thiscall*)(void*, int))0x6304ae)(field34, c);
        p[9] = r8;
        p[2] = eax2;
        p[3] = ebx;
        int (__thiscall* fn)(void*, int*) = *(int (__thiscall**)(void*, int*))((char*)(*(void**)this) + 0x48);
        int r9 = fn(this, p);
        if (r9 != 0)
            return 0;
        ((void (__thiscall*)(void*, int, int, int))0x6653f0)(field34, c, eax2, ebx);
        int (__thiscall* fn2)(void*, int*) = *(int (__thiscall**)(void*, int*))((char*)(*(void**)this) + 0x48);
        p[3] = 0xfffffe6e;
        fn2(this, p);
        eax2 &= 0xfffffffd;
        ebx &= 0xfffffffd;
    }

L_f4b:
    if (ebx != 0)
        goto L_f5e;

    return 1;

L_f5e:
    {
        void* p = field34;
        return ((int (__thiscall*)(void*, int, int, int, int, int, int, int, int))0x63063a)(p, c, 8, 0, 0, 0, eax2, ebx, 0);
    }

L_e80:
    eax2 &= 0xfffffffd;
    ebx &= 0xfffffffd;
    goto L_e88;
}
