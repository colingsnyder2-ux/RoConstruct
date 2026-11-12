// from server: 97% by EspClaude
// from server: 54% by colin
// roc 2007-08 00420430  unit: CRobloxTreeCtrl  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00420430
//
// 00420430  83ec08               sub esp, 8
// 00420433  53                   push ebx
// 00420434  56                   push esi
// 00420435  8bf1                 mov esi, ecx
// 00420437  e8348b2400           call 0x668f70
// 0042043c  6a0f                 push 0xf
// 0042043e  8bc8                 mov ecx, eax
// 00420440  e82b832400           call 0x668770
// 00420445  8bd8                 mov ebx, eax
// 00420447  e8248b2400           call 0x668f70
// 0042044c  6a0d                 push 0xd
// 0042044e  8bc8                 mov ecx, eax
// 00420450  e81b832400           call 0x668770
// 00420455  8bc8                 mov ecx, eax
// 00420457  c1e810               shr eax, 0x10
// 0042045a  0fb6c0               movzx eax, al
// 0042045d  8bd3                 mov edx, ebx
// 0042045f  c1ea10               shr edx, 0x10
// 00420462  0fb6d2               movzx edx, dl
// 00420465  03c2                 add eax, edx
// 00420467  99                   cdq 
// 00420468  2bc2                 sub eax, edx
// 0042046a  d1f8                 sar eax, 1
// 0042046c  33d2                 xor edx, edx
// 0042046e  8af0                 mov dh, al
// 00420470  894c240c             mov dword ptr [esp + 0xc], ecx
// 00420474  0fb6c5               movzx eax, ch
// 00420477  0fb6cf               movzx ecx, bh
// 0042047a  03c1                 add eax, ecx
// 0042047c  8bca                 mov ecx, edx
// 0042047e  99                   cdq 
// 0042047f  2bc2                 sub eax, edx
// 00420481  0fb654240c           movzx edx, byte ptr [esp + 0xc]
// 00420486  d1f8                 sar eax, 1
// 00420488  8ac8                 mov cl, al
// 0042048a  0fb6c3               movzx eax, bl
// 0042048d  03c2                 add eax, edx
// 0042048f  99                   cdq 
// 00420490  2bc2                 sub eax, edx
// 00420492  d1f8                 sar eax, 1
// 00420494  0fb6c0               movzx eax, al
// 00420497  c1e108               shl ecx, 8
// 0042049a  0bc8                 or ecx, eax
// 0042049c  51                   push ecx
// 0042049d  6a0f                 push 0xf
// 0042049f  e8cc8a2400           call 0x668f70
// 004204a4  8bc8                 mov ecx, eax
// 004204a6  e825852400           call 0x6689d0
// 004204ab  8bce                 mov ecx, esi
// 004204ad  e89ef7ffff           call 0x41fc50
// 004204b2  53                   push ebx
// 004204b3  6a0f                 push 0xf
// 004204b5  e8b68a2400           call 0x668f70
// 004204ba  8bc8                 mov ecx, eax
// 004204bc  e80f852400           call 0x6689d0
// 004204c1  5e                   pop esi
// 004204c2  5b                   pop ebx
// 004204c3  83c408               add esp, 8
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef DWORD COLORREF;
#define RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb) ((BYTE)(rgb))
#define GetGValue(rgb) ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb) ((BYTE)((rgb)>>16))

struct CPaintManagerColors {
    COLORREF GetColor(int index);
    void SetColor(int index, COLORREF clr);
};
CPaintManagerColors* sub_668F70();

struct CRobloxTreeCtrl {
    void sub_41FC50();
    void sub_420430();
};

void CRobloxTreeCtrl::sub_420430() {
    COLORREF clrWindow = sub_668F70()->GetColor(0xF);
    COLORREF clrOther = sub_668F70()->GetColor(0xD);
    sub_668F70()->SetColor(0xF, RGB((GetRValue(clrOther) + GetRValue(clrWindow)) / 2,
                                    (GetGValue(clrWindow) + GetGValue(clrOther)) / 2,
                                    (GetBValue(clrWindow) + GetBValue(clrOther)) / 2));
    sub_41FC50();
    sub_668F70()->SetColor(0xF, clrWindow);
}
