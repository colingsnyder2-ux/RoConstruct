// from server: 76% by colin
// roc 2007-08 004b5800  unit: RBX::Network::Replicator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b5800
//
// 004b5800  50                   push eax
// 004b5801  ff1598e67700         call dword ptr [0x77e698]
// 004b5807  56                   push esi
// 004b5808  b9a8eb8b00           mov ecx, 0x8beba8
// 004b580d  e83eb8ffff           call 0x4b1050
// 004b5812  c687281d000001       mov byte ptr [edi + 0x1d28], 1

struct Replicator {
    char pad[0x1d28];
    bool flag;
};

extern "C" void __stdcall sub_77e698();
extern "C" void __stdcall sub_4b1050();

void init(Replicator* self)
{
    sub_77e698();
    sub_4b1050();
    self->flag = true;
}
