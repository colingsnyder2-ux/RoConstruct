// from server: 100% by EspClaude
// from server: 92% by colin
// roc 2008-06 00647430  unit: RBX::GlueJoint  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00647430
//
// 00647430  53                   push ebx
// 00647431  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00647435  56                   push esi
// 00647436  57                   push edi
// 00647437  85db                 test ebx, ebx
// 00647439  0f848f000000         je 0x6474ce
// 0064743f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00647443  85ff                 test edi, edi
// 00647445  0f8483000000         je 0x6474ce
// 0064744b  8b742418             mov esi, dword ptr [esp + 0x18]
// 0064744f  807e2400             cmp byte ptr [esi + 0x24], 0
// 00647453  7479                 je 0x6474ce
// 00647455  55                   push ebp
// 00647456  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0064745a  56                   push esi
// 0064745b  e8a01ef5ff           call 0x599300
// 00647460  83c404               add esp, 4
// 00647463  85ed                 test ebp, ebp
// 00647465  740d                 je 0x647474
// 00647467  84c0                 test al, al
// 00647469  750d                 jne 0x647478
// 0064746b  56                   push esi
// 0064746c  e8bf1ef5ff           call 0x599330
// 00647471  83c404               add esp, 4
// 00647474  84c0                 test al, al
// 00647476  744f                 je 0x6474c7
// 00647478  8b87a0000000         mov eax, dword ptr [edi + 0xa0]
// 0064747e  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00647481  3b8ba0000000         cmp ecx, dword ptr [ebx + 0xa0]
// 00647487  753e                 jne 0x6474c7
// 00647489  8b535c               mov edx, dword ptr [ebx + 0x5c]
// 0064748c  3b575c               cmp edx, dword ptr [edi + 0x5c]
// 0064748f  0f94c0               sete al
// 00647492  85ed                 test ebp, ebp
// 00647494  7508                 jne 0x64749e
// 00647496  5d                   pop ebp
// 00647497  5f                   pop edi
// 00647498  5e                   pop esi
// 00647499  0fb6c0               movzx eax, al
// 0064749c  5b                   pop ebx
// 0064749d  c3                   ret 
// 0064749e  84c0                 test al, al
// 006474a0  751b                 jne 0x6474bd
// 006474a2  8bcb                 mov ecx, ebx
// 006474a4  e8b700faff           call 0x5e7560
// 006474a9  8bcf                 mov ecx, edi
// 006474ab  8bf0                 mov esi, eax
// 006474ad  e8ae00faff           call 0x5e7560
// 006474b2  3bf0                 cmp esi, eax
// 006474b4  7407                 je 0x6474bd
// 006474b6  5d                   pop ebp
// 006474b7  5f                   pop edi
// 006474b8  5e                   pop esi
// 006474b9  33c0                 xor eax, eax
// 006474bb  5b                   pop ebx
// 006474bc  c3                   ret 
// 006474bd  5d                   pop ebp
// 006474be  5f                   pop edi
// 006474bf  5e                   pop esi
// 006474c0  b801000000           mov eax, 1
// 006474c5  5b                   pop ebx
// 006474c6  c3                   ret 
// 006474c7  5d                   pop ebp
// 006474c8  5f                   pop edi
// 006474c9  5e                   pop esi
// 006474ca  32c0                 xor al, al
// 006474cc  5b                   pop ebx
// 006474cd  c3                   ret 
// 006474ce  5f                   pop edi
// 006474cf  5e                   pop esi
// 006474d0  32c0                 xor al, al
// 006474d2  5b                   pop ebx
// 006474d3  c3                   ret 

// from server: 89% by king_originala
struct Link {
    char pad[20];
    Link* parent;
};

struct Part {
    char pad0[92];
    void* identity;
    char pad1[64];
    Link* link;

    int f();
};

struct Joint {
    char pad[36];
    bool enabled;
};

extern bool __cdecl checkFirst(Joint*);
extern bool __cdecl checkSecond(Joint*);

bool __cdecl match(Part* a, Part* b, Joint* joint, int extended)
{
    if (a && b && joint->enabled) {
        bool valid;
        if (extended)
            valid = checkFirst(joint) || checkSecond(joint);
        else
            valid = checkFirst(joint);

        if (valid && b->link->parent == a->link) {
            bool same = a->identity == b->identity;
            return !extended ? same : (same || a->f() == b->f());
        }
        return false;
    }
    return false;
}

