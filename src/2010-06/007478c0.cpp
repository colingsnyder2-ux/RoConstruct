// from server: 100% by Yeetserama
// roc 2010-06 007478c0  unit: RBX::Clump  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007478c0
//
// 007478c0  8b442408             mov eax, dword ptr [esp + 8]
// 007478c4  8a08                 mov cl, byte ptr [eax]
// 007478c6  56                   push esi
// 007478c7  8b742408             mov esi, dword ptr [esp + 8]
// 007478cb  6a00                 push 0
// 007478cd  68c0c8b700           push 0xb7c8c0
// 007478d2  68408eb700           push 0xb78e40
// 007478d7  6a00                 push 0
// 007478d9  56                   push esi
// 007478da  884c2420             mov byte ptr [esp + 0x20], cl
// 007478de  e807130600           call 0x7a8bea
// 007478e3  83c414               add esp, 0x14
// 007478e6  85c0                 test eax, eax
// 007478e8  740e                 je 0x7478f8
// 007478ea  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007478ee  52                   push edx
// 007478ef  8bc8                 mov ecx, eax
// 007478f1  e87a4defff           call 0x63c670
// 007478f6  5e                   pop esi
// 007478f7  c3                   ret 
// 007478f8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007478fc  50                   push eax
// 007478fd  8bce                 mov ecx, esi
// 007478ff  e81c010000           call 0x747a20
// 00747904  5e                   pop esi
// 00747905  c3                   ret 
// copied from an identical function in another client (function ?setValue@ns_ROCX00000a@@YAXPAUInstance@1@AB_N@Z)

namespace ns_ROCX00000a {
// from server: 100% by king_originala
extern char instanceType;
extern char partType;

extern "C" void* __cdecl castObject(
    void* object, int offset, void* sourceType, void* targetType, int isReference);

struct Instance
{
    void setValue(bool value);
};

struct Part
{
    void setValue(bool value);
};

void __cdecl setValue(Instance* instance, const bool& value)
{
    bool newValue = value;
    Part* part = static_cast<Part*>(
        castObject(instance, 0, &instanceType, &partType, 0));

    if (part)
        part->setValue(newValue);
    else
        instance->setValue(newValue);
}
}
