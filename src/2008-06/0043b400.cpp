// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 0043b400  unit: G3D::VColor3::?$XItem  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043b400
//
// 0043b400  6aff                 push -1
// 0043b402  6866057c00           push 0x7c0566
// 0043b407  64a100000000         mov eax, dword ptr fs:[0]
// 0043b40d  50                   push eax
// 0043b40e  64892500000000       mov dword ptr fs:[0], esp
// 0043b415  51                   push ecx
// 0043b416  53                   push ebx
// 0043b417  56                   push esi
// 0043b418  57                   push edi
// 0043b419  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043b41d  8b4704               mov eax, dword ptr [edi + 4]
// 0043b420  8bf1                 mov esi, ecx
// 0043b422  6a00                 push 0
// 0043b424  8d4804               lea ecx, [eax + 4]
// 0043b427  89742410             mov dword ptr [esp + 0x10], esi
// 0043b42b  ff1564248000         call dword ptr [0x802464]
// 0043b431  51                   push ecx
// 0043b432  8bcc                 mov ecx, esp
// 0043b434  89642428             mov dword ptr [esp + 0x28], esp
// 0043b438  50                   push eax
// 0043b439  ff15103f8000         call dword ptr [0x803f10]
// 0043b43f  8bce                 mov ecx, esi
// 0043b441  e89ac6ffff           call 0x437ae0
// 0043b446  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043b44a  50                   push eax
// 0043b44b  8d9e18010000         lea ebx, [esi + 0x118]
// 0043b451  57                   push edi
// 0043b452  8bcb                 mov ecx, ebx
// 0043b454  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043b45c  e80fecffff           call 0x43a070
// 0043b461  b801000000           mov eax, 1
// 0043b466  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043b46c  c706c43d8100         mov dword ptr [esi], 0x813dc4
// 0043b472  c74620643d8100       mov dword ptr [esi + 0x20], 0x813d64
// 0043b479  c7035c3d8100         mov dword ptr [ebx], 0x813d5c
// 0043b47f  89be38010000         mov dword ptr [esi + 0x138], edi
// 0043b485  8b17                 mov edx, dword ptr [edi]
// 0043b487  88442418             mov byte ptr [esp + 0x18], al
// 0043b48b  8b4204               mov eax, dword ptr [edx + 4]
// 0043b48e  8bcf                 mov ecx, edi
// 0043b490  ffd0                 call eax
// 0043b492  0fb6c8               movzx ecx, al
// 0043b495  51                   push ecx
// 0043b496  8bce                 mov ecx, esi
// 0043b498  e8436c2d00           call 0x7120e0
// 0043b49d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b4a1  5f                   pop edi
// 0043b4a2  8bc6                 mov eax, esi
// 0043b4a4  5e                   pop esi
// 0043b4a5  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b4ac  5b                   pop ebx
// 0043b4ad  83c410               add esp, 0x10
// 0043b4b0  c20800               ret 8

struct __declspec(dllimport) String {
    char padding[4];
    const char* c_str() const;
};


struct Text {
    void* data;
    __declspec(dllimport) Text(const char*);
    Text(const Text&);
    ~Text();
};

struct Name {
    int id;
    String str;
};

struct Source;
inline const char* nameOf(Source* s);
struct Source {
    virtual ~Source();
    virtual bool value();
    Name* name;
};

inline const char* nameOf(Source* s) { Name* n = s->name; return n->str.c_str(); }

struct Primary {
    virtual ~Primary();
    char padding[0x1c];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0xd8];
    int flag;
    char tail[0x18];
};

struct CXTPPropertyGridItem : Primary, Secondary {
    CXTPPropertyGridItem(Text, int);
    virtual ~CXTPPropertyGridItem();
    void SetValue(int);
};

struct Extra {
    virtual ~Extra();
    char padding[0x1c];
    Extra(Source*, int);
};

struct S : CXTPPropertyGridItem, Extra {
    Source* source;
    S(Source*, int);
    virtual ~S();
};

S::S(Source* value, int argument)
    : CXTPPropertyGridItem(
          Text(nameOf(value)), 0),
      Extra(value, argument)
{
    flag = 1;
    source = value;
    SetValue(value->value());
}
