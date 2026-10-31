// from server: 86% by EspClaude
// from server: 100% by colin
// roc 2008-06 005d6070  unit: RBX::VTeams::?$FactoryProduct  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d6070
//
// 005d6070  53                   push ebx
// 005d6071  55                   push ebp
// 005d6072  56                   push esi
// 005d6073  57                   push edi
// 005d6074  51                   push ecx
// 005d6075  e8d6bcebff           call 0x491d50
// 005d607a  8bd8                 mov ebx, eax
// 005d607c  83c404               add esp, 4
// 005d607f  8bcb                 mov ecx, ebx
// 005d6081  33f6                 xor esi, esi
// 005d6083  e8984debff           call 0x48ae20
// 005d6088  85c0                 test eax, eax
// 005d608a  7651                 jbe 0x5d60dd
// 005d608c  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005d6092  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 005d6098  8b4710               mov eax, dword ptr [edi + 0x10]
// 005d609b  2b470c               sub eax, dword ptr [edi + 0xc]
// 005d609e  c1f803               sar eax, 3
// 005d60a1  3bf0                 cmp esi, eax
// 005d60a3  7202                 jb 0x5d60a7
// 005d60a5  ffd5                 call ebp
// 005d60a7  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 005d60aa  8b04f1               mov eax, dword ptr [ecx + esi*8]
// 005d60ad  6a00                 push 0
// 005d60af  6860749300           push 0x937460
// 005d60b4  687c909200           push 0x92907c
// 005d60b9  6a00                 push 0
// 005d60bb  50                   push eax
// 005d60bc  e805b70c00           call 0x6a17c6
// 005d60c1  83c414               add esp, 0x14
// 005d60c4  85c0                 test eax, eax
// 005d60c6  7409                 je 0x5d60d1
// 005d60c8  80b87c01000000       cmp byte ptr [eax + 0x17c], 0
// 005d60cf  7413                 je 0x5d60e4
// 005d60d1  8bcb                 mov ecx, ebx
// 005d60d3  46                   inc esi
// 005d60d4  e8474debff           call 0x48ae20
// 005d60d9  3bf0                 cmp esi, eax
// 005d60db  72b5                 jb 0x5d6092
// 005d60dd  5f                   pop edi
// 005d60de  5e                   pop esi
// 005d60df  5d                   pop ebp
// 005d60e0  32c0                 xor al, al
// 005d60e2  5b                   pop ebx
// 005d60e3  c3                   ret 
// 005d60e4  5f                   pop edi
// 005d60e5  5e                   pop esi
// 005d60e6  5d                   pop ebp
// 005d60e7  b001                 mov al, 1
// 005d60e9  5b                   pop ebx
// 005d60ea  c3                   ret 

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char padding[0x100];
        Instance* next;
    };

    struct Entry {
        Instance* object;
        void* control;
    };

    struct Children {
        char padding[0x0c];
        Entry* first;
        Entry* last;
    };

    struct ServiceProvider : Instance {
        Children* children;
        unsigned int count();
    };

    namespace Network {
        class Player : Instance {
        public:
            char padding[0x74];
            bool flag;
        };
    }

    struct FactoryProduct : Instance {
        bool f();
    };
}

extern RBX::ServiceProvider* __cdecl func_00491d50(RBX::Instance*);
extern "C" void (__cdecl *invalid_parameter_noinfo)();

bool RBX::FactoryProduct::f()
{
    ServiceProvider* provider = func_00491d50(this);
    unsigned int i = 0;

    if (provider->count() > 0) {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do {
            Children* children = provider->children;
            if (i >= static_cast<unsigned int>(children->last - children->first))
                invalid();

            Instance* obj = children->first[i].object;
            Network::Player* player = dynamic_cast<Network::Player*>(obj);

            if (player && !player->flag)
                return true;

            ++i;
        } while (i < provider->count());
    }

    return false;
}
