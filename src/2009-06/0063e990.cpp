// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b25f0  unit: RBX::Accoutrement  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b25f0
//
// 005b25f0  53                   push ebx
// 005b25f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005b25f5  8b4304               mov eax, dword ptr [ebx + 4]
// 005b25f8  55                   push ebp
// 005b25f9  56                   push esi
// 005b25fa  57                   push edi
// 005b25fb  50                   push eax
// 005b25fc  8bf9                 mov edi, ecx
// 005b25fe  e8cd72edff           call 0x4898d0
// 005b2603  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005b2606  51                   push ecx
// 005b2607  8bf0                 mov esi, eax
// 005b2609  e8c272edff           call 0x4898d0
// 005b260e  83c408               add esp, 8
// 005b2611  8be8                 mov ebp, eax
// 005b2613  85f6                 test esi, esi
// 005b2615  7425                 je 0x5b263c
// 005b2617  6a01                 push 1
// 005b2619  56                   push esi
// 005b261a  e89138eeff           call 0x495eb0
// 005b261f  83c408               add esp, 8
// 005b2622  84c0                 test al, al
// 005b2624  740c                 je 0x5b2632
// 005b2626  56                   push esi
// 005b2627  6a00                 push 0
// 005b2629  8bcf                 mov ecx, edi
// 005b262b  e8e0feffff           call 0x5b2510
// 005b2630  eb0a                 jmp 0x5b263c
// 005b2632  c7875401000000000000 mov dword ptr [edi + 0x154], 0
// 005b263c  53                   push ebx
// 005b263d  8bcf                 mov ecx, edi
// 005b263f  e87c86faff           call 0x55acc0
// 005b2644  85ed                 test ebp, ebp
// 005b2646  7416                 je 0x5b265e
// 005b2648  6a01                 push 1
// 005b264a  55                   push ebp
// 005b264b  e86038eeff           call 0x495eb0
// 005b2650  83c408               add esp, 8
// 005b2653  84c0                 test al, al
// 005b2655  7407                 je 0x5b265e
// 005b2657  8bcf                 mov ecx, edi
// 005b2659  e842eaffff           call 0x5b10a0
// 005b265e  5f                   pop edi
// 005b265f  5e                   pop esi
// 005b2660  5d                   pop ebp
// 005b2661  5b                   pop ebx
// 005b2662  c20400               ret 4

extern "C" int __cdecl sub_4898d0(int);
extern "C" int __cdecl sub_495eb0(int, int);

struct Args {
    int unused;
    int first;
    int second;
};

struct S {
    char padding[0x154];
    int state;

    void f(Args*);
    void sub_5b2510(int, int);
    void sub_55acc0(Args*);
    void sub_5b10a0();
};

void S::f(Args* p)
{
    int first = sub_4898d0(p->first);
    int second = sub_4898d0(p->second);

    if (first) {
        if ((unsigned char)sub_495eb0(first, 1))
            sub_5b2510(0, first);
        else
            state = 0;
    }

    sub_55acc0(p);

    if (second && (unsigned char)sub_495eb0(second, 1))
        sub_5b10a0();
}
