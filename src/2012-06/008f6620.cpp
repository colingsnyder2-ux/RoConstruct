// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 007f2b50  unit: RBX::VGuiObject::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007f2b50
//
// 007f2b50  8b442404             mov eax, dword ptr [esp + 4]
// 007f2b54  56                   push esi
// 007f2b55  8bf1                 mov esi, ecx
// 007f2b57  3986b8010000         cmp dword ptr [esi + 0x1b8], eax
// 007f2b5d  7419                 je 0x7f2b78
// 007f2b5f  6828f2e400           push 0xe4f228
// 007f2b64  8986b8010000         mov dword ptr [esi + 0x1b8], eax
// 007f2b6a  e83122c2ff           call 0x414da0
// 007f2b6f  8b06                 mov eax, dword ptr [esi]
// 007f2b71  8b5074               mov edx, dword ptr [eax + 0x74]
// 007f2b74  8bce                 mov ecx, esi
// 007f2b76  ffd2                 call edx
// 007f2b78  5e                   pop esi
// 007f2b79  c20400               ret 4

extern "C" void __stdcall sub_414da0(const char* name);

struct EventDesc {
    unsigned char pad[0x1f4];
    int field_1b8;
    void update(int value);
};

void EventDesc::update(int value)
{
    if (field_1b8 != value) {
        field_1b8 = value;
        sub_414da0((const char*)0x00e4f228);
        void** vtable = *(void***)this;
        void (__thiscall *callback)(EventDesc*) =
            (void (__thiscall *)(EventDesc*))vtable[0x74 / sizeof(void*)];
        callback(this);
    }
}
