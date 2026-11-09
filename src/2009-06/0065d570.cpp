// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059acb0  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 503 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059acb0
//
// 0059acb0  83ec30               sub esp, 0x30
// 0059acb3  56                   push esi
// 0059acb4  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0059acb8  57                   push edi
// 0059acb9  8bf9                 mov edi, ecx
// 0059acbb  8bce                 mov ecx, esi
// 0059acbd  e84e1bfeff           call 0x57c810
// 0059acc2  84c0                 test al, al
// 0059acc4  0f85d5010000         jne 0x59ae9f
// 0059acca  8d4c2408             lea ecx, [esp + 8]
// 0059acce  e8fdd5edff           call 0x4782d0
// 0059acd3  8b0d34539700         mov ecx, dword ptr [0x975334]
// 0059acd9  8d442440             lea eax, [esp + 0x40]
// 0059acdd  50                   push eax
// 0059acde  51                   push ecx
// 0059acdf  8bce                 mov ecx, esi
// 0059ace1  e84a15feff           call 0x57c230
// 0059ace6  8bc8                 mov ecx, eax
// 0059ace8  83c110               add ecx, 0x10
// 0059aceb  e82019feff           call 0x57c610
// 0059acf0  d9442440             fld dword ptr [esp + 0x40]
// 0059acf4  a180539700           mov eax, dword ptr [0x975380]
// 0059acf9  d95c242c             fstp dword ptr [esp + 0x2c]
// 0059acfd  8d542440             lea edx, [esp + 0x40]
// 0059ad01  52                   push edx
// 0059ad02  50                   push eax
// 0059ad03  8bce                 mov ecx, esi
// 0059ad05  e82615feff           call 0x57c230
// 0059ad0a  8bc8                 mov ecx, eax
// 0059ad0c  83c110               add ecx, 0x10
// 0059ad0f  e8fc18feff           call 0x57c610
// 0059ad14  d9442440             fld dword ptr [esp + 0x40]
// 0059ad18  8b1518539700         mov edx, dword ptr [0x975318]
// 0059ad1e  d95c2430             fstp dword ptr [esp + 0x30]
// 0059ad22  8d4c2440             lea ecx, [esp + 0x40]
// 0059ad26  51                   push ecx
// 0059ad27  52                   push edx
// 0059ad28  8bce                 mov ecx, esi
// 0059ad2a  e80115feff           call 0x57c230
// 0059ad2f  8bc8                 mov ecx, eax
// 0059ad31  83c110               add ecx, 0x10
// 0059ad34  e8d718feff           call 0x57c610
// 0059ad39  d9442440             fld dword ptr [esp + 0x40]
// 0059ad3d  8b0d50539700         mov ecx, dword ptr [0x975350]
// 0059ad43  d95c2434             fstp dword ptr [esp + 0x34]
// 0059ad47  8d442440             lea eax, [esp + 0x40]
// 0059ad4b  50                   push eax
// 0059ad4c  51                   push ecx
// 0059ad4d  8bce                 mov ecx, esi
// 0059ad4f  e8dc14feff           call 0x57c230
// 0059ad54  8bc8                 mov ecx, eax
// 0059ad56  83c110               add ecx, 0x10
// 0059ad59  e8b218feff           call 0x57c610
// 0059ad5e  d9442440             fld dword ptr [esp + 0x40]
// 0059ad62  a168539700           mov eax, dword ptr [0x975368]
// 0059ad67  d95c2408             fstp dword ptr [esp + 8]
// 0059ad6b  8d542440             lea edx, [esp + 0x40]
// 0059ad6f  52                   push edx
// 0059ad70  50                   push eax
// 0059ad71  8bce                 mov ecx, esi
// 0059ad73  e8b814feff           call 0x57c230
// 0059ad78  8bc8                 mov ecx, eax
// 0059ad7a  83c110               add ecx, 0x10
// 0059ad7d  e88e18feff           call 0x57c610
// 0059ad82  d9442440             fld dword ptr [esp + 0x40]
// 0059ad86  8b1504539700         mov edx, dword ptr [0x975304]
// 0059ad8c  d95c240c             fstp dword ptr [esp + 0xc]
// 0059ad90  8d4c2440             lea ecx, [esp + 0x40]
// 0059ad94  51                   push ecx
// 0059ad95  52                   push edx
// 0059ad96  8bce                 mov ecx, esi
// 0059ad98  e89314feff           call 0x57c230
// 0059ad9d  8bc8                 mov ecx, eax
// 0059ad9f  83c110               add ecx, 0x10
// 0059ada2  e86918feff           call 0x57c610
// 0059ada7  d9442440             fld dword ptr [esp + 0x40]
// 0059adab  8b0d28539700         mov ecx, dword ptr [0x975328]
// 0059adb1  d95c2410             fstp dword ptr [esp + 0x10]
// 0059adb5  8d442440             lea eax, [esp + 0x40]
// 0059adb9  50                   push eax
// 0059adba  51                   push ecx
// 0059adbb  8bce                 mov ecx, esi
// 0059adbd  e86e14feff           call 0x57c230
// 0059adc2  8bc8                 mov ecx, eax
// 0059adc4  83c110               add ecx, 0x10
// 0059adc7  e84418feff           call 0x57c610
// 0059adcc  d9442440             fld dword ptr [esp + 0x40]
// 0059add0  8d542440             lea edx, [esp + 0x40]
// 0059add4  d95c2414             fstp dword ptr [esp + 0x14]
// 0059add8  52                   push edx
// 0059add9  a154539700           mov eax, dword ptr [0x975354]
// 0059adde  50                   push eax
// 0059addf  8bce                 mov ecx, esi
// 0059ade1  e84a14feff           call 0x57c230
// 0059ade6  8bc8                 mov ecx, eax
// 0059ade8  83c110               add ecx, 0x10
// 0059adeb  e82018feff           call 0x57c610
// 0059adf0  d9442440             fld dword ptr [esp + 0x40]
// 0059adf4  8b1548539700         mov edx, dword ptr [0x975348]
// 0059adfa  d95c2418             fstp dword ptr [esp + 0x18]
// 0059adfe  8d4c2440             lea ecx, [esp + 0x40]
// 0059ae02  51                   push ecx
// 0059ae03  52                   push edx
// 0059ae04  8bce                 mov ecx, esi
// 0059ae06  e82514feff           call 0x57c230
// 0059ae0b  8bc8                 mov ecx, eax
// 0059ae0d  83c110               add ecx, 0x10
// 0059ae10  e8fb17feff           call 0x57c610
// 0059ae15  d9442440             fld dword ptr [esp + 0x40]
// 0059ae19  8b0d24539700         mov ecx, dword ptr [0x975324]
// 0059ae1f  d95c241c             fstp dword ptr [esp + 0x1c]
// 0059ae23  8d442440             lea eax, [esp + 0x40]
// 0059ae27  50                   push eax
// 0059ae28  51                   push ecx
// 0059ae29  8bce                 mov ecx, esi
// 0059ae2b  e80014feff           call 0x57c230
// 0059ae30  8bc8                 mov ecx, eax
// 0059ae32  83c110               add ecx, 0x10
// 0059ae35  e8d617feff           call 0x57c610
// 0059ae3a  d9442440             fld dword ptr [esp + 0x40]
// 0059ae3e  a120539700           mov eax, dword ptr [0x975320]
// 0059ae43  d95c2420             fstp dword ptr [esp + 0x20]
// 0059ae47  8d542440             lea edx, [esp + 0x40]
// 0059ae4b  52                   push edx
// 0059ae4c  50                   push eax
// 0059ae4d  8bce                 mov ecx, esi
// 0059ae4f  e8dc13feff           call 0x57c230
// 0059ae54  8bc8                 mov ecx, eax
// 0059ae56  83c110               add ecx, 0x10
// 0059ae59  e8b217feff           call 0x57c610
// 0059ae5e  d9442440             fld dword ptr [esp + 0x40]
// 0059ae62  8b1508539700         mov edx, dword ptr [0x975308]
// 0059ae68  d95c2424             fstp dword ptr [esp + 0x24]
// 0059ae6c  8d4c2440             lea ecx, [esp + 0x40]
// 0059ae70  51                   push ecx
// 0059ae71  52                   push edx
// 0059ae72  8bce                 mov ecx, esi
// 0059ae74  e8b713feff           call 0x57c230
// 0059ae79  8bc8                 mov ecx, eax
// 0059ae7b  83c110               add ecx, 0x10
// 0059ae7e  e88d17feff           call 0x57c610
// 0059ae83  d9442440             fld dword ptr [esp + 0x40]
// 0059ae87  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0059ae8a  d95c2428             fstp dword ptr [esp + 0x28]
// 0059ae8e  8b01                 mov eax, dword ptr [ecx]
// 0059ae90  8b400c               mov eax, dword ptr [eax + 0xc]
// 0059ae93  8d542408             lea edx, [esp + 8]
// 0059ae97  52                   push edx
// 0059ae98  8b542440             mov edx, dword ptr [esp + 0x40]
// 0059ae9c  52                   push edx
// 0059ae9d  ffd0                 call eax
// 0059ae9f  5f                   pop edi
// 0059aea0  5e                   pop esi
// 0059aea1  83c430               add esp, 0x30
// 0059aea4  c20c00               ret 0xc

struct Frame {
    float rotation[9];
    float position[3];
    Frame();
};

struct Value {
    bool toFloat(float* result);
};

struct Entry {
    unsigned char padding[16];
    Value value;
};

struct Element {
    bool isNull();
    Entry* find(unsigned int name);
};

extern unsigned int name975334;
extern unsigned int name975380;
extern unsigned int name975318;
extern unsigned int name975350;
extern unsigned int name975368;
extern unsigned int name975304;
extern unsigned int name975328;
extern unsigned int name975354;
extern unsigned int name975348;
extern unsigned int name975324;
extern unsigned int name975320;
extern unsigned int name975308;

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, const Frame& value);
};

struct Descriptor {
    unsigned char padding[24];
    Setter* setter;
    void read(void* instance, Element* element, void* unused);
};

void Descriptor::read(void* instance, Element* element, void* unused)
{
    if (element->isNull())
        return;

    Frame frame;
    float value;

    element->find(name975334)->value.toFloat(&value);
    frame.position[0] = value;
    element->find(name975380)->value.toFloat(&value);
    frame.position[1] = value;
    element->find(name975318)->value.toFloat(&value);
    frame.position[2] = value;

    element->find(name975350)->value.toFloat(&value);
    frame.rotation[0] = value;
    element->find(name975368)->value.toFloat(&value);
    frame.rotation[1] = value;
    element->find(name975304)->value.toFloat(&value);
    frame.rotation[2] = value;
    element->find(name975328)->value.toFloat(&value);
    frame.rotation[3] = value;
    element->find(name975354)->value.toFloat(&value);
    frame.rotation[4] = value;
    element->find(name975348)->value.toFloat(&value);
    frame.rotation[5] = value;
    element->find(name975324)->value.toFloat(&value);
    frame.rotation[6] = value;
    element->find(name975320)->value.toFloat(&value);
    frame.rotation[7] = value;
    element->find(name975308)->value.toFloat(&value);
    frame.rotation[8] = value;

    setter->set(instance, frame);
}
