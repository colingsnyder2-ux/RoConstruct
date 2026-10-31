// from server: 95% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 00430b40  unit: CMainFrame  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00430b40
//
// 00430b40  56                   push esi
// 00430b41  8bf1                 mov esi, ecx
// 00430b43  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 00430b4a  57                   push edi
// 00430b4b  750d                 jne 0x430b5a
// 00430b4d  80bef900000000       cmp byte ptr [esi + 0xf9], 0
// 00430b54  7504                 jne 0x430b5a
// 00430b56  33ff                 xor edi, edi
// 00430b58  eb05                 jmp 0x430b5f
// 00430b5a  bf01000000           mov edi, 1
// 00430b5f  e8c2fd2600           call 0x6a0926
// 00430b64  8b4004               mov eax, dword ptr [eax + 4]
// 00430b67  57                   push edi
// 00430b68  6824128100           push 0x811224
// 00430b6d  6818128100           push 0x811218
// 00430b72  8bc8                 mov ecx, eax
// 00430b74  e8c1042700           call 0x6a103a
// 00430b79  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 00430b80  7409                 je 0x430b8b
// 00430b82  8bce                 mov ecx, esi
// 00430b84  e8d7f5ffff           call 0x430160
// 00430b89  eb13                 jmp 0x430b9e
// 00430b8b  6a00                 push 0
// 00430b8d  689c088100           push 0x81089c
// 00430b92  56                   push esi
// 00430b93  8d8e0c010000         lea ecx, [esi + 0x10c]
// 00430b99  e8123f2b00           call 0x6e4ab0
// 00430b9e  80be0401000000       cmp byte ptr [esi + 0x104], 0
// 00430ba5  7409                 je 0x430bb0
// 00430ba7  6a00                 push 0
// 00430ba9  8bce                 mov ecx, esi
// 00430bab  e830fcffff           call 0x4307e0
// 00430bb0  8bce                 mov ecx, esi
// 00430bb2  e87d042700           call 0x6a1034
// 00430bb7  5f                   pop edi
// 00430bb8  8d8e84020000         lea ecx, [esi + 0x284]
// 00430bbe  5e                   pop esi
// 00430bbf  e90c492d00           jmp 0x7054d0

// from server: 89% by king_originala
// roc 2008-06 00430b40  unit: CMainFrame  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00430b40
//
// 00430b40  56                   push esi
// 00430b41  8bf1                 mov esi, ecx
// 00430b43  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 00430b4a  57                   push edi
// 00430b4b  750d                 jne 0x430b5a
// 00430b4d  80bef900000000       cmp byte ptr [esi + 0xf9], 0
// 00430b54  7504                 jne 0x430b5a
// 00430b56  33ff                 xor edi, edi
// 00430b58  eb05                 jmp 0x430b5f
// 00430b5a  bf01000000           mov edi, 1
// 00430b5f  e8c2fd2600           call 0x6a0926
// 00430b64  8b4004               mov eax, dword ptr [eax + 4]
// 00430b67  57                   push edi
// 00430b68  6824128100           push 0x811224
// 00430b6d  6818128100           push 0x811218
// 00430b72  8bc8                 mov ecx, eax
// 00430b74  e8c1042700           call 0x6a103a
// 00430b79  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 00430b80  7409                 je 0x430b8b
// 00430b82  8bce                 mov ecx, esi
// 00430b84  e8d7f5ffff           call 0x430160
// 00430b89  eb13                 jmp 0x430b9e
// 00430b8b  6a00                 push 0
// 00430b8d  689c088100           push 0x81089c
// 00430b92  56                   push esi
// 00430b93  8d8e0c010000         lea ecx, [esi + 0x10c]
// 00430b99  e8123f2b00           call 0x6e4ab0
// 00430b9e  80be0401000000       cmp byte ptr [esi + 0x104], 0
// 00430ba5  7409                 je 0x430bb0
// 00430ba7  6a00                 push 0
// 00430ba9  8bce                 mov ecx, esi
// 00430bab  e830fcffff           call 0x4307e0
// 00430bb0  8bce                 mov ecx, esi
// 00430bb2  e87d042700           call 0x6a1034
// 00430bb7  5f                   pop edi
// 00430bb8  8d8e84020000         lea ecx, [esi + 0x284]
// 00430bbe  5e                   pop esi
// 00430bbf  e90c492d00           jmp 0x7054d0

struct CMainFrame;

struct Settings
{
    void set(const char*, const char*, int);
};

struct Application
{
    unsigned int reserved;
    Settings* volatile settings;
};

extern Application* __cdecl getApplication();

struct FrameBinding
{
    char storage[0x178];
    void bind(CMainFrame*, const char*, int);
};

struct Finalizer
{
    void finish();
};

struct CMainFrame
{
    char reserved0[0xf8];
    bool fullscreen;
    bool alternateFullscreen;
    char reserved1[0x0a];
    bool loadEnabled;
    char reserved2[7];
    FrameBinding binding;
    Finalizer finalizer;

    void update();
    void updateFullscreen();
    int Load(int);
    void updateFrame();
};

void CMainFrame::update()
{
    int enabled = (fullscreen || alternateFullscreen) ? 1 : 0;
    Settings* settings = getApplication()->settings;
    settings->set("Settings", "fullscreen", enabled);

    if (fullscreen)
        updateFullscreen();
    else
        binding.bind(this, "CMainFrameV2", 0);

    if (loadEnabled)
        Load(0);

    updateFrame();
    finalizer.finish();
}
