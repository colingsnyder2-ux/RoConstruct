// from server: 100% by user
// from server: 99% by colin
// roc 2008-06 0063ea30  unit: RBX::SlingshotTool  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063ea30
//
// 0063ea30  6aff                 push -1
// 0063ea32  68a1a87d00           push 0x7da8a1
// 0063ea37  64a100000000         mov eax, dword ptr fs:[0]
// 0063ea3d  50                   push eax
// 0063ea3e  64892500000000       mov dword ptr fs:[0], esp
// 0063ea45  83ec20               sub esp, 0x20
// 0063ea48  53                   push ebx
// 0063ea49  56                   push esi
// 0063ea4a  57                   push edi
// 0063ea4b  33db                 xor ebx, ebx
// 0063ea4d  6a04                 push 4
// 0063ea4f  8bf1                 mov esi, ecx
// 0063ea51  895c2410             mov dword ptr [esp + 0x10], ebx
// 0063ea55  e8c61e0600           call 0x6a0920
// 0063ea5a  83c404               add esp, 4
// 0063ea5d  3bc3                 cmp eax, ebx
// 0063ea5f  7408                 je 0x63ea69
// 0063ea61  8d4c2414             lea ecx, [esp + 0x14]
// 0063ea65  8908                 mov dword ptr [eax], ecx
// 0063ea67  eb02                 jmp 0x63ea6b
// 0063ea69  33c0                 xor eax, eax
// 0063ea6b  89442414             mov dword ptr [esp + 0x14], eax
// 0063ea6f  895c2420             mov dword ptr [esp + 0x20], ebx
// 0063ea73  895c2424             mov dword ptr [esp + 0x24], ebx
// 0063ea77  895c2428             mov dword ptr [esp + 0x28], ebx
// 0063ea7b  8d542414             lea edx, [esp + 0x14]
// 0063ea7f  52                   push edx
// 0063ea80  83ec20               sub esp, 0x20
// 0063ea83  8bc4                 mov eax, esp
// 0063ea85  89642434             mov dword ptr [esp + 0x34], esp
// 0063ea89  68b0a38400           push 0x84a3b0
// 0063ea8e  50                   push eax
// 0063ea8f  c744246002000000     mov dword ptr [esp + 0x60], 2
// 0063ea97  e8e4d2f1ff           call 0x55bd80
// 0063ea9c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063ea9f  51                   push ecx
// 0063eaa0  c644246403           mov byte ptr [esp + 0x64], 3
// 0063eaa5  e86667e2ff           call 0x465210
// 0063eaaa  83c40c               add esp, 0xc
// 0063eaad  8bc8                 mov ecx, eax
// 0063eaaf  c644245802           mov byte ptr [esp + 0x58], 2
// 0063eab4  e8273ef2ff           call 0x5628e0
// 0063eab9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063eabd  8b3d90288000         mov edi, dword ptr [0x802890]
// 0063eac3  8bf0                 mov esi, eax
// 0063eac5  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0063eac9  7602                 jbe 0x63eacd
// 0063eacb  ffd7                 call edi
// 0063eacd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063ead1  3bc3                 cmp eax, ebx
// 0063ead3  7544                 jne 0x63eb19
// 0063ead5  ffd7                 call edi
// 0063ead7  33c0                 xor eax, eax
// 0063ead9  3b7010               cmp esi, dword ptr [eax + 0x10]
// 0063eadc  7202                 jb 0x63eae0
// 0063eade  ffd7                 call edi
// 0063eae0  56                   push esi
// 0063eae1  8b742440             mov esi, dword ptr [esp + 0x40]
// 0063eae5  56                   push esi
// 0063eae6  e8952bf6ff           call 0x5a1680
// 0063eaeb  83c408               add esp, 8
// 0063eaee  8d4c2414             lea ecx, [esp + 0x14]
// 0063eaf2  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0063eafa  885c2434             mov byte ptr [esp + 0x34], bl
// 0063eafe  e8dd44f6ff           call 0x5a2fe0
// 0063eb03  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0063eb07  5f                   pop edi
// 0063eb08  8bc6                 mov eax, esi
// 0063eb0a  5e                   pop esi
// 0063eb0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0063eb12  5b                   pop ebx
// 0063eb13  83c42c               add esp, 0x2c
// 0063eb16  c20400               ret 4
// 0063eb19  8b00                 mov eax, dword ptr [eax]
// 0063eb1b  ebbc                 jmp 0x63ead9

// from server: 92% by colin
// roc 2008-06 0063ea30  unit: RBX::SlingshotTool  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063ea30
//
// 0063ea30  6aff                 push -1
// 0063ea32  68a1a87d00           push 0x7da8a1
// 0063ea37  64a100000000         mov eax, dword ptr fs:[0]
// 0063ea3d  50                   push eax
// 0063ea3e  64892500000000       mov dword ptr fs:[0], esp
// 0063ea45  83ec20               sub esp, 0x20
// 0063ea48  53                   push ebx
// 0063ea49  56                   push esi
// 0063ea4a  57                   push edi
// 0063ea4b  33db                 xor ebx, ebx
// 0063ea4d  6a04                 push 4
// 0063ea4f  8bf1                 mov esi, ecx
// 0063ea51  895c2410             mov dword ptr [esp + 0x10], ebx
// 0063ea55  e8c61e0600           call 0x6a0920
// 0063ea5a  83c404               add esp, 4
// 0063ea5d  3bc3                 cmp eax, ebx
// 0063ea5f  7408                 je 0x63ea69
// 0063ea61  8d4c2414             lea ecx, [esp + 0x14]
// 0063ea65  8908                 mov dword ptr [eax], ecx
// 0063ea67  eb02                 jmp 0x63ea6b
// 0063ea69  33c0                 xor eax, eax
// 0063ea6b  89442414             mov dword ptr [esp + 0x14], eax
// 0063ea6f  895c2420             mov dword ptr [esp + 0x20], ebx
// 0063ea73  895c2424             mov dword ptr [esp + 0x24], ebx
// 0063ea77  895c2428             mov dword ptr [esp + 0x28], ebx
// 0063ea7b  8d542414             lea edx, [esp + 0x14]
// 0063ea7f  52                   push edx
// 0063ea80  83ec20               sub esp, 0x20
// 0063ea83  8bc4                 mov eax, esp
// 0063ea85  89642434             mov dword ptr [esp + 0x34], esp
// 0063ea89  68b0a38400           push 0x84a3b0
// 0063ea8e  50                   push eax
// 0063ea8f  c744246002000000     mov dword ptr [esp + 0x60], 2
// 0063ea97  e8e4d2f1ff           call 0x55bd80
// 0063ea9c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063ea9f  51                   push ecx
// 0063eaa0  c644246403           mov byte ptr [esp + 0x64], 3
// 0063eaa5  e86667e2ff           call 0x465210
// 0063eaaa  83c40c               add esp, 0xc
// 0063eaad  8bc8                 mov ecx, eax
// 0063eaaf  c644245802           mov byte ptr [esp + 0x58], 2
// 0063eab4  e8273ef2ff           call 0x5628e0
// 0063eab9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063eabd  8b3d90288000         mov edi, dword ptr [0x802890]
// 0063eac3  8bf0                 mov esi, eax
// 0063eac5  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0063eac9  7602                 jbe 0x63eacd
// 0063eacb  ffd7                 call edi
// 0063eacd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063ead1  3bc3                 cmp eax, ebx
// 0063ead3  7544                 jne 0x63eb19
// 0063ead5  ffd7                 call edi
// 0063ead7  33c0                 xor eax, eax
// 0063ead9  3b7010               cmp esi, dword ptr [eax + 0x10]
// 0063eadc  7202                 jb 0x63eae0
// 0063eade  ffd7                 call edi
// 0063eae0  56                   push esi
// 0063eae1  8b742440             mov esi, dword ptr [esp + 0x40]
// 0063eae5  56                   push esi
// 0063eae6  e8952bf6ff           call 0x5a1680
// 0063eaeb  83c408               add esp, 8
// 0063eaee  8d4c2414             lea ecx, [esp + 0x14]
// 0063eaf2  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0063eafa  885c2434             mov byte ptr [esp + 0x34], bl
// 0063eafe  e8dd44f6ff           call 0x5a2fe0
// 0063eb03  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0063eb07  5f                   pop edi
// 0063eb08  8bc6                 mov eax, esi
// 0063eb0a  5e                   pop esi
// 0063eb0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0063eb12  5b                   pop ebx
// 0063eb13  83c42c               add esp, 0x2c
// 0063eb16  c20400               ret 4
// 0063eb19  8b00                 mov eax, dword ptr [eax]
// 0063eb1b  ebbc                 jmp 0x63ead9

// from server: 89% by king_originala
// roc 2008-06 0063ea30  unit: RBX::SlingshotTool  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063ea30
//
// 0063ea30  6aff                 push -1
// 0063ea32  68a1a87d00           push 0x7da8a1
// 0063ea37  64a100000000         mov eax, dword ptr fs:[0]
// 0063ea3d  50                   push eax
// 0063ea3e  64892500000000       mov dword ptr fs:[0], esp
// 0063ea45  83ec20               sub esp, 0x20
// 0063ea48  53                   push ebx
// 0063ea49  56                   push esi
// 0063ea4a  57                   push edi
// 0063ea4b  33db                 xor ebx, ebx
// 0063ea4d  6a04                 push 4
// 0063ea4f  8bf1                 mov esi, ecx
// 0063ea51  895c2410             mov dword ptr [esp + 0x10], ebx
// 0063ea55  e8c61e0600           call 0x6a0920
// 0063ea5a  83c404               add esp, 4
// 0063ea5d  3bc3                 cmp eax, ebx
// 0063ea5f  7408                 je 0x63ea69
// 0063ea61  8d4c2414             lea ecx, [esp + 0x14]
// 0063ea65  8908                 mov dword ptr [eax], ecx
// 0063ea67  eb02                 jmp 0x63ea6b
// 0063ea69  33c0                 xor eax, eax
// 0063ea6b  89442414             mov dword ptr [esp + 0x14], eax
// 0063ea6f  895c2420             mov dword ptr [esp + 0x20], ebx
// 0063ea73  895c2424             mov dword ptr [esp + 0x24], ebx
// 0063ea77  895c2428             mov dword ptr [esp + 0x28], ebx
// 0063ea7b  8d542414             lea edx, [esp + 0x14]
// 0063ea7f  52                   push edx
// 0063ea80  83ec20               sub esp, 0x20
// 0063ea83  8bc4                 mov eax, esp
// 0063ea85  89642434             mov dword ptr [esp + 0x34], esp
// 0063ea89  68b0a38400           push 0x84a3b0
// 0063ea8e  50                   push eax
// 0063ea8f  c744246002000000     mov dword ptr [esp + 0x60], 2
// 0063ea97  e8e4d2f1ff           call 0x55bd80
// 0063ea9c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0063ea9f  51                   push ecx
// 0063eaa0  c644246403           mov byte ptr [esp + 0x64], 3
// 0063eaa5  e86667e2ff           call 0x465210
// 0063eaaa  83c40c               add esp, 0xc
// 0063eaad  8bc8                 mov ecx, eax
// 0063eaaf  c644245802           mov byte ptr [esp + 0x58], 2
// 0063eab4  e8273ef2ff           call 0x5628e0
// 0063eab9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063eabd  8b3d90288000         mov edi, dword ptr [0x802890]
// 0063eac3  8bf0                 mov esi, eax
// 0063eac5  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0063eac9  7602                 jbe 0x63eacd
// 0063eacb  ffd7                 call edi
// 0063eacd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063ead1  3bc3                 cmp eax, ebx
// 0063ead3  7544                 jne 0x63eb19
// 0063ead5  ffd7                 call edi
// 0063ead7  33c0                 xor eax, eax
// 0063ead9  3b7010               cmp esi, dword ptr [eax + 0x10]
// 0063eadc  7202                 jb 0x63eae0
// 0063eade  ffd7                 call edi
// 0063eae0  56                   push esi
// 0063eae1  8b742440             mov esi, dword ptr [esp + 0x40]
// 0063eae5  56                   push esi
// 0063eae6  e8952bf6ff           call 0x5a1680
// 0063eaeb  83c408               add esp, 8
// 0063eaee  8d4c2414             lea ecx, [esp + 0x14]
// 0063eaf2  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0063eafa  885c2434             mov byte ptr [esp + 0x34], bl
// 0063eafe  e8dd44f6ff           call 0x5a2fe0
// 0063eb03  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0063eb07  5f                   pop edi
// 0063eb08  8bc6                 mov eax, esi
// 0063eb0a  5e                   pop esi
// 0063eb0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0063eb12  5b                   pop ebx
// 0063eb13  83c42c               add esp, 0x2c
// 0063eb16  c20400               ret 4
// 0063eb19  8b00                 mov eax, dword ptr [eax]
// 0063eb1b  ebbc                 jmp 0x63ead9
extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);


struct SharedPtr;
void __cdecl copySharedPtr(SharedPtr*, const SharedPtr*);

struct SharedPtr {
    void* object;
    void* control;
    SharedPtr(const SharedPtr&);
    ~SharedPtr();
};

inline SharedPtr::SharedPtr(const SharedPtr& source) {
    copySharedPtr(this, &source);
}

struct Allocator {
    char storage[4];
    ~Allocator();
};

inline Allocator::~Allocator() {
}

struct String;
String* __cdecl initializeString(String*, const char*);

struct String {
    Allocator allocator;
    char storage[28];
    String(const char*);
    String(const String&);
    ~String();
};

inline String::String(const char* text) {
    initializeString(this, text);
}

struct Instance;

struct Vector {
    struct Proxy {
        Vector* owner;
        Proxy(Vector*);
    };

    Proxy* proxy;
    char allocator1[4];
    char allocator2[4];
    SharedPtr* first;
    SharedPtr* last;
    SharedPtr* limit;

    Vector();
    ~Vector();
};

inline Vector::Proxy::Proxy(Vector* value) : owner(value) {
}

struct VectorBuy : Vector {
    VectorBuy();
    ~VectorBuy();
    bool buy(unsigned int capacity)
    {
        first = 0; last = 0; limit = 0;
        if (capacity == 0)
            return false;
        first = (SharedPtr*)operator new(capacity * sizeof(SharedPtr));
        last = first;
        limit = first + capacity;
        return true;
    }
};

inline Vector::Vector()
    : proxy(new Proxy(this)) {
}

inline VectorBuy::VectorBuy() {
    buy(0);
}

struct ServiceProvider {
    void load(String, Vector*);
};

ServiceProvider* __cdecl func_00465210(Instance*);

struct SlingshotTool {
    char padding[0x18];
    Instance* instance;
    SharedPtr func();
};

String __cdecl makeString(const char*);

SharedPtr SlingshotTool::func() {
    VectorBuy result;
    func_00465210(instance)->load(
        makeString("Fonts\\SlingshotPellet.rbxm"), &result);

    SharedPtr* position = result.first;

    if (position > result.last)
        _invalid_parameter_noinfo();

    Vector::Proxy* aux = result.proxy;
    if (!(aux != 0))
        _invalid_parameter_noinfo();
    Vector* owner = aux ? aux->owner : 0;

    if (position >= owner->last)
        _invalid_parameter_noinfo();

    return *position;
}
