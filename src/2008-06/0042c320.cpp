// from server: 100% by coldek
// from server: 100% by king_originala
// roc 2008-06 0042c320  unit: CLuaHtmlView::Binder  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042c320
//
// 0042c320  55                   push ebp
// 0042c321  8bec                 mov ebp, esp
// 0042c323  6aff                 push -1
// 0042c325  6880f67b00           push 0x7bf680
// 0042c32a  64a100000000         mov eax, dword ptr fs:[0]
// 0042c330  50                   push eax
// 0042c331  64892500000000       mov dword ptr fs:[0], esp
// 0042c338  83ec08               sub esp, 8
// 0042c33b  53                   push ebx
// 0042c33c  56                   push esi
// 0042c33d  8bf1                 mov esi, ecx
// 0042c33f  8b06                 mov eax, dword ptr [esi]
// 0042c341  57                   push edi
// 0042c342  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042c345  8975ec               mov dword ptr [ebp - 0x14], esi
// 0042c348  85c0                 test eax, eax
// 0042c34a  7418                 je 0x42c364
// 0042c34c  8b00                 mov eax, dword ptr [eax]
// 0042c34e  8d4e08               lea ecx, [esi + 8]
// 0042c351  85c0                 test eax, eax
// 0042c353  7409                 je 0x42c35e
// 0042c355  6a01                 push 1
// 0042c357  51                   push ecx
// 0042c358  51                   push ecx
// 0042c359  ffd0                 call eax
// 0042c35b  83c40c               add esp, 0xc
// 0042c35e  c70600000000         mov dword ptr [esi], 0
// 0042c364  a158068100           mov eax, dword ptr [0x810658]
// 0042c369  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0042c370  8d7e08               lea edi, [esi + 8]
// 0042c373  85c0                 test eax, eax
// 0042c375  7409                 je 0x42c380
// 0042c377  6a01                 push 1
// 0042c379  57                   push edi
// 0042c37a  57                   push edi
// 0042c37b  ffd0                 call eax
// 0042c37d  83c40c               add esp, 0xc
// 0042c380  8b4508               mov eax, dword ptr [ebp + 8]
// 0042c383  85c0                 test eax, eax
// 0042c385  741c                 je 0x42c3a3
// 0042c387  8907                 mov dword ptr [edi], eax
// 0042c389  c70658068100         mov dword ptr [esi], 0x810658
// 0042c38f  eb18                 jmp 0x42c3a9

typedef void (__cdecl *Manager)(void *, void *, int);
extern Manager globalManager;

struct Binder {
    Manager *manager;
    unsigned int reserved;
    unsigned int storage;

    Binder &assign(unsigned int value);
};

Binder &Binder::assign(unsigned int value)
{
    if (manager) {
        Manager callback = *manager;
        unsigned int *destination = &storage;
        if (callback)
            callback(destination, destination, 1);
        manager = 0;
    }

    try {
        Manager callback = globalManager;
        unsigned int *destination = &storage;
        if (callback)
            callback(destination, destination, 1);

        if (value) {
            *destination = value;
            manager = &globalManager;
        } else {
            manager = 0;
        }
    } catch (...) {
        manager = 0;
        throw;
    }

    return *this;
}
