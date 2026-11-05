// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00606e00  unit: RBX::ContactConnector  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00606e00
//
// 00606e00  6aff                 push -1
// 00606e02  683bf47b00           push 0x7bf43b
// 00606e07  64a100000000         mov eax, dword ptr fs:[0]
// 00606e0d  50                   push eax
// 00606e0e  64892500000000       mov dword ptr fs:[0], esp
// 00606e15  51                   push ecx
// 00606e16  56                   push esi
// 00606e17  57                   push edi
// 00606e18  6a50                 push 0x50
// 00606e1a  8bf9                 mov edi, ecx
// 00606e1c  e8ff9a0900           call 0x6a0920
// 00606e21  83c404               add esp, 4
// 00606e24  89442408             mov dword ptr [esp + 8], eax
// 00606e28  33f6                 xor esi, esi
// 00606e2a  89742414             mov dword ptr [esp + 0x14], esi
// 00606e2e  3bc6                 cmp eax, esi
// 00606e30  7420                 je 0x606e52
// 00606e32  d94730               fld dword ptr [edi + 0x30]
// 00606e35  83ec0c               sub esp, 0xc
// 00606e38  d95c2408             fstp dword ptr [esp + 8]
// 00606e3c  8bc8                 mov ecx, eax
// 00606e3e  d9472c               fld dword ptr [edi + 0x2c]
// 00606e41  d95c2404             fstp dword ptr [esp + 4]
// 00606e45  d94728               fld dword ptr [edi + 0x28]
// 00606e48  d91c24               fstp dword ptr [esp]
// 00606e4b  e8f0feffff           call 0x606d40
// 00606e50  8bf0                 mov esi, eax
// 00606e52  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00606e56  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00606e5a  894614               mov dword ptr [esi + 0x14], eax
// 00606e5d  894e18               mov dword ptr [esi + 0x18], ecx
// 00606e60  56                   push esi
// 00606e61  8bcf                 mov ecx, edi
// 00606e63  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00606e6b  e8e0e90300           call 0x645850
// 00606e70  8bc8                 mov ecx, eax
// 00606e72  e8e942ffff           call 0x5fb160
// 00606e77  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00606e7b  5f                   pop edi
// 00606e7c  8bc6                 mov eax, esi
// 00606e7e  5e                   pop esi
// 00606e7f  64890d00000000       mov dword ptr fs:[0], ecx
// 00606e86  83c410               add esp, 0x10
// 00606e89  c20800               ret 8

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Link {
    void update();
};

struct ContactConnector {
    unsigned char prefix[0x14];
    volatile int first;
    volatile int second;
    unsigned char middle[0x0c];
    float x;
    float y;
    float z;
    unsigned char tail[0x1c];

    ContactConnector(float, float, float);
    Link* attach(ContactConnector*);
    ContactConnector* create(int, int);
};

ContactConnector* ContactConnector::create(int a, int b)
{
    ContactConnector* result = new ContactConnector(x, y, z);
    result->first = a;
    result->second = b;
    attach(result)->update();
    return result;
}
