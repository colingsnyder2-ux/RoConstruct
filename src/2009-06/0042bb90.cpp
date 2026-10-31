// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00431b40  unit: CDataModelPropGrid  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00431b40
//
// 00431b40  8a442404             mov al, byte ptr [esp + 4]
// 00431b44  83ec10               sub esp, 0x10
// 00431b47  56                   push esi
// 00431b48  8bf1                 mov esi, ecx
// 00431b4a  3886f8000000         cmp byte ptr [esi + 0xf8], al
// 00431b50  0f848c000000         je 0x431be2
// 00431b56  8886f8000000         mov byte ptr [esi + 0xf8], al
// 00431b5c  84c0                 test al, al
// 00431b5e  7428                 je 0x431b88
// 00431b60  8b4620               mov eax, dword ptr [esi + 0x20]
// 00431b63  57                   push edi
// 00431b64  8dbe28010000         lea edi, [esi + 0x128]
// 00431b6a  57                   push edi
// 00431b6b  50                   push eax
// 00431b6c  ff15342e8000         call dword ptr [0x802e34]
// 00431b72  57                   push edi
// 00431b73  8d4c240c             lea ecx, [esp + 0xc]
// 00431b77  51                   push ecx
// 00431b78  ff15702d8000         call dword ptr [0x802d70]
// 00431b7e  8bce                 mov ecx, esi
// 00431b80  e82bfdffff           call 0x4318b0
// 00431b85  5f                   pop edi
// 00431b86  eb4c                 jmp 0x431bd4
// 00431b88  e8d3e5ffff           call 0x430160
// 00431b8d  8d9628010000         lea edx, [esi + 0x128]
// 00431b93  52                   push edx
// 00431b94  8d442408             lea eax, [esp + 8]
// 00431b98  50                   push eax
// 00431b99  ff15702d8000         call dword ptr [0x802d70]
// 00431b9f  8d4c2404             lea ecx, [esp + 4]
// 00431ba3  51                   push ecx
// 00431ba4  ff156c2d8000         call dword ptr [0x802d6c]
// 00431baa  85c0                 test eax, eax
// 00431bac  7526                 jne 0x431bd4
// 00431bae  8b442408             mov eax, dword ptr [esp + 8]
// 00431bb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00431bb6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00431bba  6860020000           push 0x260
// 00431bbf  2bd0                 sub edx, eax
// 00431bc1  52                   push edx
// 00431bc2  8b542414             mov edx, dword ptr [esp + 0x14]
// 00431bc6  2bd1                 sub edx, ecx
// 00431bc8  52                   push edx
// 00431bc9  50                   push eax
// 00431bca  51                   push ecx
// 00431bcb  6a00                 push 0
// 00431bcd  8bce                 mov ecx, esi
// 00431bcf  e872ee2600           call 0x6a0a46
// 00431bd4  8b06                 mov eax, dword ptr [esi]
// 00431bd6  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 00431bdc  6a01                 push 1
// 00431bde  8bce                 mov ecx, esi
// 00431be0  ffd2                 call edx
// 00431be2  5e                   pop esi
// 00431be3  83c410               add esp, 0x10
// 00431be6  c20400               ret 4

struct Rect {
    int left, top, right, bottom;
};

extern "C" {
    extern int (__stdcall *GetWindowRect)(void *, Rect *);
    extern int (__stdcall *CopyRect)(Rect *, const Rect *);
    extern int (__stdcall *IsRectEmpty)(const Rect *);
}

struct CDataModelPropGrid;

struct PropGridVTable {
    char padding[0x158];
    void (__thiscall *update)(CDataModelPropGrid *, int);
};

struct CDataModelPropGrid {
    PropGridVTable *vtable;
    char padding04[0x1C];
    void *window;
    char padding24[0xD4];
    unsigned char flagF8;
    char paddingF9[0x2F];
    Rect savedRect;

    void restore();
    void configure();
    void position(void *, int, int, int, int, unsigned int);
    void f(unsigned char);
};

void CDataModelPropGrid::f(unsigned char value)
{
    Rect rect;

    if (flagF8 != value) {
        flagF8 = value;

        if (value) {
            GetWindowRect(window, &savedRect);
            CopyRect(&rect, &savedRect);
            configure();
        } else {
            restore();
            CopyRect(&rect, &savedRect);
            if (!IsRectEmpty(&rect)) {
                position(0, rect.left, rect.top,
                         rect.right - rect.left,
                         rect.bottom - rect.top, 0x260);
            }
        }

        vtable->update(this, 1);
    }
}
