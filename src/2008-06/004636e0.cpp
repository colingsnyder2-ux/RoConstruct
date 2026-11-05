// from server: 100% by EspClaude
// from server: 84% by colin
// roc 2008-06 004636e0  unit: Scintilla::CScintillaView  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004636e0
//
// 004636e0  6aff                 push -1
// 004636e2  6812327c00           push 0x7c3212
// 004636e7  64a100000000         mov eax, dword ptr fs:[0]
// 004636ed  50                   push eax
// 004636ee  64892500000000       mov dword ptr fs:[0], esp
// 004636f5  83ec2c               sub esp, 0x2c
// 004636f8  53                   push ebx
// 004636f9  55                   push ebp
// 004636fa  56                   push esi
// 004636fb  8bf1                 mov esi, ecx
// 004636fd  57                   push edi
// 004636fe  8d4c2410             lea ecx, [esp + 0x10]
// 00463702  ff15043f8000         call dword ptr [0x803f04]
// 00463708  33db                 xor ebx, ebx
// 0046370a  53                   push ebx
// 0046370b  895c2448             mov dword ptr [esp + 0x48], ebx
// 0046370f  ff1508288000         call dword ptr [0x802808]
// 00463715  d9ee                 fldz 
// 00463717  8944241c             mov dword ptr [esp + 0x1c], eax
// 0046371b  dd5c2424             fstp qword ptr [esp + 0x24]
// 0046371f  83c404               add esp, 4
// 00463722  8d442418             lea eax, [esp + 0x18]
// 00463726  50                   push eax
// 00463727  8d4c2424             lea ecx, [esp + 0x24]
// 0046372b  89542420             mov dword ptr [esp + 0x20], edx
// 0046372f  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00463733  e898f9ffff           call 0x4630d0
// 00463738  6800040000           push 0x400
// 0046373d  53                   push ebx
// 0046373e  8d4c241c             lea ecx, [esp + 0x1c]
// 00463742  51                   push ecx
// 00463743  8d4c242c             lea ecx, [esp + 0x2c]
// 00463747  e824e5ffff           call 0x461c70
// 0046374c  8b7654               mov esi, dword ptr [esi + 0x54]
// 0046374f  8bc8                 mov ecx, eax
// 00463751  c644244401           mov byte ptr [esp + 0x44], 1
// 00463756  ff15e03e8000         call dword ptr [0x803ee0]
// 0046375c  50                   push eax
// 0046375d  8d4e20               lea ecx, [esi + 0x20]
// 00463760  ff15e03e8000         call dword ptr [0x803ee0]
// 00463766  50                   push eax
// 00463767  68c5000000           push 0xc5
// 0046376c  8d54241c             lea edx, [esp + 0x1c]
// 00463770  52                   push edx
// 00463771  e8fcdc2300           call 0x6a1472
// 00463776  8d4c2414             lea ecx, [esp + 0x14]
// 0046377a  885c2444             mov byte ptr [esp + 0x44], bl
// 0046377e  ff15143f8000         call dword ptr [0x803f14]
// 00463784  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 00463788  8b07                 mov eax, dword ptr [edi]
// 0046378a  8b5038               mov edx, dword ptr [eax + 0x38]
// 0046378d  53                   push ebx
// 0046378e  8bcf                 mov ecx, edi
// 00463790  ffd2                 call edx
// 00463792  53                   push ebx
// 00463793  8bcf                 mov ecx, edi
// 00463795  e896dc2300           call 0x6a1430
// 0046379a  89442414             mov dword ptr [esp + 0x14], eax
// 0046379e  8d442418             lea eax, [esp + 0x18]
// 004637a2  50                   push eax
// 004637a3  8d4c2414             lea ecx, [esp + 0x14]
// 004637a7  ff15e02f8000         call dword ptr [0x802fe0]
// 004637ad  50                   push eax
// 004637ae  8d4c2418             lea ecx, [esp + 0x18]
// 004637b2  ff15e03e8000         call dword ptr [0x803ee0]
// 004637b8  8b4f08               mov ecx, dword ptr [edi + 8]
// 004637bb  50                   push eax
// 004637bc  51                   push ecx
// 004637bd  ff1540218000         call dword ptr [0x802140]
// 004637c3  8b742454             mov esi, dword ptr [esp + 0x54]
// 004637c7  8b4618               mov eax, dword ptr [esi + 0x18]
// 004637ca  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004637ce  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 004637d1  8b5620               mov edx, dword ptr [esi + 0x20]
// 004637d4  03ed                 add ebp, ebp
// 004637d6  8944244c             mov dword ptr [esp + 0x4c], eax
// 004637da  8944242c             mov dword ptr [esp + 0x2c], eax
// 004637de  8d0429               lea eax, [ecx + ebp]
// 004637e1  89442438             mov dword ptr [esp + 0x38], eax
// 004637e5  b856555555           mov eax, 0x55555556
// 004637ea  89542434             mov dword ptr [esp + 0x34], edx
// 004637ee  f7ed                 imul ebp
// 004637f0  8bda                 mov ebx, edx
// 004637f2  894c2430             mov dword ptr [esp + 0x30], ecx
// 004637f6  c1eb1f               shr ebx, 0x1f
// 004637f9  03da                 add ebx, edx
// 004637fb  03d9                 add ebx, ecx
// 004637fd  6a00                 push 0
// 004637ff  8d4c2414             lea ecx, [esp + 0x14]
// 00463803  ff15e02f8000         call dword ptr [0x802fe0]
// 00463809  50                   push eax
// 0046380a  8d4c2418             lea ecx, [esp + 0x18]
// 0046380e  ff15e03e8000         call dword ptr [0x803ee0]
// 00463814  8b542454             mov edx, dword ptr [esp + 0x54]
// 00463818  50                   push eax
// 00463819  8b4704               mov eax, dword ptr [edi + 4]
// 0046381c  8d4c2438             lea ecx, [esp + 0x38]
// 00463820  51                   push ecx
// 00463821  6a00                 push 0
// 00463823  53                   push ebx
// 00463824  52                   push edx
// 00463825  50                   push eax
// 00463826  ff1544218000         call dword ptr [0x802144]
// 0046382c  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0046382f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00463832  8d5429fb             lea edx, [ecx + ebp - 5]
// 00463836  52                   push edx
// 00463837  50                   push eax
// 00463838  8d4c2420             lea ecx, [esp + 0x20]
// 0046383c  51                   push ecx
// 0046383d  8bcf                 mov ecx, edi
// 0046383f  e8e6db2300           call 0x6a142a
// 00463844  8b561c               mov edx, dword ptr [esi + 0x1c]
// 00463847  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0046384a  8d442afb             lea eax, [edx + ebp - 5]
// 0046384e  50                   push eax
// 0046384f  51                   push ecx
// 00463850  8bcf                 mov ecx, edi
// 00463852  e8cddb2300           call 0x6a1424
// 00463857  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046385b  52                   push edx
// 0046385c  8bcf                 mov ecx, edi
// 0046385e  e8cddb2300           call 0x6a1430
// 00463863  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00463866  03e8                 add ebp, eax
// 00463868  396e0c               cmp dword ptr [esi + 0xc], ebp
// 0046386b  7d03                 jge 0x463870
// 0046386d  896e0c               mov dword ptr [esi + 0xc], ebp
// 00463870  8d4c2410             lea ecx, [esp + 0x10]
// 00463874  ff15143f8000         call dword ptr [0x803f14]
// 0046387a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0046387e  5f                   pop edi
// 0046387f  5e                   pop esi
// 00463880  5d                   pop ebp
// 00463881  5b                   pop ebx
// 00463882  64890d00000000       mov dword ptr fs:[0], ecx
// 00463889  83c438               add esp, 0x38
// 0046388c  c20c00               ret 0xc

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
