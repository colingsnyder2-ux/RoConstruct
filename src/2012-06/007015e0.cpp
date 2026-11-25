// from server: 87% by Xemicl
// from server: 100% by tajop
// roc 2012-06 0081a560  unit: RBX::VTouchTransmitter::?$FactoryProduct  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081a560
//
// 0081a560  53                   push ebx
// 0081a561  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0081a565  56                   push esi
// 0081a566  57                   push edi
// 0081a567  8bf9                 mov edi, ecx
// 0081a569  8b7704               mov esi, dword ptr [edi + 4]
// 0081a56c  8b4f08               mov ecx, dword ptr [edi + 8]
// 0081a56f  2bce                 sub ecx, esi
// 0081a571  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0081a576  f7e9                 imul ecx
// 0081a578  c1fa02               sar edx, 2
// 0081a57b  8bc2                 mov eax, edx
// 0081a57d  c1e81f               shr eax, 0x1f
// 0081a580  03c2                 add eax, edx
// 0081a582  7504                 jne 0x81a588
// 0081a584  33f6                 xor esi, esi
// 0081a586  eb15                 jmp 0x81a59d
// 0081a588  8bcb                 mov ecx, ebx
// 0081a58a  2bce                 sub ecx, esi
// 0081a58c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0081a591  f7e9                 imul ecx
// 0081a593  c1fa02               sar edx, 2
// 0081a596  8bf2                 mov esi, edx
// 0081a598  c1ee1f               shr esi, 0x1f
// 0081a59b  03f2                 add esi, edx
// 0081a59d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0081a5a1  51                   push ecx
// 0081a5a2  6a01                 push 1
// 0081a5a4  53                   push ebx
// 0081a5a5  8bcf                 mov ecx, edi
// 0081a5a7  e874fbffff           call 0x81a120
// 0081a5ac  8b4704               mov eax, dword ptr [edi + 4]
// 0081a5af  8d1476               lea edx, [esi + esi*2]
// 0081a5b2  5f                   pop edi
// 0081a5b3  8d0cd0               lea ecx, [eax + edx*8]
// 0081a5b6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0081a5ba  5e                   pop esi
// 0081a5bb  8908                 mov dword ptr [eax], ecx
// 0081a5bd  5b                   pop ebx
// 0081a5be  c20c00               ret 0xc

struct Iter {
    char* ptr;
    Iter(char* p) : ptr(p) {}
};

struct VTouchTransmitter {
    char pad0[4];
    char* begin;
    char* end;
    void insert(char* pos, int count, char* val);

    Iter FactoryProduct(char* pos, char* val);
};

Iter VTouchTransmitter::FactoryProduct(char* pos, char* val) {
    char* first = this->begin;
    int n = (int)((this->end - first) / 24);
    int idx;
    if (n == 0) {
        idx = 0;
    } else {
        idx = (int)((pos - first) / 24);
    }
    insert(pos, 1, val);
    return Iter(this->begin + idx * 24);
}
