// from server: 100% by EspClaude
// from server: 80% by EspClaude
// roc 2007-08 00432380  unit: CDataModelPropGrid  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00432380
//
// 00432380  8a442404             mov al, byte ptr [esp + 4]
// 00432384  83ec10               sub esp, 0x10
// 00432387  56                   push esi
// 00432388  8bf1                 mov esi, ecx
// 0043238a  3886e0000000         cmp byte ptr [esi + 0xe0], al
// 00432390  0f8483000000         je 0x432419
// 00432396  84c0                 test al, al
// 00432398  8886e0000000         mov byte ptr [esi + 0xe0], al
// 0043239e  742d                 je 0x4323cd
// 004323a0  8b4620               mov eax, dword ptr [esi + 0x20]
// 004323a3  57                   push edi
// 004323a4  8dbe10010000         lea edi, [esi + 0x110]
// 004323aa  57                   push edi
// 004323ab  50                   push eax
// 004323ac  ff15d4ed7700         call dword ptr [0x77edd4]
// 004323b2  57                   push edi
// 004323b3  8d4c240c             lea ecx, [esp + 0xc]
// 004323b7  51                   push ecx
// 004323b8  ff15e0ed7700         call dword ptr [0x77ede0]
// 004323be  8bce                 mov ecx, esi
// 004323c0  e81bfdffff           call 0x4320e0
// 004323c5  5f                   pop edi
// 004323c6  5e                   pop esi
// 004323c7  83c410               add esp, 0x10
// 004323ca  c20400               ret 4
// 004323cd  e82ee4ffff           call 0x430800
// 004323d2  8d9610010000         lea edx, [esi + 0x110]
// 004323d8  52                   push edx
// 004323d9  8d442408             lea eax, [esp + 8]
// 004323dd  50                   push eax
// 004323de  ff15e0ed7700         call dword ptr [0x77ede0]
// 004323e4  8d4c2404             lea ecx, [esp + 4]
// 004323e8  51                   push ecx
// 004323e9  ff15dced7700         call dword ptr [0x77eddc]
// 004323ef  85c0                 test eax, eax
// 004323f1  7526                 jne 0x432419
// 004323f3  8b442408             mov eax, dword ptr [esp + 8]
// 004323f7  8b542410             mov edx, dword ptr [esp + 0x10]
// 004323fb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004323ff  6860020000           push 0x260
// 00432404  2bd0                 sub edx, eax
// 00432406  52                   push edx
// 00432407  8b542414             mov edx, dword ptr [esp + 0x14]
// 0043240b  2bd1                 sub edx, ecx
// 0043240d  52                   push edx
// 0043240e  50                   push eax
// 0043240f  51                   push ecx
// 00432410  6a00                 push 0
// 00432412  8bce                 mov ecx, esi
// 00432414  e815dc1f00           call 0x63002e
// 00432419  5e                   pop esi
// 0043241a  83c410               add esp, 0x10
// 0043241d  c20400               ret 4

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
    char padding24[0xBC];
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
    }
}
