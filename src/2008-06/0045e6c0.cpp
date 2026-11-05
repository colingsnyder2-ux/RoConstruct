// from server: 100% by EspClaude
// from server: 98% by king_originala
// roc 2008-06 0045e6c0  unit: CRobloxWnd  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045e6c0
//
// 0045e6c0  64a100000000         mov eax, dword ptr fs:[0]
// 0045e6c6  6aff                 push -1
// 0045e6c8  6848e97b00           push 0x7be948
// 0045e6cd  50                   push eax
// 0045e6ce  64892500000000       mov dword ptr fs:[0], esp
// 0045e6d5  83ec08               sub esp, 8
// 0045e6d8  56                   push esi
// 0045e6d9  8bf1                 mov esi, ecx
// 0045e6db  80be8900000000       cmp byte ptr [esi + 0x89], 0
// 0045e6e2  57                   push edi
// 0045e6e3  8dbe89000000         lea edi, [esi + 0x89]
// 0045e6e9  0f859a000000         jne 0x45e789
// 0045e6ef  8a07                 mov al, byte ptr [edi]
// 0045e6f1  897c2408             mov dword ptr [esp + 8], edi
// 0045e6f5  8844240c             mov byte ptr [esp + 0xc], al
// 0045e6f9  c60701               mov byte ptr [edi], 1
// 0045e6fc  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045e6ff  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045e707  85c9                 test ecx, ecx
// 0045e709  7529                 jne 0x45e734
// 0045e70b  d9e8                 fld1 
// 0045e70d  83ec10               sub esp, 0x10
// 0045e710  d95c240c             fstp dword ptr [esp + 0xc]
// 0045e714  d9ee                 fldz 
// 0045e716  d9542408             fst dword ptr [esp + 8]
// 0045e71a  d9542404             fst dword ptr [esp + 4]
// 0045e71e  d91c24               fstp dword ptr [esp]
// 0045e721  ff15a4298000         call dword ptr [0x8029a4]
// 0045e727  6800410000           push 0x4100
// 0045e72c  ff15a0298000         call dword ptr [0x8029a0]
// 0045e732  eb4f                 jmp 0x45e783
// 0045e734  83beb000000000       cmp dword ptr [esi + 0xb0], 0
// 0045e73b  7512                 jne 0x45e74f
// 0045e73d  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 0045e740  85c9                 test ecx, ecx
// 0045e742  743f                 je 0x45e783
// 0045e744  8d4654               lea eax, [esi + 0x54]
// 0045e747  50                   push eax
// 0045e748  e8936e0f00           call 0x5555e0
// 0045e74d  eb34                 jmp 0x45e783
// 0045e74f  e84c07fcff           call 0x41eea0
// 0045e754  a3744d9700           mov dword ptr [0x974d74], eax
// 0045e759  837e5c02             cmp dword ptr [esi + 0x5c], 2
// 0045e75d  750e                 jne 0x45e76d
// 0045e75f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0045e763  51                   push ecx
// 0045e764  8bce                 mov ecx, esi
// 0045e766  e815d5ffff           call 0x45bc80
// 0045e76b  eb0c                 jmp 0x45e779
// 0045e76d  8b542420             mov edx, dword ptr [esp + 0x20]
// 0045e771  52                   push edx
// 0045e772  8bce                 mov ecx, esi
// 0045e774  e877fcffff           call 0x45e3f0
// 0045e779  c705744d970000000000 mov dword ptr [0x974d74], 0
// 0045e783  8a44240c             mov al, byte ptr [esp + 0xc]
// 0045e787  8807                 mov byte ptr [edi], al
// 0045e789  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045e78d  5f                   pop edi
// 0045e78e  5e                   pop esi
// 0045e78f  64890d00000000       mov dword ptr fs:[0], ecx
// 0045e796  83c414               add esp, 0x14
// 0045e799  c20400               ret 4

extern "C" {
    extern void (__stdcall * const glClearColor)(float, float, float, float);
    extern void (__stdcall * const glClear)(unsigned int);
}

struct Context {
    void* get();
};

struct View;
struct Renderer {
    void render(View*);
};

extern void* currentContext;

struct FlagGuard {
    bool* flag;
    volatile bool saved;

    FlagGuard(bool&);
    ~FlagGuard();
};

__forceinline FlagGuard::FlagGuard(bool& value)
    : flag(&value), saved(value) {
    value = true;
}

__forceinline FlagGuard::~FlagGuard() {
    *flag = saved;
}

struct Base0 {
    unsigned char padding0[0x54];
};

struct View {
    int viewport[2];
    int mode;
};

struct CRobloxWnd : Base0, View {
    unsigned char padding1[0x10];
    Context* context;
    unsigned char padding2[4];
    Renderer* renderer;
    unsigned char padding3[0x0d];
    bool rendering;
    unsigned char padding4[0x26];
    int enabled;

    void draw(void*);
    void drawFirst(void*);
    void drawSecond(void*);
};

void CRobloxWnd::draw(void* argument) {
    if (rendering)
        return;

    FlagGuard guard(rendering);

    if (!context) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(0x4100);
    } else if (!enabled) {
        if (renderer)
            renderer->render(this);
    } else {
        currentContext = context->get();
        if (mode == 2)
            drawFirst(argument);
        else
            drawSecond(argument);
        currentContext = 0;
    }
}
