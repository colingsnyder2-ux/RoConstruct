// from server: 100% by Espeon
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
// from server: 86% by king_originala
// roc 2008-06 005e7580  unit: RBX::Ball  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7580
//
// 005e7580  56                   push esi
// 005e7581  8bf1                 mov esi, ecx
// 005e7583  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 005e7589  8b01                 mov eax, dword ptr [ecx]
// 005e758b  8b5008               mov edx, dword ptr [eax + 8]
// 005e758e  ffd2                 call edx
// 005e7590  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 005e7596  83c104               add ecx, 4
// 005e7599  83f801               cmp eax, 1
// 005e759c  0f94c0               sete al
// 005e759f  0fb6d0               movzx edx, al
// 005e75a2  52                   push edx
// 005e75a3  51                   push ecx
// 005e75a4  e887210600           call 0x649730
// 005e75a9  83c408               add esp, 8
// 005e75ac  5e                   pop esi
// 005e75ad  c3                   ret 

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    int value;
};

extern "C" void __cdecl update(int*, bool);

struct S {
    char padding[0x9c];
    Object* object;
    void f();
};

void S::f()
{
    int kind=object->slot2();
    int* destination=&object->value;
    _ReadWriteBarrier();
    update(destination,kind==1);
}
