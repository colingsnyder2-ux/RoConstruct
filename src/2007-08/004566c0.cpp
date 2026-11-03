// from server: 90% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004596a0  unit: CRobloxView  size: 274 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004596a0
//
// 004596a0  8a442404             mov al, byte ptr [esp + 4]
// 004596a4  83ec10               sub esp, 0x10
// 004596a7  53                   push ebx
// 004596a8  56                   push esi
// 004596a9  8bf1                 mov esi, ecx
// 004596ab  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 004596b1  33db                 xor ebx, ebx
// 004596b3  3bcb                 cmp ecx, ebx
// 004596b5  0f95c2               setne dl
// 004596b8  3ac2                 cmp al, dl
// 004596ba  0f84ea000000         je 0x4597aa
// 004596c0  3ac3                 cmp al, bl
// 004596c2  0f84ce000000         je 0x459796
// 004596c8  55                   push ebp
// 004596c9  57                   push edi
// 004596ca  e8b10e0100           call 0x46a580
// 004596cf  8bc8                 mov ecx, eax
// 004596d1  e8ec782400           call 0x6a0fc2
// 004596d6  8bf8                 mov edi, eax
// 004596d8  8b4654               mov eax, dword ptr [esi + 0x54]
// 004596db  89bed8010000         mov dword ptr [esi + 0x1d8], edi
// 004596e1  8ba894000000         mov ebp, dword ptr [eax + 0x94]
// 004596e7  39affc000000         cmp dword ptr [edi + 0xfc], ebp
// 004596ed  7425                 je 0x459714
// 004596ef  3beb                 cmp ebp, ebx
// 004596f1  7409                 je 0x4596fc
// 004596f3  8b4d00               mov ecx, dword ptr [ebp]
// 004596f6  8b5104               mov edx, dword ptr [ecx + 4]
// 004596f9  55                   push ebp
// 004596fa  ffd2                 call edx
// 004596fc  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 00459702  3bc3                 cmp eax, ebx
// 00459704  7408                 je 0x45970e
// 00459706  8b08                 mov ecx, dword ptr [eax]
// 00459708  8b5108               mov edx, dword ptr [ecx + 8]
// 0045970b  50                   push eax
// 0045970c  ffd2                 call edx
// 0045970e  89affc000000         mov dword ptr [edi + 0xfc], ebp
// 00459714  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 0045971a  53                   push ebx
// 0045971b  6813040000           push 0x413
// 00459720  8d86b0000000         lea eax, [esi + 0xb0]
// 00459726  8981f8000000         mov dword ptr [ecx + 0xf8], eax
// 0045972c  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 00459732  56                   push esi
// 00459733  8d44241c             lea eax, [esp + 0x1c]
// 00459737  50                   push eax
// 00459738  6800000050           push 0x50000000
// 0045973d  895c2424             mov dword ptr [esp + 0x24], ebx
// 00459741  895c2428             mov dword ptr [esp + 0x28], ebx
// 00459745  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00459749  895c2430             mov dword ptr [esp + 0x30], ebx
// 0045974d  8b11                 mov edx, dword ptr [ecx]
// 0045974f  8b525c               mov edx, dword ptr [edx + 0x5c]
// 00459752  53                   push ebx
// 00459753  53                   push ebx
// 00459754  ffd2                 call edx
// 00459756  5f                   pop edi
// 00459757  5d                   pop ebp
// 00459758  85c0                 test eax, eax
// 0045975a  750e                 jne 0x45976a
// 0045975c  899ed8010000         mov dword ptr [esi + 0x1d8], ebx
// 00459762  5e                   pop esi
// 00459763  5b                   pop ebx
// 00459764  83c410               add esp, 0x10
// 00459767  c20800               ret 8
// 0045976a  385c2420             cmp byte ptr [esp + 0x20], bl
// 0045976e  7433                 je 0x4597a3
// 00459770  8b86d8010000         mov eax, dword ptr [esi + 0x1d8]
// 00459776  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00459779  53                   push ebx
// 0045977a  53                   push ebx
// 0045977b  6864030000           push 0x364
// 00459780  51                   push ecx
// 00459781  ff15142e8000         call dword ptr [0x802e14]
// 00459787  8bce                 mov ecx, esi
// 00459789  e822fbffff           call 0x4592b0
// 0045978e  5e                   pop esi
// 0045978f  5b                   pop ebx
// 00459790  83c410               add esp, 0x10
// 00459793  c20800               ret 8
// 00459796  8b11                 mov edx, dword ptr [ecx]
// 00459798  8b4268               mov eax, dword ptr [edx + 0x68]
// 0045979b  ffd0                 call eax
// 0045979d  899ed8010000         mov dword ptr [esi + 0x1d8], ebx
// 004597a3  8bce                 mov ecx, esi
// 004597a5  e806fbffff           call 0x4592b0
// 004597aa  5e                   pop esi
// 004597ab  5b                   pop ebx
// 004597ac  83c410               add esp, 0x10
// 004597af  c20800               ret 8

extern char* func_0046a580();
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

struct Ref {
    void** vtable;
};

struct Rect {
    long left, top, right, bottom;
};

struct View;

struct Window {
    void** vtable;
    char padding0[28];
    void* handle;
    char padding1[212];
    void* owner;
    Ref* reference;
};

struct Factory {
    Window* create();
};

struct Data {
    char padding[148];
    Ref* reference;
};

struct View {
    char padding0[84];
    Data* data;
    char padding1[88];
    char owner[296];
    Window* window;

    void update();
    void setEnabled(unsigned char enabled, bool notify);
};

void View::setEnabled(unsigned char enabled, bool notify)
{
    if (enabled == static_cast<unsigned char>(window != 0))
        return;

    if (enabled) {
        Window* w = reinterpret_cast<Factory*>(func_0046a580())->create();
        window = w;
        Ref* r = data->reference;

        if (w->reference != r) {
            if (r)
                reinterpret_cast<unsigned long (__stdcall*)(Ref*)>(
                    r->vtable[1])(r);

            Ref* old = w->reference;
            if (old)
                reinterpret_cast<unsigned long (__stdcall*)(Ref*)>(
                    old->vtable[2])(old);

            w->reference = r;
        }

        window->owner = owner;
        Rect rect = { 0, 0, 0, 0 };

        if (!reinterpret_cast<int (__thiscall*)(Window*, const char*,
                const char*, unsigned long, const Rect&, View*,
                unsigned int, void*)>(window->vtable[23])(
                    window, 0, 0, 0x50000000UL, rect, this, 0x413, 0)) {
            window = 0;
            return;
        }

        if (notify)
            SendMessageA(window->handle, 0x364, 0, 0);
    } else {
        reinterpret_cast<int (__thiscall*)(Window*)>(
            window->vtable[26])(window);
        window = 0;
    }

    update();
}
