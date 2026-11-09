// from server: 100% by colin
// roc 2008-06 00583570  unit: RBX::ModelInstance  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00583570
//
// 00583570  56                   push esi
// 00583571  57                   push edi
// 00583572  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00583576  8db164fdffff         lea esi, [ecx - 0x29c]
// 0058357c  57                   push edi
// 0058357d  56                   push esi
// 0058357e  e8bdbd0800           call 0x60f340
// 00583583  56                   push esi
// 00583584  e897640500           call 0x5d9a20
// 00583589  83c40c               add esp, 0xc
// 0058358c  85c0                 test eax, eax
// 0058358e  740e                 je 0x58359e
// 00583590  8d884c010000         lea ecx, [eax + 0x14c]
// 00583596  8b01                 mov eax, dword ptr [ecx]
// 00583598  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0058359b  57                   push edi
// 0058359c  ffd2                 call edx
// 0058359e  5f                   pop edi
// 0058359f  5e                   pop esi
// 005835a0  c20400               ret 4

struct Sub {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void call(void*);
};

struct Owner { char padding[0x14c]; Sub sub; };
extern "C" void __cdecl func_0060f340(void*, void*);
extern "C" Owner* __cdecl func_005d9a20(void*);

struct S { void f(void*); };

void S::f(void* value)
{
    void* base = (char*)this - 0x29c;
    func_0060f340(base, value);
    Owner* owner = func_005d9a20(base);
    if (owner)
        owner->sub.call(value);
}
