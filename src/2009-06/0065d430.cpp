// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00599360  unit: RBX::VPartInstance::?$FactoryProduct  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00599360
//
// 00599360  56                   push esi
// 00599361  8bf1                 mov esi, ecx
// 00599363  837e1400             cmp dword ptr [esi + 0x14], 0
// 00599367  746e                 je 0x5993d7
// 00599369  57                   push edi
// 0059936a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0059936d  8bcf                 mov ecx, edi
// 0059936f  e8ecffffff           call 0x599360
// 00599374  8b8690000000         mov eax, dword ptr [esi + 0x90]
// 0059937a  3b8790000000         cmp eax, dword ptr [edi + 0x90]
// 00599380  7454                 je 0x5993d6
// 00599382  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00599385  53                   push ebx
// 00599386  e8d5ffffff           call 0x599360
// 0059938b  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0059938e  85c9                 test ecx, ecx
// 00599390  7409                 je 0x59939b
// 00599392  e8c9a90700           call 0x613d60
// 00599397  8bd8                 mov ebx, eax
// 00599399  eb03                 jmp 0x59939e
// 0059939b  8d5e38               lea ebx, [esi + 0x38]
// 0059939e  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005993a1  8bcf                 mov ecx, edi
// 005993a3  e8b8ffffff           call 0x599360
// 005993a8  8d8e94000000         lea ecx, [esi + 0x94]
// 005993ae  51                   push ecx
// 005993af  53                   push ebx
// 005993b0  81c794000000         add edi, 0x94
// 005993b6  57                   push edi
// 005993b7  e804feffff           call 0x5991c0
// 005993bc  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005993bf  83c40c               add esp, 0xc
// 005993c2  8bcf                 mov ecx, edi
// 005993c4  e897ffffff           call 0x599360
// 005993c9  8b9790000000         mov edx, dword ptr [edi + 0x90]
// 005993cf  899690000000         mov dword ptr [esi + 0x90], edx
// 005993d5  5b                   pop ebx
// 005993d6  5f                   pop edi
// 005993d7  5e                   pop esi
// 005993d8  c3                   ret 

struct DataSource {
    const void* get();
};

extern void __cdecl combine(const void*, const void*, void*);

struct S {
    char reserved0[0x4];
    S* parent;
    char reserved1[0x24];
    S* source;
    char reserved2[0x8];
    DataSource* dataSource;
    char reserved3[0x4];
    char localData[0x58];
    unsigned int version;
    char result[0x30];

    void update();
};

void S::update()
{
    if (parent) {
        S* s = source;
        s->update();
        if (version != s->version) {
            parent->update();

            const void* data;
            if (dataSource)
                data = dataSource->get();
            else
                data = localData;

            S* p = parent;
            p->update();
            combine(p->result, data, result);

            s = source;
            s->update();
            version = s->version;
        }
    }
}
