// from server: 100% by EspClaude
// roc 2009-06 006cafa0  unit: RBX::RocketTool  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cafa0
//
// 006cafa0  6aff                 push -1
// 006cafa2  68610d8700           push 0x870d61
// 006cafa7  64a100000000         mov eax, dword ptr fs:[0]
// 006cafad  50                   push eax
// 006cafae  64892500000000       mov dword ptr fs:[0], esp
// 006cafb5  83ec20               sub esp, 0x20
// 006cafb8  53                   push ebx
// 006cafb9  56                   push esi
// 006cafba  57                   push edi
// 006cafbb  33db                 xor ebx, ebx
// 006cafbd  6a04                 push 4
// 006cafbf  8bf1                 mov esi, ecx
// 006cafc1  895c2410             mov dword ptr [esp + 0x10], ebx
// 006cafc5  e86eda0400           call 0x718a38
// 006cafca  83c404               add esp, 4
// 006cafcd  3bc3                 cmp eax, ebx
// 006cafcf  7408                 je 0x6cafd9
// 006cafd1  8d4c2414             lea ecx, [esp + 0x14]
// 006cafd5  8908                 mov dword ptr [eax], ecx
// 006cafd7  eb02                 jmp 0x6cafdb
// 006cafd9  33c0                 xor eax, eax
// 006cafdb  89442414             mov dword ptr [esp + 0x14], eax
// 006cafdf  895c2420             mov dword ptr [esp + 0x20], ebx
// 006cafe3  895c2424             mov dword ptr [esp + 0x24], ebx
// 006cafe7  895c2428             mov dword ptr [esp + 0x28], ebx
// 006cafeb  8d542414             lea edx, [esp + 0x14]
// 006cafef  52                   push edx
// 006caff0  83ec20               sub esp, 0x20
// 006caff3  8bc4                 mov eax, esp
// 006caff5  89642434             mov dword ptr [esp + 0x34], esp
// 006caff9  6838c68e00           push 0x8ec638
// 006caffe  50                   push eax
// 006cafff  c744246002000000     mov dword ptr [esp + 0x60], 2
// 006cb007  e884dcf0ff           call 0x5d8c90
// 006cb00c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006cb00f  51                   push ecx
// 006cb010  c644246403           mov byte ptr [esp + 0x64], 3
// 006cb015  e846afd9ff           call 0x465f60
// 006cb01a  83c40c               add esp, 0xc
// 006cb01d  8bc8                 mov ecx, eax
// 006cb01f  c644245802           mov byte ptr [esp + 0x58], 2
// 006cb024  e8775df1ff           call 0x5e0da0
// 006cb029  8b442420             mov eax, dword ptr [esp + 0x20]
// 006cb02d  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006cb033  8bf0                 mov esi, eax
// 006cb035  3b442424             cmp eax, dword ptr [esp + 0x24]
// 006cb039  7602                 jbe 0x6cb03d
// 006cb03b  ffd7                 call edi
// 006cb03d  8b442414             mov eax, dword ptr [esp + 0x14]
// 006cb041  3bc3                 cmp eax, ebx
// 006cb043  7544                 jne 0x6cb089
// 006cb045  ffd7                 call edi
// 006cb047  33c0                 xor eax, eax
// 006cb049  3b7010               cmp esi, dword ptr [eax + 0x10]
// 006cb04c  7202                 jb 0x6cb050
// 006cb04e  ffd7                 call edi
// 006cb050  56                   push esi
// 006cb051  8b742440             mov esi, dword ptr [esp + 0x40]
// 006cb055  56                   push esi
// 006cb056  e8c570e1ff           call 0x4e2120
// 006cb05b  83c408               add esp, 8
// 006cb05e  8d4c2414             lea ecx, [esp + 0x14]
// 006cb062  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 006cb06a  885c2434             mov byte ptr [esp + 0x34], bl
// 006cb06e  e84d090400           call 0x70b9c0
// 006cb073  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006cb077  5f                   pop edi
// 006cb078  8bc6                 mov eax, esi
// 006cb07a  5e                   pop esi
// 006cb07b  64890d00000000       mov dword ptr fs:[0], ecx
// 006cb082  5b                   pop ebx
// 006cb083  83c42c               add esp, 0x2c
// 006cb086  c20400               ret 4
// 006cb089  8b00                 mov eax, dword ptr [eax]
// 006cb08b  ebbc                 jmp 0x6cb049
// copied from an identical function in another client (function ?func@SlingshotTool@@QAE?AUSharedPtr@@XZ)

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

String __cdecl makeString(const char*);

struct ServiceProvider {
    void load(String, Vector*);
};

ServiceProvider* __cdecl func_00465210(Instance*);

struct SlingshotTool {
    char padding[0x18];
    Instance* instance;
    SharedPtr func();
};

SharedPtr SlingshotTool::func() {
    VectorBuy result;
    func_00465210(instance)->load(
        makeString("Fonts\\Rocket.rbxm"), &result);

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