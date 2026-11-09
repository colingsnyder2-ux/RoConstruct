// from server: 37% by atomic.potato
struct CString {
    void* m_pData;
    CString();
    CString(const char*);
    ~CString();
};

struct CXTPPaintManager {
    char pad[0x38];
    int field_38;
    char pad2[0x08];
    int field_44;
    char pad3[0x08];
    int field_4c;
    char pad4[0x04];
    int field_50;
    char pad5[0x14];
    int field_68;
};

struct CXTPPropertyGridPaintThemes {
    char pad[0x34];
    int field_34;
    char pad2[0x08];
    int field_40;
    char pad3[0x08];
    int field_4c;
    char pad4[0x08];
    int field_58;
    char pad5[0x18];
    CXTPPaintManager* field_74;
    void Init();
};

extern "C" void* __stdcall sub_b247c8(const char*);

void* __fastcall sub_a66a30();
void __fastcall sub_a66330(void* self, void* arg);

void CXTPPropertyGridPaintThemes::Init()
{
    CString s1;
    CString s2;
    CString s3;
    CString s4;

    sub_b247c8("PropertyGrid");
    sub_a66330(sub_a66a30(), &s1);
    field_74->field_4c = (int)&s1;

    sub_b247c8("Highlight");
    sub_a66330(sub_a66a30(), &s2);
    field_74->field_68 = (int)&s2;

    sub_b247c8("HighlightText");
    sub_a66330(sub_a66a30(), &s3);
    field_58 = (int)&s3;

    sub_b247c8("CategoryText");
    sub_a66330(sub_a66a30(), &s4);
    field_4c = (int)&s4;

    field_34 = 0xffd1ad;
    field_40 = 0xcf9365;
    field_74->field_38 = 0xffe8d6;
    field_74->field_44 = 0;
    field_74->field_50 = 0xffe8d6;
    field_74->field_68 = 0x8b4215;
    field_58 = 0;
    field_4c = 0xe8c8b3;
}
