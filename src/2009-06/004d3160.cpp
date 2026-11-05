// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2009-06 004d3160  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d3160
//
// 004d3160  6aff                 push -1
// 004d3162  680ab18500           push 0x85b10a
// 004d3167  64a100000000         mov eax, dword ptr fs:[0]
// 004d316d  50                   push eax
// 004d316e  64892500000000       mov dword ptr fs:[0], esp
// 004d3175  83ec1c               sub esp, 0x1c
// 004d3178  55                   push ebp
// 004d3179  57                   push edi
// 004d317a  8be9                 mov ebp, ecx
// 004d317c  6a03                 push 3
// 004d317e  8d4c2410             lea ecx, [esp + 0x10]
// 004d3182  c744243001000000     mov dword ptr [esp + 0x30], 1
// 004d318a  e8b1b2feff           call 0x4be440
// 004d318f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d3193  2b442418             sub eax, dword ptr [esp + 0x18]
// 004d3197  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 004d319d  c1f802               sar eax, 2
// 004d31a0  c644242c02           mov byte ptr [esp + 0x2c], 2
// 004d31a5  85c0                 test eax, eax
// 004d31a7  7702                 ja 0x4d31ab
// 004d31a9  ffd7                 call edi
// 004d31ab  56                   push esi
// 004d31ac  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004d31b0  8d4c2438             lea ecx, [esp + 0x38]
// 004d31b4  51                   push ecx
// 004d31b5  8d4c2410             lea ecx, [esp + 0x10]
// 004d31b9  e8522ef5ff           call 0x426010
// 004d31be  3bc6                 cmp eax, esi
// 004d31c0  7408                 je 0x4d31ca
// 004d31c2  8b16                 mov edx, dword ptr [esi]
// 004d31c4  8b08                 mov ecx, dword ptr [eax]
// 004d31c6  8910                 mov dword ptr [eax], edx
// 004d31c8  890e                 mov dword ptr [esi], ecx
// 004d31ca  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d31ce  85c9                 test ecx, ecx
// 004d31d0  7408                 je 0x4d31da
// 004d31d2  8b01                 mov eax, dword ptr [ecx]
// 004d31d4  8b10                 mov edx, dword ptr [eax]
// 004d31d6  6a01                 push 1
// 004d31d8  ffd2                 call edx
// 004d31da  8b442420             mov eax, dword ptr [esp + 0x20]
// 004d31de  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 004d31e2  c1f802               sar eax, 2
// 004d31e5  83f801               cmp eax, 1
// 004d31e8  7702                 ja 0x4d31ec
// 004d31ea  ffd7                 call edi
// 004d31ec  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004d31f0  6a08                 push 8
// 004d31f2  83c604               add esi, 4
// 004d31f5  e83e582400           call 0x718a38
// 004d31fa  83c404               add esp, 4
// 004d31fd  85c0                 test eax, eax
// 004d31ff  740f                 je 0x4d3210
// 004d3201  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004d3205  c700b00c8b00         mov dword ptr [eax], 0x8b0cb0
// 004d320b  894804               mov dword ptr [eax + 4], ecx
// 004d320e  eb02                 jmp 0x4d3212
// 004d3210  33c0                 xor eax, eax
// 004d3212  8d542454             lea edx, [esp + 0x54]
// 004d3216  8bc8                 mov ecx, eax
// 004d3218  3bd6                 cmp edx, esi
// 004d321a  7404                 je 0x4d3220
// 004d321c  8b0e                 mov ecx, dword ptr [esi]
// 004d321e  8906                 mov dword ptr [esi], eax
// 004d3220  85c9                 test ecx, ecx
// 004d3222  7408                 je 0x4d322c
// 004d3224  8b01                 mov eax, dword ptr [ecx]
// 004d3226  8b10                 mov edx, dword ptr [eax]
// 004d3228  6a01                 push 1
// 004d322a  ffd2                 call edx
// 004d322c  8b442420             mov eax, dword ptr [esp + 0x20]
// 004d3230  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 004d3234  c1f802               sar eax, 2
// 004d3237  83f802               cmp eax, 2
// 004d323a  7702                 ja 0x4d323e
// 004d323c  ffd7                 call edi
// 004d323e  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004d3242  8d4c2458             lea ecx, [esp + 0x58]
// 004d3246  51                   push ecx
// 004d3247  8d4c2458             lea ecx, [esp + 0x58]
// 004d324b  83c608               add esi, 8
// 004d324e  e8bd2df5ff           call 0x426010
// 004d3253  3bc6                 cmp eax, esi
// 004d3255  7408                 je 0x4d325f
// 004d3257  8b16                 mov edx, dword ptr [esi]
// 004d3259  8b08                 mov ecx, dword ptr [eax]
// 004d325b  8910                 mov dword ptr [eax], edx
// 004d325d  890e                 mov dword ptr [esi], ecx
// 004d325f  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004d3263  5e                   pop esi
// 004d3264  85c9                 test ecx, ecx
// 004d3266  7408                 je 0x4d3270
// 004d3268  8b01                 mov eax, dword ptr [ecx]
// 004d326a  8b10                 mov edx, dword ptr [eax]
// 004d326c  6a01                 push 1
// 004d326e  ffd2                 call edx
// 004d3270  8b4500               mov eax, dword ptr [ebp]
// 004d3273  8b5004               mov edx, dword ptr [eax + 4]
// 004d3276  8d4c240c             lea ecx, [esp + 0xc]
// 004d327a  51                   push ecx
// 004d327b  8bcd                 mov ecx, ebp
// 004d327d  ffd2                 call edx
// 004d327f  8d4c240c             lea ecx, [esp + 0xc]
// 004d3283  c644242c01           mov byte ptr [esp + 0x2c], 1
// 004d3288  e8a3affeff           call 0x4be230
// 004d328d  8d4c2434             lea ecx, [esp + 0x34]
// 004d3291  c644242c00           mov byte ptr [esp + 0x2c], 0
// 004d3296  ff15c4e48900         call dword ptr [0x89e4c4]
// 004d329c  8d4c2454             lea ecx, [esp + 0x54]
// 004d32a0  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004d32a8  ff15c4e48900         call dword ptr [0x89e4c4]
// 004d32ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004d32b2  5f                   pop edi
// 004d32b3  5d                   pop ebp
// 004d32b4  64890d00000000       mov dword ptr fs:[0], ecx
// 004d32bb  83c428               add esp, 0x28
// 004d32be  c23c00               ret 0x3c

// from server: 100% by king_originala
// roc 2008-06 0049fa40  unit: RBX::Network::VClient::?$SignalDesc  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049fa40
//
// 0049fa40  6aff                 push -1
// 0049fa42  68ba777c00           push 0x7c77ba
// 0049fa47  64a100000000         mov eax, dword ptr fs:[0]
// 0049fa4d  50                   push eax
// 0049fa4e  64892500000000       mov dword ptr fs:[0], esp
// 0049fa55  83ec1c               sub esp, 0x1c
// 0049fa58  55                   push ebp
// 0049fa59  57                   push edi
// 0049fa5a  8be9                 mov ebp, ecx
// 0049fa5c  6a03                 push 3
// 0049fa5e  8d4c2410             lea ecx, [esp + 0x10]
// 0049fa62  c744243001000000     mov dword ptr [esp + 0x30], 1
// 0049fa6a  e801b7f7ff           call 0x41b170
// 0049fa6f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049fa73  2b442418             sub eax, dword ptr [esp + 0x18]
// 0049fa77  8b3d90288000         mov edi, dword ptr [0x802890]
// 0049fa7d  c1f802               sar eax, 2
// 0049fa80  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0049fa85  85c0                 test eax, eax
// 0049fa87  7702                 ja 0x49fa8b
// 0049fa89  ffd7                 call edi
// 0049fa8b  56                   push esi
// 0049fa8c  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0049fa90  8d4c2438             lea ecx, [esp + 0x38]
// 0049fa94  51                   push ecx
// 0049fa95  8d4c2410             lea ecx, [esp + 0x10]
// 0049fa99  e89277f7ff           call 0x417230
// 0049fa9e  3bc6                 cmp eax, esi
// 0049faa0  7408                 je 0x49faaa
// 0049faa2  8b16                 mov edx, dword ptr [esi]
// 0049faa4  8b08                 mov ecx, dword ptr [eax]
// 0049faa6  8910                 mov dword ptr [eax], edx
// 0049faa8  890e                 mov dword ptr [esi], ecx
// 0049faaa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049faae  85c9                 test ecx, ecx
// 0049fab0  7408                 je 0x49faba
// 0049fab2  8b01                 mov eax, dword ptr [ecx]
// 0049fab4  8b10                 mov edx, dword ptr [eax]
// 0049fab6  6a01                 push 1
// 0049fab8  ffd2                 call edx
// 0049faba  8b442420             mov eax, dword ptr [esp + 0x20]
// 0049fabe  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 0049fac2  c1f802               sar eax, 2
// 0049fac5  83f801               cmp eax, 1
// 0049fac8  7702                 ja 0x49facc
// 0049faca  ffd7                 call edi
// 0049facc  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0049fad0  6a08                 push 8
// 0049fad2  83c604               add esi, 4
// 0049fad5  e8460e2000           call 0x6a0920
// 0049fada  83c404               add esp, 4
// 0049fadd  85c0                 test eax, eax
// 0049fadf  740f                 je 0x49faf0
// 0049fae1  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0049fae5  c700cc068100         mov dword ptr [eax], 0x8106cc
// 0049faeb  894804               mov dword ptr [eax + 4], ecx
// 0049faee  eb02                 jmp 0x49faf2
// 0049faf0  33c0                 xor eax, eax
// 0049faf2  8d542454             lea edx, [esp + 0x54]
// 0049faf6  8bc8                 mov ecx, eax
// 0049faf8  3bd6                 cmp edx, esi
// 0049fafa  7404                 je 0x49fb00
// 0049fafc  8b0e                 mov ecx, dword ptr [esi]
// 0049fafe  8906                 mov dword ptr [esi], eax
// 0049fb00  85c9                 test ecx, ecx
// 0049fb02  7408                 je 0x49fb0c
// 0049fb04  8b01                 mov eax, dword ptr [ecx]
// 0049fb06  8b10                 mov edx, dword ptr [eax]
// 0049fb08  6a01                 push 1
// 0049fb0a  ffd2                 call edx
// 0049fb0c  8b442420             mov eax, dword ptr [esp + 0x20]
// 0049fb10  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 0049fb14  c1f802               sar eax, 2
// 0049fb17  83f802               cmp eax, 2
// 0049fb1a  7702                 ja 0x49fb1e
// 0049fb1c  ffd7                 call edi
// 0049fb1e  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0049fb22  8d4c2458             lea ecx, [esp + 0x58]
// 0049fb26  51                   push ecx
// 0049fb27  8d4c2458             lea ecx, [esp + 0x58]
// 0049fb2b  83c608               add esi, 8
// 0049fb2e  e8fd76f7ff           call 0x417230
// 0049fb33  3bc6                 cmp eax, esi
// 0049fb35  7408                 je 0x49fb3f
// 0049fb37  8b16                 mov edx, dword ptr [esi]
// 0049fb39  8b08                 mov ecx, dword ptr [eax]
// 0049fb3b  8910                 mov dword ptr [eax], edx
// 0049fb3d  890e                 mov dword ptr [esi], ecx
// 0049fb3f  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0049fb43  5e                   pop esi
// 0049fb44  85c9                 test ecx, ecx
// 0049fb46  7408                 je 0x49fb50
// 0049fb48  8b01                 mov eax, dword ptr [ecx]
// 0049fb4a  8b10                 mov edx, dword ptr [eax]
// 0049fb4c  6a01                 push 1
// 0049fb4e  ffd2                 call edx
// 0049fb50  8b4d00               mov ecx, dword ptr [ebp]
// 0049fb53  8b01                 mov eax, dword ptr [ecx]
// 0049fb55  8b4004               mov eax, dword ptr [eax + 4]
// 0049fb58  8d54240c             lea edx, [esp + 0xc]
// 0049fb5c  52                   push edx
// 0049fb5d  ffd0                 call eax
// 0049fb5f  8d4c240c             lea ecx, [esp + 0xc]
// 0049fb63  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0049fb68  e8b3b3f7ff           call 0x41af20
// 0049fb6d  8d4c2434             lea ecx, [esp + 0x34]
// 0049fb71  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0049fb76  ff1568248000         call dword ptr [0x802468]
// 0049fb7c  8d4c2454             lea ecx, [esp + 0x54]
// 0049fb80  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0049fb88  ff1568248000         call dword ptr [0x802468]
// 0049fb8e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0049fb92  5f                   pop edi
// 0049fb93  5d                   pop ebp
// 0049fb94  64890d00000000       mov dword ptr fs:[0], ecx
// 0049fb9b  83c428               add esp, 0x28
// 0049fb9e  c23c00               ret 0x3c

extern "C" void (__cdecl *invalid_parameter_noinfo)();
void * __cdecl operator new(unsigned int);

struct String;
extern "C" void (__thiscall *destroy_string)(String *);

struct String {
    char data[28];
    ~String();
};

inline String::~String()
{
    destroy_string(this);
}

struct Holder {
    virtual ~Holder();
};

struct IntHolder : Holder {
    int value;
    IntHolder(int);
};

struct Owner {
    Holder *pointer;
    Owner(const String &);
    Owner(Holder *);
    ~Owner();
    void swap(Owner &);
};

struct Arguments {
    char prefix[12];
    Owner *first;
    Owner *last;
    Owner *limit;

    Arguments(unsigned int);
    ~Arguments();
};

struct Receiver {
    virtual ~Receiver();
    virtual void invoke(const Arguments &);
};

struct S {
    virtual ~S();
    virtual void invoke(const Arguments &);
    void f(String, int, String);
};

inline IntHolder::IntHolder(int n) : value(n)
{
}

inline Owner::Owner(Holder *p) : pointer(p)
{
}

inline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

inline void Owner::swap(Owner &other)
{
    if (this != &other) {
        Holder *p = pointer;
        pointer = other.pointer;
        other.pointer = p;
    }
}

void S::f(String a, int b, String c)
{
    Arguments arguments(3);
    void (__cdecl *check)() = invalid_parameter_noinfo;
    {
        if (static_cast<unsigned int>(arguments.last - arguments.first) <= 0)
            check();
        Owner &destination = arguments.first[0];
        Owner(a).swap(destination);
    }
    {
        if (static_cast<unsigned int>(arguments.last - arguments.first) <= 1)
            check();
        Owner &destination = arguments.first[1];
        Owner(new IntHolder(b)).swap(destination);
    }
    {
        if (static_cast<unsigned int>(arguments.last - arguments.first) <= 2)
            check();
        Owner &destination = arguments.first[2];
        Owner(c).swap(destination);
    }
    invoke(arguments);
}
