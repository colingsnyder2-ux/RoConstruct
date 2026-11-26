// from server: 100% by Xemicl
// roc 2012-06 00742e40  unit: seg_00740000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00742e40
//
// 00742e40  51                   push ecx
// 00742e41  8d0424               lea eax, [esp]
// 00742e44  50                   push eax
// 00742e45  e866ffffff           call 0x742db0
// 00742e4a  8b0c24               mov ecx, dword ptr [esp]
// 00742e4d  8b442408             mov eax, dword ptr [esp + 8]
// 00742e51  8808                 mov byte ptr [eax], cl
// 00742e53  8a4c2402             mov cl, byte ptr [esp + 2]
// 00742e57  886801               mov byte ptr [eax + 1], ch
// 00742e5a  884802               mov byte ptr [eax + 2], cl
// 00742e5d  59                   pop ecx
// 00742e5e  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000010@@QAE?AUColor@2@XZ)

namespace ns_ROCX000010 {
struct Iterator {
    union {
        unsigned long value;
        unsigned char bytes[4];
    };
};

struct Color {
    unsigned char r, g, b;
};

struct S {
    Iterator* find(Iterator*);
    Color f();
};

Color S::f()
{
    Iterator value;
    find(&value);

    Color result;
    result.r = value.bytes[0];
    result.g = value.bytes[1];
    result.b = value.bytes[2];
    return result;
}
}
