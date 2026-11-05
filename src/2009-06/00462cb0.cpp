// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00462040  unit: Scintilla::CScintillaFindReplaceDlg  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00462040
//
// 00462040  83ec14               sub esp, 0x14
// 00462043  833db02f930000       cmp dword ptr [0x932fb0], 0
// 0046204a  894c240c             mov dword ptr [esp + 0xc], ecx
// 0046204e  0f8426010000         je 0x46217a
// 00462054  53                   push ebx
// 00462055  55                   push ebp
// 00462056  56                   push esi
// 00462057  57                   push edi
// 00462058  e8c9e82300           call 0x6a0926
// 0046205d  8b7004               mov esi, dword ptr [eax + 4]
// 00462060  33ed                 xor ebp, ebp
// 00462062  89742420             mov dword ptr [esp + 0x20], esi
// 00462066  396e58               cmp dword ptr [esi + 0x58], ebp
// 00462069  0f84d4000000         je 0x462143
// 0046206f  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 00462072  8b01                 mov eax, dword ptr [ecx]
// 00462074  8b5018               mov edx, dword ptr [eax + 0x18]
// 00462077  ffd2                 call edx
// 00462079  89442418             mov dword ptr [esp + 0x18], eax
// 0046207d  85c0                 test eax, eax
// 0046207f  0f84be000000         je 0x462143
// 00462085  eb0d                 jmp 0x462094
// 00462087  eb07                 jmp 0x462090
// 00462089  8da42400000000       lea esp, [esp]
// 00462090  8b742420             mov esi, dword ptr [esp + 0x20]
// 00462094  85ed                 test ebp, ebp
// 00462096  0f85da000000         jne 0x462176
// 0046209c  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0046209f  8b01                 mov eax, dword ptr [ecx]
// 004620a1  8b401c               mov eax, dword ptr [eax + 0x1c]
// 004620a4  8d542418             lea edx, [esp + 0x18]
// 004620a8  52                   push edx
// 004620a9  ffd0                 call eax
// 004620ab  8bd8                 mov ebx, eax
// 004620ad  8b13                 mov edx, dword ptr [ebx]
// 004620af  8b425c               mov eax, dword ptr [edx + 0x5c]
// 004620b2  8bcb                 mov ecx, ebx
// 004620b4  ffd0                 call eax
// 004620b6  89442414             mov dword ptr [esp + 0x14], eax
// 004620ba  85c0                 test eax, eax
// 004620bc  7476                 je 0x462134
// 004620be  8bff                 mov edi, edi
// 004620c0  85ed                 test ebp, ebp
// 004620c2  7570                 jne 0x462134
// 004620c4  8b13                 mov edx, dword ptr [ebx]
// 004620c6  8b5260               mov edx, dword ptr [edx + 0x60]
// 004620c9  8d442414             lea eax, [esp + 0x14]
// 004620cd  50                   push eax
// 004620ce  8bcb                 mov ecx, ebx
// 004620d0  ffd2                 call edx
// 004620d2  8bf8                 mov edi, eax
// 004620d4  8b07                 mov eax, dword ptr [edi]
// 004620d6  8b5068               mov edx, dword ptr [eax + 0x68]
// 004620d9  8bcf                 mov ecx, edi
// 004620db  ffd2                 call edx
// 004620dd  89442410             mov dword ptr [esp + 0x10], eax
// 004620e1  85c0                 test eax, eax
// 004620e3  7448                 je 0x46212d
// 004620e5  85ed                 test ebp, ebp
// 004620e7  7544                 jne 0x46212d
// 004620e9  8b07                 mov eax, dword ptr [edi]
// 004620eb  8b506c               mov edx, dword ptr [eax + 0x6c]
// 004620ee  8d4c2410             lea ecx, [esp + 0x10]
// 004620f2  51                   push ecx
// 004620f3  8bcf                 mov ecx, edi
// 004620f5  ffd2                 call edx
// 004620f7  8bf0                 mov esi, eax
// 004620f9  68c8a88100           push 0x81a8c8
// 004620fe  8bce                 mov ecx, esi
// 00462100  e8ebea2300           call 0x6a0bf0
// 00462105  85c0                 test eax, eax
// 00462107  741d                 je 0x462126
// 00462109  3b74241c             cmp esi, dword ptr [esp + 0x1c]
// 0046210d  7417                 je 0x462126
// 0046210f  85f6                 test esi, esi
// 00462111  7403                 je 0x462116
// 00462113  8b7620               mov esi, dword ptr [esi + 0x20]
// 00462116  56                   push esi
// 00462117  ff15502d8000         call dword ptr [0x802d50]
// 0046211d  85c0                 test eax, eax
// 0046211f  7405                 je 0x462126
// 00462121  bd01000000           mov ebp, 1
// 00462126  837c241000           cmp dword ptr [esp + 0x10], 0
// 0046212b  75b8                 jne 0x4620e5
// 0046212d  837c241400           cmp dword ptr [esp + 0x14], 0
// 00462132  758c                 jne 0x4620c0
// 00462134  837c241800           cmp dword ptr [esp + 0x18], 0
// 00462139  0f8551ffffff         jne 0x462090
// 0046213f  85ed                 test ebp, ebp
// 00462141  7533                 jne 0x462176
// 00462143  a1b02f9300           mov eax, dword ptr [0x932fb0]
// 00462148  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0046214b  51                   push ecx
// 0046214c  ff15502d8000         call dword ptr [0x802d50]
// 00462152  85c0                 test eax, eax
// 00462154  7416                 je 0x46216c
// 00462156  8b15b02f9300         mov edx, dword ptr [0x932fb0]
// 0046215c  8b4220               mov eax, dword ptr [edx + 0x20]
// 0046215f  6a00                 push 0
// 00462161  6a00                 push 0
// 00462163  6a10                 push 0x10
// 00462165  50                   push eax
// 00462166  ff15142e8000         call dword ptr [0x802e14]
// 0046216c  c705b02f930000000000 mov dword ptr [0x932fb0], 0
// 00462176  5f                   pop edi
// 00462177  5e                   pop esi
// 00462178  5d                   pop ebp
// 00462179  5b                   pop ebx
// 0046217a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046217e  83c414               add esp, 0x14
// 00462181  e950f22300           jmp 0x6a13d6

struct S;

struct VTable {
    void* slots0[6];
    void* (__thiscall *firstOuter)(S*);
    S* (__thiscall *nextOuter)(S*, void**);
    void* slots8[15];
    void* (__thiscall *firstMiddle)(S*);
    S* (__thiscall *nextMiddle)(S*, void**);
    void* slot25;
    void* (__thiscall *firstInner)(S*);
    S* (__thiscall *nextInner)(S*, void**);
};

struct S {
    VTable* table;
    char pad04[0x1c];
    void* handle;

    int sub_6a0bf0(const void*);
    void sub_6a13d6();
    void f();
};

struct Application {
    char pad00[0x58];
    S* list;
};

struct State {
    void* field00;
    Application* application;
};

extern S* globalDialog;
extern "C" State* __cdecl sub_6a0926();
extern "C" int (__stdcall *IsWindow)(void*);
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

void S::f()
{
    if (globalDialog != 0) {
        Application* application = sub_6a0926()->application;
        int found = 0;

        if (application->list != 0) {
            void* outer = application->list->table->firstOuter(application->list);
            while (outer != 0) {
                if (found)
                    break;

                S* middleList =
                    application->list->table->nextOuter(application->list, &outer);
                void* middle = middleList->table->firstMiddle(middleList);

                while (middle != 0) {
                    if (found)
                        break;

                    S* innerList = middleList->table->nextMiddle(middleList, &middle);
                    void* inner = innerList->table->firstInner(innerList);

                    while (inner != 0) {
                        if (found)
                            break;

                        S* candidate = innerList->table->nextInner(innerList, &inner);
                        if (candidate->sub_6a0bf0((const void*)0x81a8c8) &&
                            candidate != this) {
                            void* handle = candidate;
                            if (candidate)
                                handle = candidate->handle;
                            if (IsWindow(handle))
                                found = 1;
                        }
                    }
                }
            }
        }

        if (!found) {
            if (IsWindow(globalDialog->handle))
                SendMessageA(globalDialog->handle, 0x10, 0, 0);
            globalDialog = 0;
        }
    }

    sub_6a13d6();
}
