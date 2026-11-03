// from server: 80% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0057d550  unit: RBX::RotateSelectionVerb  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057d550
//
// 0057d550  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0057d554  8b8130010000         mov eax, dword ptr [ecx + 0x130]
// 0057d55a  8b5004               mov edx, dword ptr [eax + 4]
// 0057d55d  81c130010000         add ecx, 0x130
// 0057d563  ffe2                 jmp edx

struct Subobject {
    virtual void first();
    virtual void second();
};

struct S {
    char padding[0x130];
    Subobject subobject;
};

void f(S* object)
{
    object->subobject.second();
}
