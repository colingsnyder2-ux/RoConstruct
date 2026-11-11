// from server: 100% by EspClaude
// from server: 77% by colin
// roc 2007-08 006a8010  unit: CXTPRibbonBar  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a8010
//
// 006a8010  56                   push esi
// 006a8011  8bf1                 mov esi, ecx
// 006a8013  83c8ff               or eax, 0xffffffff
// 006a8016  0bc8                 or ecx, eax
// 006a8018  51                   push ecx
// 006a8019  8b8e64020000         mov ecx, dword ptr [esi + 0x264]
// 006a801f  50                   push eax
// 006a8020  8b4620               mov eax, dword ptr [esi + 0x20]
// 006a8023  50                   push eax
// 006a8024  81c178010000         add ecx, 0x178
// 006a802a  e8c16b0500           call 0x6febf0
// 006a802f  83be7402000000       cmp dword ptr [esi + 0x274], 0
// 006a8036  741a                 je 0x6a8052
// 006a8038  8b16                 mov edx, dword ptr [esi]
// 006a803a  8b829c010000         mov eax, dword ptr [edx + 0x19c]
// 006a8040  6a01                 push 1
// 006a8042  6a00                 push 0
// 006a8044  8bce                 mov ecx, esi
// 006a8046  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 006a8050  ffd0                 call eax
// 006a8052  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a8056  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006a805a  8b442408             mov eax, dword ptr [esp + 8]
// 006a805e  51                   push ecx
// 006a805f  52                   push edx
// 006a8060  50                   push eax
// 006a8061  8bce                 mov ecx, esi
// 006a8063  e8b8edf9ff           call 0x646e20

struct Pt { int x; int y; };

struct Sub178
{
    void sub_6febf0(int, Pt);
};

struct CXTPRibbonBar
{
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
    virtual void v(int, int);
    void sub_646e20(int, int, int);
    void func_006a8010(int, int, int);
};

typedef void (__thiscall CXTPRibbonBar::*VFn)(int, int);

void CXTPRibbonBar::func_006a8010(int a1, int a2, int a3)
{
    Sub178* p = (Sub178*)(*(char**)((char*)this + 0x264) + 0x178);
    Pt pt; pt.x = -1; pt.y = -1;
    p->sub_6febf0(*(int*)((char*)this + 0x20), pt);

    if (*(int*)((char*)this + 0x274) != 0)
    {
        *(int*)((char*)this + 0x274) = 0;
        v(0, 1);
    }

    sub_646e20(a1, a2, a3);
}
