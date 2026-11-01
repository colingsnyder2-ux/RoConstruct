// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 00640e20  unit: RBX::AxisMoveTool  size: 264 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640e20
//
// 00640e20  83ec34               sub esp, 0x34
// 00640e23  d9ee                 fldz 
// 00640e25  56                   push esi
// 00640e26  57                   push edi
// 00640e27  d9542408             fst dword ptr [esp + 8]
// 00640e2b  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00640e2f  d954240c             fst dword ptr [esp + 0xc]
// 00640e33  8bf1                 mov esi, ecx
// 00640e35  d95c2410             fstp dword ptr [esp + 0x10]
// 00640e39  8d442440             lea eax, [esp + 0x40]
// 00640e3d  50                   push eax
// 00640e3e  8d4c240c             lea ecx, [esp + 0xc]
// 00640e42  51                   push ecx
// 00640e43  57                   push edi
// 00640e44  8bce                 mov ecx, esi
// 00640e46  e805ffffff           call 0x640d50
// 00640e4b  84c0                 test al, al
// 00640e4d  0f84c5000000         je 0x640f18
// 00640e53  8b5708               mov edx, dword ptr [edi + 8]
// 00640e56  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00640e5a  895642               mov dword ptr [esi + 0x42], edx
// 00640e5d  b856555555           mov eax, 0x55555556
// 00640e62  f7e9                 imul ecx
// 00640e64  8bc2                 mov eax, edx
// 00640e66  c1e81f               shr eax, 0x1f
// 00640e69  03c2                 add eax, edx
// 00640e6b  8d0440               lea eax, [eax + eax*2]
// 00640e6e  2bc8                 sub ecx, eax
// 00640e70  b801000000           mov eax, 1
// 00640e75  894e64               mov dword ptr [esi + 0x64], ecx
// 00640e78  8405c4d59700         test byte ptr [0x97d5c4], al
// 00640e7e  7520                 jne 0x640ea0
// 00640e80  d9e8                 fld1 
// 00640e82  0905c4d59700         or dword ptr [0x97d5c4], eax
// 00640e88  d915b8d59700         fst dword ptr [0x97d5b8]
// 00640e8e  d905182a8300         fld dword ptr [0x832a18]
// 00640e94  d91dbcd59700         fstp dword ptr [0x97d5bc]
// 00640e9a  d91dc0d59700         fstp dword ptr [0x97d5c0]
// 00640ea0  68b8d59700           push 0x97d5b8
// 00640ea5  8d4c240c             lea ecx, [esp + 0xc]
// 00640ea9  51                   push ecx
// 00640eaa  8d54241c             lea edx, [esp + 0x1c]
// 00640eae  52                   push edx
// 00640eaf  e85cdff9ff           call 0x5dee10
// 00640eb4  d900                 fld dword ptr [eax]
// 00640eb6  d95e68               fstp dword ptr [esi + 0x68]
// 00640eb9  8d7e68               lea edi, [esi + 0x68]
// 00640ebc  d94004               fld dword ptr [eax + 4]
// 00640ebf  d95f04               fstp dword ptr [edi + 4]
// 00640ec2  d94008               fld dword ptr [eax + 8]
// 00640ec5  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00640ec9  50                   push eax
// 00640eca  d95f08               fstp dword ptr [edi + 8]
// 00640ecd  e89eb6faff           call 0x5ec570
// 00640ed2  50                   push eax
// 00640ed3  8d4c2434             lea ecx, [esp + 0x34]
// 00640ed7  57                   push edi
// 00640ed8  51                   push ecx
// 00640ed9  e85279edff           call 0x518830
// 00640ede  d94004               fld dword ptr [eax + 4]
// 00640ee1  d95e4c               fstp dword ptr [esi + 0x4c]
// 00640ee4  83c41c               add esp, 0x1c
// 00640ee7  d94008               fld dword ptr [eax + 8]
// 00640eea  8bce                 mov ecx, esi
// 00640eec  d95e50               fstp dword ptr [esi + 0x50]
// 00640eef  d9400c               fld dword ptr [eax + 0xc]
// 00640ef2  d95e54               fstp dword ptr [esi + 0x54]
// 00640ef5  d94010               fld dword ptr [eax + 0x10]
// 00640ef8  d95e58               fstp dword ptr [esi + 0x58]
// 00640efb  d94014               fld dword ptr [eax + 0x14]
// 00640efe  d95e5c               fstp dword ptr [esi + 0x5c]
// 00640f01  d94018               fld dword ptr [eax + 0x18]
// 00640f04  d95e60               fstp dword ptr [esi + 0x60]
// 00640f07  8b16                 mov edx, dword ptr [esi]
// 00640f09  8b4224               mov eax, dword ptr [edx + 0x24]
// 00640f0c  ffd0                 call eax
// 00640f0e  5f                   pop edi
// 00640f0f  8bc6                 mov eax, esi
// 00640f11  5e                   pop esi
// 00640f12  83c434               add esp, 0x34
// 00640f15  c20400               ret 4
// 00640f18  57                   push edi
// 00640f19  8bce                 mov ecx, esi
// 00640f1b  e86068fdff           call 0x617780
// 00640f20  5f                   pop edi
// 00640f21  5e                   pop esi
// 00640f22  83c434               add esp, 0x34
// 00640f25  c20400               ret 4

struct Vector3 {
    float x, y, z;
};

struct Result {
    virtual void slot0();
    float values[6];
};

struct Input {
    char padding[8];
    int value;
};

extern const float factorY;
extern Vector3* __cdecl multiply(Vector3*, const Vector3*, const Vector3*);
extern const Vector3* __cdecl axisVector(int);
extern Result* __cdecl makeResult(Result*, const Vector3*, const Vector3*);

struct Factor : Vector3 {
    Factor();
};

inline Factor::Factor()
{
    x = 1.0f;
    y = factorY;
    z = 1.0f;
}

#pragma pack(push, 1)
struct Tool {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void refresh();

    char padding[0x3e];
    int selected;
    char padding2[2];
    Result result;
    int axis;
    Vector3 position;

    bool pick(Input*, Vector3*, int*);
    Tool* fallback(Input*);
    Tool* update(Input*);
};
#pragma pack(pop)

Tool* Tool::update(Input* input)
{
    Vector3 point = { 0.0f, 0.0f, 0.0f };
    int& selectedRef = selected;
    int selectedAxis;

    if (pick(input, &point, &selectedAxis)) {
        selectedRef = input->value;
        axis = selectedAxis % 3;

        static Factor factor;

        Vector3 temporary;
        const Vector3* product = multiply(&temporary, &point, &factor);
        Vector3& destination = position;
        destination.x = product->x;
        destination.y = product->y;
        destination.z = product->z;

        union {
            int alignment;
            char storage[sizeof(Result)];
        } temporaryResult;

        result = *makeResult(
            reinterpret_cast<Result*>(temporaryResult.storage),
            &destination, axisVector(selectedAxis));

        refresh();
        return this;
    }

    return fallback(input);
}
