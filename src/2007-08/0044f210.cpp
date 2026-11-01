// from server: 100% by Yeetserama
// roc 2007-08 0044f210  unit: CRobloxDoc  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044f210
//
// 0044f210  6aff                 push -1
// 0044f212  68a80a7400           push 0x740aa8
// 0044f217  64a100000000         mov eax, dword ptr fs:[0]
// 0044f21d  50                   push eax
// 0044f21e  83ec10               sub esp, 0x10
// 0044f221  53                   push ebx
// 0044f222  55                   push ebp
// 0044f223  56                   push esi
// 0044f224  57                   push edi
// 0044f225  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044f22a  33c4                 xor eax, esp
// 0044f22c  50                   push eax
// 0044f22d  8d442424             lea eax, [esp + 0x24]
// 0044f231  64a300000000         mov dword ptr fs:[0], eax
// 0044f237  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0044f23b  33ff                 xor edi, edi
// 0044f23d  57                   push edi
// 0044f23e  56                   push esi
// 0044f23f  8d4c241f             lea ecx, [esp + 0x1f]
// 0044f243  ff1514e67700         call dword ptr [0x77e614]
// 0044f249  8bc8                 mov ecx, eax
// 0044f24b  ff1518e67700         call dword ptr [0x77e618]
// 0044f251  8be8                 mov ebp, eax
// 0044f253  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0044f257  89742420             mov dword ptr [esp + 0x20], esi
// 0044f25b  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0044f25f  897c242c             mov dword ptr [esp + 0x2c], edi
// 0044f263  897c2418             mov dword ptr [esp + 0x18], edi
// 0044f267  8b442434             mov eax, dword ptr [esp + 0x34]
// 0044f26b  8b00                 mov eax, dword ptr [eax]
// 0044f26d  8b08                 mov ecx, dword ptr [eax]
// 0044f26f  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044f272  56                   push esi
// 0044f273  55                   push ebp
// 0044f274  03c8                 add ecx, eax
// 0044f276  ff1508e67700         call dword ptr [0x77e608]
// 0044f27c  8bc8                 mov ecx, eax
// 0044f27e  ff150ce67700         call dword ptr [0x77e60c]
// 0044f284  85c0                 test eax, eax
// 0044f286  7404                 je 0x44f28c
// 0044f288  8bf8                 mov edi, eax
// 0044f28a  eb03                 jmp 0x44f28f
// 0044f28c  83cfff               or edi, 0xffffffff
// 0044f28f  83ffff               cmp edi, -1
// 0044f292  0f94442438           sete byte ptr [esp + 0x38]
// 0044f297  83ffff               cmp edi, -1
// 0044f29a  7428                 je 0x44f2c4
// 0044f29c  33f6                 xor esi, esi
// 0044f29e  85ff                 test edi, edi
// 0044f2a0  7e1a                 jle 0x44f2bc
// 0044f2a2  8b03                 mov eax, dword ptr [ebx]
// 0044f2a4  8bd7                 mov edx, edi
// 0044f2a6  2bd6                 sub edx, esi
// 0044f2a8  52                   push edx
// 0044f2a9  8d0c2e               lea ecx, [esi + ebp]
// 0044f2ac  51                   push ecx
// 0044f2ad  8d4804               lea ecx, [eax + 4]
// 0044f2b0  ff1500e67700         call dword ptr [0x77e600]
// 0044f2b6  03f0                 add esi, eax
// 0044f2b8  3bf7                 cmp esi, edi
// 0044f2ba  7ce6                 jl 0x44f2a2
// 0044f2bc  017c2418             add dword ptr [esp + 0x18], edi
// 0044f2c0  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0044f2c4  807c243800           cmp byte ptr [esp + 0x38], 0
// 0044f2c9  749c                 je 0x44f267
// 0044f2cb  85ed                 test ebp, ebp
// 0044f2cd  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0044f2d5  7414                 je 0x44f2eb
// 0044f2d7  56                   push esi
// 0044f2d8  55                   push ebp
// 0044f2d9  8d4c2444             lea ecx, [esp + 0x44]
// 0044f2dd  ff1514e67700         call dword ptr [0x77e614]
// 0044f2e3  8bc8                 mov ecx, eax
// 0044f2e5  ff1510e67700         call dword ptr [0x77e610]
// 0044f2eb  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044f2ef  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044f2f3  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f2fa  59                   pop ecx
// 0044f2fb  5f                   pop edi
// 0044f2fc  5e                   pop esi
// 0044f2fd  5d                   pop ebp
// 0044f2fe  5b                   pop ebx
// 0044f2ff  83c41c               add esp, 0x1c
// 0044f302  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000006_00451210@ns_ROCX000006@@YAHPAPAUInput@1@PAPAUOutput@1@I@Z)

namespace ns_ROCX000006 {
// from server: 100% by colin
struct Allocator {
    char unused;
};

struct Buffer {
    char unused;
};

struct InputBase {
    char unused;
};

struct Input {
    int* table;
};

struct Output {
    int reserved;
    Buffer buffer;
};

extern Allocator* (__thiscall *prepare)(Allocator*, unsigned int, const void*);
extern char* (__thiscall *allocate)(Allocator*);
extern void (__thiscall *deallocate)(Allocator*);
extern Buffer* (__thiscall *rdbuf)(const InputBase*);
extern int (__thiscall *sgetn)(Buffer*, char*, int);
extern int (__thiscall *sputn)(Buffer*, const char*, int);

struct Temporary {
    char* data;
    unsigned int size;

    Temporary(unsigned int);
    ~Temporary();
};

Temporary::Temporary(unsigned int n)
{
    Allocator allocator;
    data = allocate(prepare(&allocator, n, 0));
    size = n;
}

Temporary::~Temporary()
{
    if (data) {
        Allocator allocator;
        deallocate(prepare(&allocator,
                           reinterpret_cast<unsigned int>(data),
                           reinterpret_cast<const void*>(size)));
    }
}

int fn_ROCX000006_00451210(Input** input, Output** output, unsigned int size)
{
    Temporary temporary(size);
    int total = 0;
    int count = 0;
    Output** destination = output;
    bool done;

    do {
        Input* stream = *input;
        int received = sgetn(
            rdbuf(reinterpret_cast<InputBase*>(
                reinterpret_cast<char*>(stream) + stream->table[1])),
            temporary.data, size);

        count = received ? received : -1;
        done = count == -1;

        if (count != -1) {
            int written = 0;
            while (written < count) {
                Output* currentDestination = *destination;
                written += sputn(&currentDestination->buffer,
                                 temporary.data + written,
                                 count - written);
            }
            total += count;
        }
    } while (!done);

    return total;
}
}
