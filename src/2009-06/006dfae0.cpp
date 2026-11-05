// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064e840  unit: RBX::UnifiedImageWidget  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064e840
//
// 0064e840  83ec10               sub esp, 0x10
// 0064e843  56                   push esi
// 0064e844  8bf1                 mov esi, ecx
// 0064e846  8b06                 mov eax, dword ptr [esi]
// 0064e848  8b5054               mov edx, dword ptr [eax + 0x54]
// 0064e84b  ffd2                 call edx
// 0064e84d  84c0                 test al, al
// 0064e84f  7444                 je 0x64e895
// 0064e851  8b8644010000         mov eax, dword ptr [esi + 0x144]
// 0064e857  83f801               cmp eax, 1
// 0064e85a  7414                 je 0x64e870
// 0064e85c  83c0fe               add eax, -2
// 0064e85f  b901000000           mov ecx, 1
// 0064e864  3bc8                 cmp ecx, eax
// 0064e866  1bc0                 sbb eax, eax
// 0064e868  83e0fe               and eax, 0xfffffffe
// 0064e86b  83c002               add eax, 2
// 0064e86e  eb05                 jmp 0x64e875
// 0064e870  b801000000           mov eax, 1
// 0064e875  50                   push eax
// 0064e876  8d542408             lea edx, [esp + 8]
// 0064e87a  52                   push edx
// 0064e87b  8bce                 mov ecx, esi
// 0064e87d  e88e4af2ff           call 0x573310
// 0064e882  50                   push eax
// 0064e883  8b442420             mov eax, dword ptr [esp + 0x20]
// 0064e887  6a01                 push 1
// 0064e889  50                   push eax
// 0064e88a  8d8e48010000         lea ecx, [esi + 0x148]
// 0064e890  e84b45ffff           call 0x642de0
// 0064e895  5e                   pop esi
// 0064e896  83c410               add esp, 0x10
// 0064e899  c20400               ret 4

struct Color {
    float r, g, b, a;
    Color();
};

struct Image {
    void draw(void* context, bool enabled, const Color& color);
};

struct Widget {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual bool visible();

    char padding[0x9c];
    int state;
    Image image;

    Color getColor(int mode);
    void draw(void* context);
};

void Widget::draw(void* context)
{
    if (visible()) {
        int mode;
        switch (state) {
        case 1:
            mode = 1;
            break;
        case 2:
        case 3:
            mode = 2;
            break;
        default:
            mode = 0;
            break;
        }
        image.draw((&context)[1], true, getColor(mode));
    }
}
