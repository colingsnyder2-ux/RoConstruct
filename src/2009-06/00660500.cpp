// from server: 78% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059dd80  unit: VCRenderSettings::?$EnumPropDescriptor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059dd80
//
// 0059dd80  807c240400           cmp byte ptr [esp + 4], 0
// 0059dd85  56                   push esi
// 0059dd86  0f94c0               sete al
// 0059dd89  8bf1                 mov esi, ecx
// 0059dd8b  88442408             mov byte ptr [esp + 8], al
// 0059dd8f  3a86d3020000         cmp al, byte ptr [esi + 0x2d3]
// 0059dd95  741c                 je 0x59ddb3
// 0059dd97  8b442408             mov eax, dword ptr [esp + 8]
// 0059dd9b  50                   push eax
// 0059dd9c  8d8e28020000         lea ecx, [esi + 0x228]
// 0059dda2  e839980400           call 0x5e75e0
// 0059dda7  6800609700           push 0x976000
// 0059ddac  8bce                 mov ecx, esi
// 0059ddae  e84dfde6ff           call 0x40db00
// 0059ddb3  5e                   pop esi
// 0059ddb4  c20400               ret 4

extern unsigned char property;

struct Value {
    unsigned char padding[0xAB];
    unsigned char value;

    void setValue(unsigned char v);
};

struct Settings {
    unsigned char padding[0x228];
    Value setting;

    void notify(void*);
    void setEnabled(unsigned char v);
};

void Settings::setEnabled(unsigned char v)
{
    v = !v;
    if (v != setting.value) {
        setting.setValue(v);
        notify(&property);
    }
}
