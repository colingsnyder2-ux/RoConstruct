// from server: 100% by EspClaude
// roc 2009-06 0065a850  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065a850
//
// 0065a850  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0065a853  8b01                 mov eax, dword ptr [ecx]
// 0065a855  8b542404             mov edx, dword ptr [esp + 4]
// 0065a859  8b4008               mov eax, dword ptr [eax + 8]
// 0065a85c  52                   push edx
// 0065a85d  ffd0                 call eax
// 0065a85f  83ec08               sub esp, 8
// 0065a862  8bcc                 mov ecx, esp
// 0065a864  8964240c             mov dword ptr [esp + 0xc], esp
// 0065a868  50                   push eax
// 0065a869  e8321dffff           call 0x64c5a0
// 0065a86e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065a872  83c110               add ecx, 0x10
// 0065a875  e8b605e6ff           call 0x4bae30
// 0065a87a  c20800               ret 8
// copied from an identical function in another client (function ?read@Descriptor@ns_ROCX00000c@@QAEXPAXPAUOutput@2@@Z)

namespace ns_ROCX00000c {
struct Shared {
    void* pointer;
    void* control;
    Shared(void*);
    Shared(const Shared&);
    ~Shared();
};

struct Holder {
    void set(Shared);
};

struct Output {
    char padding[16];
    Holder holder;
};

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual void* get(void*);
};

struct Descriptor {
    char padding[28];
    Getter* getter;
    void read(void*, Output*);
};

void Descriptor::read(void* object, Output* output)
{
    output->holder.set(Shared(getter->get(object)));
}
}
