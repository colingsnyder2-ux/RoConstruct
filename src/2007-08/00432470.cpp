// from server: 100% by Intel
// from server: 96% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00431c40  unit: CDataModelPropGrid  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00431c40
//
// 00431c40  83ec10               sub esp, 0x10
// 00431c43  53                   push ebx
// 00431c44  56                   push esi
// 00431c45  57                   push edi
// 00431c46  8bf1                 mov esi, ecx
// 00431c48  e81bf02600           call 0x6a0c68
// 00431c4d  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00431c51  33db                 xor ebx, ebx
// 00431c53  389ef8000000         cmp byte ptr [esi + 0xf8], bl
// 00431c59  7406                 je 0x431c61
// 00431c5b  895f10               mov dword ptr [edi + 0x10], ebx
// 00431c5e  895f14               mov dword ptr [edi + 0x14], ebx
// 00431c61  389efa000000         cmp byte ptr [esi + 0xfa], bl
// 00431c67  7566                 jne 0x431ccf
// 00431c69  389ef8000000         cmp byte ptr [esi + 0xf8], bl
// 00431c6f  755e                 jne 0x431ccf
// 00431c71  389e04010000         cmp byte ptr [esi + 0x104], bl
// 00431c77  7456                 je 0x431ccf
// 00431c79  8d442420             lea eax, [esp + 0x20]
// 00431c7d  50                   push eax
// 00431c7e  e8cd10feff           call 0x412d50
// 00431c83  8bc8                 mov ecx, eax
// 00431c85  e8c6350100           call 0x445250
// 00431c8a  0fbf4c2420           movsx ecx, word ptr [esp + 0x20]
// 00431c8f  0fbf542422           movsx edx, word ptr [esp + 0x22]
// 00431c94  8b06                 mov eax, dword ptr [esi]
// 00431c96  894c2414             mov dword ptr [esp + 0x14], ecx
// 00431c9a  53                   push ebx
// 00431c9b  8d4c2410             lea ecx, [esp + 0x10]
// 00431c9f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00431ca3  8b5070               mov edx, dword ptr [eax + 0x70]
// 00431ca6  51                   push ecx
// 00431ca7  8bce                 mov ecx, esi
// 00431ca9  895c2414             mov dword ptr [esp + 0x14], ebx
// 00431cad  895c2418             mov dword ptr [esp + 0x18], ebx
// 00431cb1  ffd2                 call edx
// 00431cb3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00431cb7  2b44240c             sub eax, dword ptr [esp + 0xc]
// 00431cbb  894720               mov dword ptr [edi + 0x20], eax
// 00431cbe  894708               mov dword ptr [edi + 8], eax
// 00431cc1  8b442418             mov eax, dword ptr [esp + 0x18]
// 00431cc5  2b442410             sub eax, dword ptr [esp + 0x10]
// 00431cc9  894724               mov dword ptr [edi + 0x24], eax
// 00431ccc  89470c               mov dword ptr [edi + 0xc], eax
// 00431ccf  5f                   pop edi
// 00431cd0  5e                   pop esi
// 00431cd1  5b                   pop ebx
// 00431cd2  83c410               add esp, 0x10
// 00431cd5  c20400               ret 4

struct Rect {
    int left, top, right, bottom;
};

struct Info {
    int unused0[2];
    int width, height;
    int minWidth, minHeight;
    int unused1[2];
    int maxWidth, maxHeight;
};

struct Object {
    int get_19c(int *out);
};

extern "C" Object *__cdecl getObject();

struct CDataModelPropGrid {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void adjust(Rect *, int);

    char pad0[0xDC];
    unsigned char flagF8;
    unsigned char flagFA;
    char padFB[10];
    unsigned char flag104;

    void prepare();
    void f(Info *);
};

void CDataModelPropGrid::f(Info *p) {
    prepare();
    Info *out = p;
    if (flagF8) {
        out->minWidth = 0;
        out->minHeight = 0;
    }
    if (!flagFA && !flagF8 && flag104) {
        getObject()->get_19c((int *)&p);
        Rect r;
        r.right = ((short *)&p)[0];
        r.bottom = ((short *)&p)[1];
        r.left = 0;
        r.top = 0;
        adjust(&r, 0);
        out->maxWidth = r.right - r.left;
        out->width = r.right - r.left;
        out->maxHeight = r.bottom - r.top;
        out->height = r.bottom - r.top;
    }
}
