// from server: 91% by EspClaude
// from server: 73% by colin
// roc 2007-08 006a7f90  unit: CXTPRibbonBar  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a7f90
//
// 006a7f90  83ec10               sub esp, 0x10
// 006a7f93  56                   push esi
// 006a7f94  8bf1                 mov esi, ecx
// 006a7f96  8b8664020000         mov eax, dword ptr [esi + 0x264]
// 006a7f9c  85c0                 test eax, eax
// 006a7f9e  7416                 je 0x6a7fb6
// 006a7fa0  83c9ff               or ecx, 0xffffffff
// 006a7fa3  0bd1                 or edx, ecx
// 006a7fa5  52                   push edx
// 006a7fa6  51                   push ecx
// 006a7fa7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006a7faa  51                   push ecx
// 006a7fab  8d8878010000         lea ecx, [eax + 0x178]
// 006a7fb1  e83a6c0500           call 0x6febf0
// 006a7fb6  8b8674020000         mov eax, dword ptr [esi + 0x274]
// 006a7fbc  85c0                 test eax, eax
// 006a7fbe  7439                 je 0x6a7ff9
// 006a7fc0  8b5034               mov edx, dword ptr [eax + 0x34]
// 006a7fc3  89542404             mov dword ptr [esp + 4], edx
// 006a7fc7  8b4838               mov ecx, dword ptr [eax + 0x38]
// 006a7fca  894c2408             mov dword ptr [esp + 8], ecx
// 006a7fce  8b503c               mov edx, dword ptr [eax + 0x3c]
// 006a7fd1  8954240c             mov dword ptr [esp + 0xc], edx
// 006a7fd5  8b4040               mov eax, dword ptr [eax + 0x40]
// 006a7fd8  8b16                 mov edx, dword ptr [esi]
// 006a7fda  8b929c010000         mov edx, dword ptr [edx + 0x19c]
// 006a7fe0  89442410             mov dword ptr [esp + 0x10], eax
// 006a7fe4  6a01                 push 1
// 006a7fe6  8d442408             lea eax, [esp + 8]
// 006a7fea  50                   push eax
// 006a7feb  8bce                 mov ecx, esi
// 006a7fed  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 006a7ff7  ffd2                 call edx
// 006a7ff9  8bce                 mov ecx, esi
// 006a7ffb  5e                   pop esi
// 006a7ffc  83c410               add esp, 0x10
// 006a7fff  e9dcc3f9ff           jmp 0x6443e0

struct Pt { int x; int y; };
struct Rc { int l, t, r, b; };

struct Helper178 {
    void sub_6FEBF0(int, Pt);
};

struct Obj274 {
    char pad[0x34];
    Rc rc;
};

struct CXTPRibbonBar {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void pad59();
    virtual void pad60();
    virtual void pad61();
    virtual void pad62();
    virtual void pad63();
    virtual void pad64();
    virtual void pad65();
    virtual void pad66();
    virtual void pad67();
    virtual void pad68();
    virtual void pad69();
    virtual void pad70();
    virtual void pad71();
    virtual void pad72();
    virtual void pad73();
    virtual void pad74();
    virtual void pad75();
    virtual void pad76();
    virtual void pad77();
    virtual void pad78();
    virtual void pad79();
    virtual void pad80();
    virtual void pad81();
    virtual void pad82();
    virtual void pad83();
    virtual void pad84();
    virtual void pad85();
    virtual void pad86();
    virtual void pad87();
    virtual void pad88();
    virtual void pad89();
    virtual void pad90();
    virtual void pad91();
    virtual void pad92();
    virtual void pad93();
    virtual void pad94();
    virtual void pad95();
    virtual void pad96();
    virtual void pad97();
    virtual void pad98();
    virtual void pad99();
    virtual void pad100();
    virtual void pad101();
    virtual void pad102();
    virtual void v(Rc*, int);
    void sub_6443E0();
    void sub_6A7F90();
};

void CXTPRibbonBar::sub_6A7F90() {
    char* p264 = *(char**)((char*)this + 0x264);
    if (p264 != 0) {
        Pt pt; pt.x = -1; pt.y = -1;
        ((Helper178*)(p264 + 0x178))->sub_6FEBF0(*(int*)((char*)this + 0x20), pt);
    }
    Obj274* p274 = *(Obj274**)((char*)this + 0x274);
    if (p274 != 0) {
        Rc rc = p274->rc;
        *(Obj274**)((char*)this + 0x274) = 0;
        v(&rc, 1);
    }
    sub_6443E0();
}
