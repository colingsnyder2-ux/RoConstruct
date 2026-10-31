// from server: 100% by EspClaude
// roc 2009-06 00438160  unit: Vector3ComponentItem  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00438160
//
// 00438160  6aff                 push -1
// 00438162  6822f98400           push 0x84f922
// 00438167  64a100000000         mov eax, dword ptr fs:[0]
// 0043816d  50                   push eax
// 0043816e  64892500000000       mov dword ptr fs:[0], esp
// 00438175  83ec2c               sub esp, 0x2c
// 00438178  53                   push ebx
// 00438179  56                   push esi
// 0043817a  8bf1                 mov esi, ecx
// 0043817c  d98634010000         fld dword ptr [esi + 0x134]
// 00438182  8d442408             lea eax, [esp + 8]
// 00438186  d95c240c             fstp dword ptr [esp + 0xc]
// 0043818a  50                   push eax
// 0043818b  d98638010000         fld dword ptr [esi + 0x138]
// 00438191  d95c2414             fstp dword ptr [esp + 0x14]
// 00438195  d9863c010000         fld dword ptr [esi + 0x13c]
// 0043819b  d95c2418             fstp dword ptr [esp + 0x18]
// 0043819f  e8ac94ffff           call 0x431650
// 004381a4  8bc8                 mov ecx, eax
// 004381a6  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 004381ae  ff15d0fc8900         call dword ptr [0x89fcd0]
// 004381b4  50                   push eax
// 004381b5  8d4c241c             lea ecx, [esp + 0x1c]
// 004381b9  ff15b4e48900         call dword ptr [0x89e4b4]
// 004381bf  8b8630010000         mov eax, dword ptr [esi + 0x130]
// 004381c5  8d44840c             lea eax, [esp + eax*4 + 0xc]
// 004381c9  50                   push eax
// 004381ca  8d4c241c             lea ecx, [esp + 0x1c]
// 004381ce  51                   push ecx
// 004381cf  c644244401           mov byte ptr [esp + 0x44], 1
// 004381d4  e807342100           call 0x64b5e0
// 004381d9  83c408               add esp, 8
// 004381dc  8d4c2418             lea ecx, [esp + 0x18]
// 004381e0  8ad8                 mov bl, al
// 004381e2  c644243c00           mov byte ptr [esp + 0x3c], 0
// 004381e7  ff15c4e48900         call dword ptr [0x89e4c4]
// 004381ed  8d4c2408             lea ecx, [esp + 8]
// 004381f1  ff1510fd8900         call dword ptr [0x89fd10]
// 004381f7  8b442444             mov eax, dword ptr [esp + 0x44]
// 004381fb  84db                 test bl, bl
// 004381fd  7413                 je 0x438212
// 004381ff  d944240c             fld dword ptr [esp + 0xc]
// 00438203  d918                 fstp dword ptr [eax]
// 00438205  d9442410             fld dword ptr [esp + 0x10]
// 00438209  d95804               fstp dword ptr [eax + 4]
// 0043820c  d9442414             fld dword ptr [esp + 0x14]
// 00438210  eb17                 jmp 0x438229
// 00438212  d98634010000         fld dword ptr [esi + 0x134]
// 00438218  d918                 fstp dword ptr [eax]
// 0043821a  d98638010000         fld dword ptr [esi + 0x138]
// 00438220  d95804               fstp dword ptr [eax + 4]
// 00438223  d9863c010000         fld dword ptr [esi + 0x13c]
// 00438229  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0043822d  d95808               fstp dword ptr [eax + 8]
// 00438230  5e                   pop esi
// 00438231  5b                   pop ebx
// 00438232  64890d00000000       mov dword ptr fs:[0], ecx
// 00438239  83c438               add esp, 0x38
// 0043823c  c20400               ret 4
// copied from an identical function in another client (function ?getValue@Vector3ComponentItem@ns_ROCX00000c@@QAE?AUVector@2@XZ)

namespace ns_ROCX00000c {
struct Text;
extern const char* (__thiscall* text_data)(const Text*);

struct Text {
    int value;
    const char* c_str() const;
    ~Text() throw();

    __declspec(dllimport) void __thiscall destroyImport() throw();
};

inline const char* Text::c_str() const
{
    return text_data(this);
}

inline Text::~Text() throw()
{
    destroyImport();
}

struct String;
extern void (__thiscall* string_construct)(String*, const char*);
extern void (__thiscall* string_destroy)(String*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

extern bool __cdecl parse_component(const String&, float*);

struct Vector {
    float x, y, z;
    Vector();
    Vector(float, float, float);
    float& operator[](int);
};

inline Vector::Vector()
{
}

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline float& Vector::operator[](int index)
{
    return (&x)[index];
}

struct Vector3ComponentItem {
    char padding[0x130];
    int component;
    Vector value;

    Text copy();
    Vector getValue();
};

Vector Vector3ComponentItem::getValue()
{
    Vector result;
    result.x = value.x;
    result.y = value.y;
    result.z = value.z;
    bool valid = parse_component(String(copy().c_str()),
                                 &result[component]);
    if (valid)
        return Vector(result.x, result.y, result.z);
    return Vector(value.x, value.y, value.z);
}
}
