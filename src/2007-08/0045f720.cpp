// from server: 100% by Yeetserama
// roc 2007-08 0045f720  unit: Scintilla::CScintillaView  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045f720
//
// 0045f720  6aff                 push -1
// 0045f722  6872277400           push 0x742772
// 0045f727  64a100000000         mov eax, dword ptr fs:[0]
// 0045f72d  50                   push eax
// 0045f72e  83ec2c               sub esp, 0x2c
// 0045f731  53                   push ebx
// 0045f732  55                   push ebp
// 0045f733  56                   push esi
// 0045f734  57                   push edi
// 0045f735  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045f73a  33c4                 xor eax, esp
// 0045f73c  50                   push eax
// 0045f73d  8d442440             lea eax, [esp + 0x40]
// 0045f741  64a300000000         mov dword ptr fs:[0], eax
// 0045f747  8bf1                 mov esi, ecx
// 0045f749  8d4c2414             lea ecx, [esp + 0x14]
// 0045f74d  ff15acdd7700         call dword ptr [0x77ddac]
// 0045f753  33db                 xor ebx, ebx
// 0045f755  53                   push ebx
// 0045f756  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0045f75a  ff1548e97700         call dword ptr [0x77e948]
// 0045f760  d9ee                 fldz 
// 0045f762  89442420             mov dword ptr [esp + 0x20], eax
// 0045f766  dd5c2428             fstp qword ptr [esp + 0x28]
// 0045f76a  83c404               add esp, 4
// 0045f76d  8d44241c             lea eax, [esp + 0x1c]
// 0045f771  50                   push eax
// 0045f772  8d4c2428             lea ecx, [esp + 0x28]
// 0045f776  89542424             mov dword ptr [esp + 0x24], edx
// 0045f77a  895c2430             mov dword ptr [esp + 0x30], ebx
// 0045f77e  e87df9ffff           call 0x45f100
// 0045f783  6800040000           push 0x400
// 0045f788  53                   push ebx
// 0045f789  8d4c2420             lea ecx, [esp + 0x20]
// 0045f78d  51                   push ecx
// 0045f78e  8d4c2430             lea ecx, [esp + 0x30]
// 0045f792  e899e4ffff           call 0x45dc30
// 0045f797  8b7654               mov esi, dword ptr [esi + 0x54]
// 0045f79a  8bc8                 mov ecx, eax
// 0045f79c  c644244801           mov byte ptr [esp + 0x48], 1
// 0045f7a1  ff1598dd7700         call dword ptr [0x77dd98]
// 0045f7a7  50                   push eax
// 0045f7a8  8d4e20               lea ecx, [esi + 0x20]
// 0045f7ab  ff1598dd7700         call dword ptr [0x77dd98]
// 0045f7b1  50                   push eax
// 0045f7b2  68c5000000           push 0xc5
// 0045f7b7  8d542420             lea edx, [esp + 0x20]
// 0045f7bb  52                   push edx
// 0045f7bc  e80f121d00           call 0x6309d0
// 0045f7c1  8d4c2418             lea ecx, [esp + 0x18]
// 0045f7c5  885c2448             mov byte ptr [esp + 0x48], bl
// 0045f7c9  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0045f7cf  8b7c2450             mov edi, dword ptr [esp + 0x50]
// 0045f7d3  8b07                 mov eax, dword ptr [edi]
// 0045f7d5  8b5038               mov edx, dword ptr [eax + 0x38]
// 0045f7d8  53                   push ebx
// 0045f7d9  8bcf                 mov ecx, edi
// 0045f7db  ffd2                 call edx
// 0045f7dd  53                   push ebx
// 0045f7de  8bcf                 mov ecx, edi
// 0045f7e0  e89d111d00           call 0x630982
// 0045f7e5  89442418             mov dword ptr [esp + 0x18], eax
// 0045f7e9  8d44241c             lea eax, [esp + 0x1c]
// 0045f7ed  50                   push eax
// 0045f7ee  8d4c2418             lea ecx, [esp + 0x18]
// 0045f7f2  ff15c8dc7700         call dword ptr [0x77dcc8]
// 0045f7f8  50                   push eax
// 0045f7f9  8d4c241c             lea ecx, [esp + 0x1c]
// 0045f7fd  ff1598dd7700         call dword ptr [0x77dd98]
// 0045f803  8b4f08               mov ecx, dword ptr [edi + 8]
// 0045f806  50                   push eax
// 0045f807  51                   push ecx
// 0045f808  ff15b8d07700         call dword ptr [0x77d0b8]
// 0045f80e  8b742458             mov esi, dword ptr [esp + 0x58]
// 0045f812  8b4618               mov eax, dword ptr [esi + 0x18]
// 0045f815  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0045f818  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0045f81c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0045f81f  03ed                 add ebp, ebp
// 0045f821  89442450             mov dword ptr [esp + 0x50], eax
// 0045f825  89442430             mov dword ptr [esp + 0x30], eax
// 0045f829  8d0429               lea eax, [ecx + ebp]
// 0045f82c  8944243c             mov dword ptr [esp + 0x3c], eax
// 0045f830  89542438             mov dword ptr [esp + 0x38], edx
// 0045f834  b856555555           mov eax, 0x55555556
// 0045f839  f7ed                 imul ebp
// 0045f83b  8bda                 mov ebx, edx
// 0045f83d  c1eb1f               shr ebx, 0x1f
// 0045f840  03da                 add ebx, edx
// 0045f842  894c2434             mov dword ptr [esp + 0x34], ecx
// 0045f846  03d9                 add ebx, ecx
// 0045f848  6a00                 push 0
// 0045f84a  8d4c2418             lea ecx, [esp + 0x18]
// 0045f84e  ff15c8dc7700         call dword ptr [0x77dcc8]
// 0045f854  50                   push eax
// 0045f855  8d4c241c             lea ecx, [esp + 0x1c]
// 0045f859  ff1598dd7700         call dword ptr [0x77dd98]
// 0045f85f  8b542458             mov edx, dword ptr [esp + 0x58]
// 0045f863  50                   push eax
// 0045f864  8b4704               mov eax, dword ptr [edi + 4]
// 0045f867  8d4c243c             lea ecx, [esp + 0x3c]
// 0045f86b  51                   push ecx
// 0045f86c  6a00                 push 0
// 0045f86e  53                   push ebx
// 0045f86f  52                   push edx
// 0045f870  50                   push eax
// 0045f871  ff15bcd07700         call dword ptr [0x77d0bc]
// 0045f877  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0045f87a  8b4618               mov eax, dword ptr [esi + 0x18]
// 0045f87d  8d5429fb             lea edx, [ecx + ebp - 5]
// 0045f881  52                   push edx
// 0045f882  50                   push eax
// 0045f883  8d4c2424             lea ecx, [esp + 0x24]
// 0045f887  51                   push ecx
// 0045f888  8bcf                 mov ecx, edi
// 0045f88a  e8ed101d00           call 0x63097c
// 0045f88f  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0045f892  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0045f895  8d442afb             lea eax, [edx + ebp - 5]
// 0045f899  50                   push eax
// 0045f89a  51                   push ecx
// 0045f89b  8bcf                 mov ecx, edi
// 0045f89d  e8d4101d00           call 0x630976
// 0045f8a2  8b542418             mov edx, dword ptr [esp + 0x18]
// 0045f8a6  52                   push edx
// 0045f8a7  8bcf                 mov ecx, edi
// 0045f8a9  e8d4101d00           call 0x630982
// 0045f8ae  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0045f8b1  03e8                 add ebp, eax
// 0045f8b3  396e0c               cmp dword ptr [esi + 0xc], ebp
// 0045f8b6  7d03                 jge 0x45f8bb
// 0045f8b8  896e0c               mov dword ptr [esi + 0xc], ebp
// 0045f8bb  8d4c2414             lea ecx, [esp + 0x14]
// 0045f8bf  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0045f8c5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0045f8c9  64890d00000000       mov dword ptr fs:[0], ecx
// 0045f8d0  59                   pop ecx
// 0045f8d1  5f                   pop edi
// 0045f8d2  5e                   pop esi
// 0045f8d3  5d                   pop ebp
// 0045f8d4  5b                   pop ebx
// 0045f8d5  83c438               add esp, 0x38
// 0045f8d8  c20c00               ret 0xc
// copied from an identical function in another client (function ?DrawHeader@View@ns_ROCX000017@@QAEXPAUDC@2@IPAUPrintInfo@2@@Z)

namespace ns_ROCX000017 {
struct Size { int cx, cy; };
struct Point { int x, y; };
struct Rect { int left, top, right, bottom; };

struct String;
extern void (__thiscall * const StringConstruct)(String*);
extern void (__thiscall * const StringDestroy)(String*);
extern int (__thiscall * const StringLength)(const String*);
extern const char* (__thiscall * const StringData)(const String*);

struct String {
    char* data;
    String();
    __declspec(dllimport) ~String() throw();
};

inline String::String() { StringConstruct(this); }
#pragma pack(push, 4)
struct Date {
    double value;
    int status;
    Date(const __int64&);
    void SetTime(const __int64&);
    String Format(unsigned long, unsigned long) const;
};
#pragma pack(pop)

inline Date::Date(const __int64& time) : value(0), status(0)
{
    SetTime(time);
}

struct Document {
    char reserved[32];
    String title;
};

struct PrintInfo {
    char reserved0[12];
    int bottom;
    char reserved1[8];
    Rect draw;
};

struct DC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned long SetTextColor(unsigned long);

    void* output;
    void* attribute;

    unsigned int SetTextAlign(unsigned int);
    Point MoveTo(int, int);
    int LineTo(int, int);
};

extern __int64 (__cdecl * const Time64)(__int64*);
extern int (__stdcall * const TextExtent)(void*, const char*, int, Size*);
extern int (__stdcall * const TextOut)(
    void*, int, int, unsigned int, const Rect*, const char*,
    unsigned int, const int*);

void __stdcall FormatString2(String&, unsigned int, const char*, const char*);

inline int extTextOut(DC* dc, int x, int y, unsigned int options, const Rect* rect, const String& str, const int* widths)
{
    return TextOut(dc->output, x, y, options, rect, StringData(&str), StringLength(&str), widths);
}
inline Date currentTime() { return Date(Time64(0)); }
inline Size textExtent(DC* dc, const String& str)
{
    Size size;
    TextExtent(dc->attribute, StringData(&str), StringLength(&str), &size);
    return size;
}

struct View {
    char reserved[84];
    Document* document;
    Document* GetDocument() const { return document; }
    void DrawHeader(DC*, unsigned int, PrintInfo*);
};

void View::DrawHeader(DC* dc, unsigned int unused, PrintInfo* info)
{
    String text;
    {
        FormatString2(text, 197,
                      StringData(&GetDocument()->title),
                      StringData(&currentTime().Format(0, 0x400)));
    }

    dc->SetTextColor(0);
    unsigned int oldAlignment = dc->SetTextAlign(0);

    Size extent = textExtent(dc, text);

    int height = extent.cy * 2;
    Rect rectangle;
    rectangle.left = info->draw.left;
    rectangle.top = info->draw.top;
    rectangle.right = info->draw.right;
    rectangle.bottom = info->draw.top + height;
    extTextOut(dc, info->draw.left, info->draw.top + height / 3, 0, &rectangle, text, 0);

    dc->MoveTo(info->draw.left, info->draw.top + height - 5);
    dc->LineTo(info->draw.right, info->draw.top + height - 5);
    dc->SetTextAlign(oldAlignment);

    if (info->bottom < info->draw.top + height)
        info->bottom = info->draw.top + height;
}
}
