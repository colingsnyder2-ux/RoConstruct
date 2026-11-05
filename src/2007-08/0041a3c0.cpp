// from server: 79% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0041c4b0  unit: VDHTMLWindow::?$BoundFuncDesc  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041c4b0
//
// 0041c4b0  6aff                 push -1
// 0041c4b2  6809097d00           push 0x7d0909
// 0041c4b7  64a100000000         mov eax, dword ptr fs:[0]
// 0041c4bd  50                   push eax
// 0041c4be  64892500000000       mov dword ptr fs:[0], esp
// 0041c4c5  51                   push ecx
// 0041c4c6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0041c4ca  56                   push esi
// 0041c4cb  8bf1                 mov esi, ecx
// 0041c4cd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0041c4d1  50                   push eax
// 0041c4d2  51                   push ecx
// 0041c4d3  8974240c             mov dword ptr [esp + 0xc], esi
// 0041c4d7  e8c4f3ffff           call 0x41b8a0
// 0041c4dc  50                   push eax
// 0041c4dd  8bce                 mov ecx, esi
// 0041c4df  e8ac921700           call 0x595790
// 0041c4e4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0041c4e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041c4ec  8d4e40               lea ecx, [esi + 0x40]
// 0041c4ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041c4f7  c70640ef8000         mov dword ptr [esi], 0x80ef40
// 0041c4fd  895638               mov dword ptr [esi + 0x38], edx
// 0041c500  89463c               mov dword ptr [esi + 0x3c], eax
// 0041c503  e8b8851700           call 0x594ac0
// 0041c508  8d4e48               lea ecx, [esi + 0x48]
// 0041c50b  c644241001           mov byte ptr [esp + 0x10], 1
// 0041c510  e8ab851700           call 0x594ac0
// 0041c515  8d4e50               lea ecx, [esi + 0x50]
// 0041c518  c644241002           mov byte ptr [esp + 0x10], 2
// 0041c51d  e89e851700           call 0x594ac0
// 0041c522  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0041c526  8b542428             mov edx, dword ptr [esp + 0x28]
// 0041c52a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0041c52e  51                   push ecx
// 0041c52f  52                   push edx
// 0041c530  50                   push eax
// 0041c531  8bce                 mov ecx, esi
// 0041c533  c644241c03           mov byte ptr [esp + 0x1c], 3
// 0041c538  e8d3a9ffff           call 0x416f10
// 0041c53d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041c541  8bc6                 mov eax, esi
// 0041c543  5e                   pop esi
// 0041c544  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c54b  83c410               add esp, 0x10
// 0041c54e  c21c00               ret 0x1c

extern "C" void* __stdcall getDescriptor(const char*, int);

struct Base {
    char data[0x34];

    Base(void*);
    virtual ~Base();
};

struct Value {
    unsigned long type;
    unsigned long data;

    Value();
    ~Value();
};

struct S : Base {
    unsigned long first;
    unsigned long second;
    Value value1;
    Value value2;
    Value value3;

    S(unsigned long, unsigned long, const char*, int, int, int, int);
    virtual ~S();
    void initialize(int, int, int);
};

S::S(unsigned long a, unsigned long b, const char* c,
     int d, int e, int f, int g)
    : Base(getDescriptor(c, g)),
      first(a),
      second(b),
      value1(),
      value2(),
      value3()
{
    initialize(d, e, f);
}
