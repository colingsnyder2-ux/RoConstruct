// from server: 79% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006149c0  unit: RBX::RevoluteLink  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006149c0
//
// 006149c0  6aff                 push -1
// 006149c2  68168e7d00           push 0x7d8e16
// 006149c7  64a100000000         mov eax, dword ptr fs:[0]
// 006149cd  50                   push eax
// 006149ce  64892500000000       mov dword ptr fs:[0], esp
// 006149d5  83ec08               sub esp, 8
// 006149d8  53                   push ebx
// 006149d9  33db                 xor ebx, ebx
// 006149db  83c8ff               or eax, 0xffffffff
// 006149de  56                   push esi
// 006149df  8bf1                 mov esi, ecx
// 006149e1  8906                 mov dword ptr [esi], eax
// 006149e3  894604               mov dword ptr [esi + 4], eax
// 006149e6  895e08               mov dword ptr [esi + 8], ebx
// 006149e9  885e0c               mov byte ptr [esi + 0xc], bl
// 006149ec  895e10               mov dword ptr [esi + 0x10], ebx
// 006149ef  895e14               mov dword ptr [esi + 0x14], ebx
// 006149f2  894618               mov dword ptr [esi + 0x18], eax
// 006149f5  89742408             mov dword ptr [esp + 8], esi
// 006149f9  895e20               mov dword ptr [esi + 0x20], ebx
// 006149fc  895e24               mov dword ptr [esi + 0x24], ebx
// 006149ff  895e1c               mov dword ptr [esi + 0x1c], ebx
// 00614a02  8d4e38               lea ecx, [esi + 0x38]
// 00614a05  895c2418             mov dword ptr [esp + 0x18], ebx
// 00614a09  895e28               mov dword ptr [esi + 0x28], ebx
// 00614a0c  895e2c               mov dword ptr [esi + 0x2c], ebx
// 00614a0f  c6463001             mov byte ptr [esi + 0x30], 1
// 00614a13  895e34               mov dword ptr [esi + 0x34], ebx
// 00614a16  e8b538e6ff           call 0x4782d0
// 00614a1b  e800f4efff           call 0x513e20
// 00614a20  50                   push eax
// 00614a21  8d4e68               lea ecx, [esi + 0x68]
// 00614a24  e8f7e7efff           call 0x513220
// 00614a29  d9ee                 fldz 
// 00614a2b  a198a89500           mov eax, dword ptr [0x95a898]
// 00614a30  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 00614a36  40                   inc eax
// 00614a37  a398a89500           mov dword ptr [0x95a898], eax
// 00614a3c  3dffffff7f           cmp eax, 0x7fffffff
// 00614a41  750a                 jne 0x614a4d
// 00614a43  b801000000           mov eax, 1
// 00614a48  a398a89500           mov dword ptr [0x95a898], eax
// 00614a4d  57                   push edi
// 00614a4e  8dbe94000000         lea edi, [esi + 0x94]
// 00614a54  8bcf                 mov ecx, edi
// 00614a56  898690000000         mov dword ptr [esi + 0x90], eax
// 00614a5c  e86f38e6ff           call 0x4782d0
// 00614a61  8d4f30               lea ecx, [edi + 0x30]
// 00614a64  e807f7ffff           call 0x614170
// 00614a69  68b4000000           push 0xb4
// 00614a6e  897610               mov dword ptr [esi + 0x10], esi
// 00614a71  e8aabe0800           call 0x6a0920
// 00614a76  83c404               add esp, 4
// 00614a79  89442410             mov dword ptr [esp + 0x10], eax
// 00614a7d  c644241c01           mov byte ptr [esp + 0x1c], 1
// 00614a82  5f                   pop edi
// 00614a83  3bc3                 cmp eax, ebx
// 00614a85  741e                 je 0x614aa5
// 00614a87  56                   push esi
// 00614a88  8bc8                 mov ecx, eax
// 00614a8a  e851400400           call 0x658ae0
// 00614a8f  89462c               mov dword ptr [esi + 0x2c], eax
// 00614a92  8bc6                 mov eax, esi
// 00614a94  5e                   pop esi
// 00614a95  5b                   pop ebx
// 00614a96  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00614a9a  64890d00000000       mov dword ptr fs:[0], ecx
// 00614aa1  83c414               add esp, 0x14
// 00614aa4  c3                   ret 
// 00614aa5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00614aa9  895e2c               mov dword ptr [esi + 0x2c], ebx
// 00614aac  8bc6                 mov eax, esi
// 00614aae  5e                   pop esi
// 00614aaf  5b                   pop ebx
// 00614ab0  64890d00000000       mov dword ptr fs:[0], ecx
// 00614ab7  83c414               add esp, 0x14
// 00614aba  c3                   ret 

struct Matrix {
    float values[9];
    Matrix(const Matrix&);
};

extern const Matrix& __cdecl identity();

struct Frame {
    float values[12];
    Frame();
};

struct State {
    unsigned char data[1];
    State();
};

struct Storage {
    void* first;
    void* last;
    void* end;

    Storage();
    ~Storage();
};

inline Storage::Storage()
{
    last = 0;
    end = 0;
    first = 0;
}

struct FrameState {
    Frame frame;
    State state;
    FrameState();
};

inline FrameState::FrameState()
    : frame(), state()
{
}

extern int counter;

inline int nextIdentifier(float& value)
{
    int result = counter;
    value = 0.0f;
    ++result;
    counter = result;
    if (result == 0x7fffffff) {
        result = 1;
        counter = result;
    }
    return result;
}

struct S;

struct Object {
    unsigned char data[180];
    Object(S*);
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S {
    int first;
    int second;
    int third;
    bool flag;
    S* owner;
    void* pointer;
    int index;
    Storage storage;
    void* extra;
    Object* object;
    bool enabled;
    int reserved;
    Frame frame;
    Matrix matrix;
    float value;
    int identifier;
    FrameState frameState;

    S();
};

S::S()
    : first(-1),
      second(-1),
      third(0),
      flag(false),
      owner(0),
      pointer(0),
      index(-1),
      storage(),
      extra(0),
      object(0),
      enabled(true),
      reserved(0),
      frame(),
      matrix(identity()),
      identifier(nextIdentifier(value)),
      frameState()
{
    owner = this;
    object = new Object(this);
}
