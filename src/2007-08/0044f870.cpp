// from server: 97% by EspClaude
// from server: 80% by colin
// roc 2007-08 0044f870  unit: VCRobloxDoc::?$VerbBinder  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044f870
//
// 0044f870  8b442408             mov eax, dword ptr [esp + 8]
// 0044f874  85c0                 test eax, eax
// 0044f876  56                   push esi
// 0044f877  57                   push edi
// 0044f878  8bf1                 mov esi, ecx
// 0044f87a  741f                 je 0x44f89b
// 0044f87c  8b7804               mov edi, dword ptr [eax + 4]
// 0044f87f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044f883  8d4c240c             lea ecx, [esp + 0xc]
// 0044f887  51                   push ecx
// 0044f888  8d4e54               lea ecx, [esi + 0x54]
// 0044f88b  89442410             mov dword ptr [esp + 0x10], eax
// 0044f88f  e83c41feff           call 0x4339d0
// 0044f894  8938                 mov dword ptr [eax], edi
// 0044f896  5f                   pop edi
// 0044f897  5e                   pop esi
// 0044f898  c20800               ret 8
// 0044f89b  e890d20d00           call 0x52cb30
// 0044f8a0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0044f8a4  8bf8                 mov edi, eax
// 0044f8a6  8d44240c             lea eax, [esp + 0xc]
// 0044f8aa  50                   push eax
// 0044f8ab  8d4e54               lea ecx, [esi + 0x54]
// 0044f8ae  89542410             mov dword ptr [esp + 0x10], edx
// 0044f8b2  e81941feff           call 0x4339d0
// 0044f8b7  8938                 mov dword ptr [eax], edi
// 0044f8b9  5f                   pop edi
// 0044f8ba  5e                   pop esi
// 0044f8bb  c20800               ret 8

struct Map4339D0 {
    int *lookup(int *key);
};

struct VCRobloxDoc_VerbBinder {
    char pad[0x54];
    Map4339D0 m;
    void insert(int, int);
};

extern "C" int __cdecl sub_52CB30();

void VCRobloxDoc_VerbBinder::insert(int a, int b) {
    if (b != 0) {
        int v = *(int *)(b + 4);
        int tmp = a;
        *m.lookup(&tmp) = v;
    } else {
        int v = sub_52CB30();
        int tmp = a;
        *m.lookup(&tmp) = v;
    }
}
