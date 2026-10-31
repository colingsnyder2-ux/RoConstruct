// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00640560  unit: RBX::ArrowTool  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640560
//
// 00640560  6aff                 push -1
// 00640562  6823aa7d00           push 0x7daa23
// 00640567  64a100000000         mov eax, dword ptr fs:[0]
// 0064056d  50                   push eax
// 0064056e  64892500000000       mov dword ptr fs:[0], esp
// 00640575  51                   push ecx
// 00640576  8b442414             mov eax, dword ptr [esp + 0x14]
// 0064057a  53                   push ebx
// 0064057b  56                   push esi
// 0064057c  8bf1                 mov esi, ecx
// 0064057e  50                   push eax
// 0064057f  8974240c             mov dword ptr [esp + 0xc], esi
// 00640583  e86854fdff           call 0x6159f0
// 00640588  33db                 xor ebx, ebx
// 0064058a  885e1c               mov byte ptr [esi + 0x1c], bl
// 0064058d  c706aca58400         mov dword ptr [esi], 0x84a5ac
// 00640593  c7460494a58400       mov dword ptr [esi + 4], 0x84a594
// 0064059a  895c2414             mov dword ptr [esp + 0x14], ebx
// 0064059e  895e20               mov dword ptr [esi + 0x20], ebx
// 006405a1  6850388300           push 0x833850
// 006405a6  8d4e24               lea ecx, [esi + 0x24]
// 006405a9  c644241801           mov byte ptr [esp + 0x18], 1
// 006405ae  ff1558248000         call dword ptr [0x802458]
// 006405b4  33c9                 xor ecx, ecx
// 006405b6  885e40               mov byte ptr [esi + 0x40], bl
// 006405b9  66894e42             mov word ptr [esi + 0x42], cx
// 006405bd  33d2                 xor edx, edx
// 006405bf  8d4e48               lea ecx, [esi + 0x48]
// 006405c2  66895644             mov word ptr [esi + 0x44], dx
// 006405c6  e86504edff           call 0x510a30
// 006405cb  d9ee                 fldz 
// 006405cd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006405d1  d95668               fst dword ptr [esi + 0x68]
// 006405d4  d9566c               fst dword ptr [esi + 0x6c]
// 006405d7  8bc6                 mov eax, esi
// 006405d9  d95e70               fstp dword ptr [esi + 0x70]
// 006405dc  5e                   pop esi
// 006405dd  5b                   pop ebx
// 006405de  64890d00000000       mov dword ptr fs:[0], ecx
// 006405e5  83c410               add esp, 0x10
// 006405e8  c20400               ret 4

struct Primary {
    virtual void primary();
};

struct Secondary {
    virtual void secondary();
};

struct Base : Primary, Secondary {
    int fields[5];
    Base(int);
    ~Base();
};

struct Active {
    bool active;
    Active();
};

inline Active::Active() : active(false) {}

struct Regex {
    void* pointer;
    Regex();
    ~Regex();
};

inline Regex::Regex() : pointer(0) {}

struct String {
    char storage[28];
};

extern void (__thiscall* constructString)(String*, const char*);

struct Ray {
    int storage[8];
    void initialize();
};

struct ArrowTool : Base, Active {
    Regex regex;
    String cursor;
    volatile bool flag;
    volatile short first;
    volatile short second;
    Ray ray;
    float x;
    float y;
    float z;

    ArrowTool(int);
    virtual void primary();
    virtual void secondary();
};

ArrowTool::ArrowTool(int argument)
    : Base(argument), Active(), regex()
{
    constructString(&cursor, "ArrowCursor");
    flag = false;
    first = 0;
    second = 0;
    ray.initialize();
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
