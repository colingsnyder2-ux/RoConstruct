// from server: 77% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006087a0  unit: RBX::BlockBlockContact  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006087a0
//
// 006087a0  d9ee                 fldz 
// 006087a2  56                   push esi
// 006087a3  8bf1                 mov esi, ecx
// 006087a5  d85e54               fcomp dword ptr [esi + 0x54]
// 006087a8  dfe0                 fnstsw ax
// 006087aa  f6c401               test ah, 1
// 006087ad  7568                 jne 0x608817
// 006087af  8b4e04               mov ecx, dword ptr [esi + 4]
// 006087b2  8b01                 mov eax, dword ptr [ecx]
// 006087b4  8b5004               mov edx, dword ptr [eax + 4]
// 006087b7  ffd2                 call edx
// 006087b9  83f807               cmp eax, 7
// 006087bc  7569                 jne 0x608827
// 006087be  8b4638               mov eax, dword ptr [esi + 0x38]
// 006087c1  57                   push edi
// 006087c2  6a00                 push 0
// 006087c4  8d7e40               lea edi, [esi + 0x40]
// 006087c7  50                   push eax
// 006087c8  8bcf                 mov ecx, edi
// 006087ca  e85177e7ff           call 0x47ff20
// 006087cf  33c0                 xor eax, eax
// 006087d1  394638               cmp dword ptr [esi + 0x38], eax
// 006087d4  7e0c                 jle 0x6087e2
// 006087d6  8b0f                 mov ecx, dword ptr [edi]
// 006087d8  c6040800             mov byte ptr [eax + ecx], 0
// 006087dc  40                   inc eax
// 006087dd  3b4638               cmp eax, dword ptr [esi + 0x38]
// 006087e0  7cf4                 jl 0x6087d6
// 006087e2  807e5c00             cmp byte ptr [esi + 0x5c], 0
// 006087e6  5f                   pop edi
// 006087e7  8bce                 mov ecx, esi
// 006087e9  740d                 je 0x6087f8
// 006087eb  e890fdffff           call 0x608580
// 006087f0  8bce                 mov ecx, esi
// 006087f2  5e                   pop esi
// 006087f3  e908f6ffff           jmp 0x607e00
// 006087f8  8b5668               mov edx, dword ptr [esi + 0x68]
// 006087fb  8b4664               mov eax, dword ptr [esi + 0x64]
// 006087fe  83ea06               sub edx, 6
// 00608801  52                   push edx
// 00608802  83e806               sub eax, 6
// 00608805  50                   push eax
// 00608806  6a01                 push 1
// 00608808  6a00                 push 0
// 0060880a  e891f6ffff           call 0x607ea0
// 0060880f  8bce                 mov ecx, esi
// 00608811  5e                   pop esi
// 00608812  e9e9f5ffff           jmp 0x607e00
// 00608817  8b16                 mov edx, dword ptr [esi]
// 00608819  8b4214               mov eax, dword ptr [edx + 0x14]
// 0060881c  ffd0                 call eax
// 0060881e  83c8ff               or eax, 0xffffffff
// 00608821  894664               mov dword ptr [esi + 0x64], eax
// 00608824  894668               mov dword ptr [esi + 0x68], eax
// 00608827  5e                   pop esi
// 00608828  c3                   ret 

struct Object {
    virtual void slot0();
    virtual int kind();
};

struct Buffer {
    unsigned char* data;
    int size;
    int capacity;

    void resize(int count, unsigned char value);
};

struct Contact {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void reset();

    Object* object;
    unsigned char padding08[0x30];
    int count;
    unsigned char padding3c[4];
    Buffer buffer;
    unsigned char padding4c[8];
    float value;
    unsigned char padding58[4];
    bool flag;
    unsigned char padding5d[7];
    int first;
    int second;

    void prepare();
    void process(int, int, int, int);
    void finish();
    void update();
};

void Contact::update()
{
    if (value <= 0.0f) {
        if (object->kind() == 7) {
            buffer.resize(count, 0);
            for (int i = 0; i < count; ++i)
                buffer.data[i] = 0;

            if (flag)
                prepare();
            else
                process(0, 1, first - 6, second - 6);

            finish();
        }
    } else {
        reset();
        first = -1;
        second = -1;
    }
}
