// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0057dc60  unit: RBX::TiltSelectionVerb  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057dc60
//
// 0057dc60  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0057dc63  8b9188020000         mov edx, dword ptr [ecx + 0x288]
// 0057dc69  83ec30               sub esp, 0x30
// 0057dc6c  81c188020000         add ecx, 0x288
// 0057dc72  56                   push esi
// 0057dc73  8d442404             lea eax, [esp + 4]
// 0057dc77  50                   push eax
// 0057dc78  8b4208               mov eax, dword ptr [edx + 8]
// 0057dc7b  ffd0                 call eax
// 0057dc7d  8bc8                 mov ecx, eax
// 0057dc7f  e82c2bf9ff           call 0x5107b0
// 0057dc84  50                   push eax
// 0057dc85  e8d60d0600           call 0x5dea60
// 0057dc8a  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0057dc8e  50                   push eax
// 0057dc8f  56                   push esi
// 0057dc90  e8fb0c0600           call 0x5de990
// 0057dc95  83c40c               add esp, 0xc
// 0057dc98  8bc6                 mov eax, esi
// 0057dc9a  5e                   pop esi
// 0057dc9b  83c430               add esp, 0x30
// 0057dc9e  c20400               ret 4

struct Value {
    unsigned char data[48];
};

struct Source {
    Value get();
};

struct Provider {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Source& source();
};

struct Owner {
    unsigned char padding[0x118];
    Provider provider;
};

extern "C" void* __cdecl convert(const Value&);
extern "C" void __cdecl assign(void*, void*);

struct TiltSelectionVerb {
    unsigned char padding[12];
    Owner* owner;

    void* execute(void* result);
};

void* TiltSelectionVerb::execute(void* result)
{
    assign(result, convert(owner->provider.source().get()));
    return result;
}
