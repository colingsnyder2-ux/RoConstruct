// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00433ef0  unit: CMemberTreeView  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00433ef0
//
// 00433ef0  83ec40               sub esp, 0x40
// 00433ef3  53                   push ebx
// 00433ef4  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 00433ef8  56                   push esi
// 00433ef9  8bf1                 mov esi, ecx
// 00433efb  85db                 test ebx, ebx
// 00433efd  0f84ae000000         je 0x433fb1
// 00433f03  80bb3101000000       cmp byte ptr [ebx + 0x131], 0
// 00433f0a  55                   push ebp
// 00433f0b  8b2d54218000         mov ebp, dword ptr [0x802154]
// 00433f11  57                   push edi
// 00433f12  8b3d142e8000         mov edi, dword ptr [0x802e14]
// 00433f18  7446                 je 0x433f60
// 00433f1a  8d4c2410             lea ecx, [esp + 0x10]
// 00433f1e  e8fdbf2d00           call 0x70ff20
// 00433f23  8b4620               mov eax, dword ptr [esi + 0x20]
// 00433f26  6a00                 push 0
// 00433f28  6a00                 push 0
// 00433f2a  6a31                 push 0x31
// 00433f2c  50                   push eax
// 00433f2d  ffd7                 call edi
// 00433f2f  50                   push eax
// 00433f30  e895d12600           call 0x6a10ca
// 00433f35  8b5004               mov edx, dword ptr [eax + 4]
// 00433f38  8d4c2410             lea ecx, [esp + 0x10]
// 00433f3c  51                   push ecx
// 00433f3d  6a3c                 push 0x3c
// 00433f3f  52                   push edx
// 00433f40  ffd5                 call ebp
// 00433f42  85c0                 test eax, eax
// 00433f44  741a                 je 0x433f60
// 00433f46  8b4660               mov eax, dword ptr [esi + 0x60]
// 00433f49  8b401c               mov eax, dword ptr [eax + 0x1c]
// 00433f4c  8d542410             lea edx, [esp + 0x10]
// 00433f50  8d4e60               lea ecx, [esi + 0x60]
// 00433f53  52                   push edx
// 00433f54  8b542458             mov edx, dword ptr [esp + 0x58]
// 00433f58  52                   push edx
// 00433f59  c644242e01           mov byte ptr [esp + 0x2e], 1
// 00433f5e  ffd0                 call eax
// 00433f60  80bb3201000000       cmp byte ptr [ebx + 0x132], 0
// 00433f67  7446                 je 0x433faf
// 00433f69  8d4c2410             lea ecx, [esp + 0x10]
// 00433f6d  e8aebf2d00           call 0x70ff20
// 00433f72  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00433f75  6a00                 push 0
// 00433f77  6a00                 push 0
// 00433f79  6a31                 push 0x31
// 00433f7b  51                   push ecx
// 00433f7c  ffd7                 call edi
// 00433f7e  50                   push eax
// 00433f7f  e846d12600           call 0x6a10ca
// 00433f84  8b4004               mov eax, dword ptr [eax + 4]
// 00433f87  8d542410             lea edx, [esp + 0x10]
// 00433f8b  52                   push edx
// 00433f8c  6a3c                 push 0x3c
// 00433f8e  50                   push eax
// 00433f8f  ffd5                 call ebp
// 00433f91  85c0                 test eax, eax
// 00433f93  741a                 je 0x433faf
// 00433f95  8b5660               mov edx, dword ptr [esi + 0x60]
// 00433f98  8b521c               mov edx, dword ptr [edx + 0x1c]
// 00433f9b  8d442410             lea eax, [esp + 0x10]
// 00433f9f  8d4e60               lea ecx, [esi + 0x60]
// 00433fa2  50                   push eax
// 00433fa3  8b442458             mov eax, dword ptr [esp + 0x58]
// 00433fa7  50                   push eax
// 00433fa8  c644242c01           mov byte ptr [esp + 0x2c], 1
// 00433fad  ffd2                 call edx
// 00433faf  5f                   pop edi
// 00433fb0  5d                   pop ebp
// 00433fb1  5e                   pop esi
// 00433fb2  5b                   pop ebx
// 00433fb3  83c440               add esp, 0x40
// 00433fb6  c20800               ret 8

struct FontData {
    long height;
    long width;
    long escapement;
    long orientation;
    long weight;
    unsigned char italic;
    unsigned char underline;
    unsigned char strikeOut;
    unsigned char charSet;
    unsigned char outPrecision;
    unsigned char clipPrecision;
    unsigned char quality;
    unsigned char pitchAndFamily;
    char faceName[32];
    unsigned long extra;

    FontData();
};

struct Font {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int setFont(void*, FontData*);

    void* handle;
};

struct Node {
    char padding[0x131];
    unsigned char strikeOut;
    unsigned char italic;
};

extern "C" {
    extern long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);
    extern int (__stdcall *GetObjectA)(void*, int, void*);
}

Font* __stdcall fontFromHandle(long);

struct S {
    char padding0[0x20];
    void* window;
    char padding1[0x3c];
    Font font;

    void updateFont(void*, Node*);
};

void S::updateFont(void* item, Node* node)
{
    if (!node)
        return;

    long (__stdcall *sendMessage)(void*, unsigned int, unsigned int, long) = SendMessageA;
    int (__stdcall *getObject)(void*, int, void*) = GetObjectA;

    if (node->strikeOut) {
        FontData data;
        Font* source = fontFromHandle(sendMessage(window, 0x31, 0, 0));
        if (getObject(source->handle, 60, &data)) {
            data.strikeOut = 1;
            font.setFont(item, &data);
        }
    }

    if (node->italic) {
        FontData data;
        Font* source = fontFromHandle(sendMessage(window, 0x31, 0, 0));
        if (getObject(source->handle, 60, &data)) {
            data.italic = 1;
            font.setFont(item, &data);
        }
    }
}
