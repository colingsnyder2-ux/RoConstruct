// from server: 100% by EspClaude
// from server: 57% by colin
// roc 2007-08 00453700  unit: RBX::VInstance::?$NonFactoryProduct  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00453700
//
// 00453700  6aff                 push -1
// 00453702  6834d97300           push 0x73d934
// 00453707  64a100000000         mov eax, dword ptr fs:[0]
// 0045370d  50                   push eax
// 0045370e  53                   push ebx
// 0045370f  56                   push esi
// 00453710  57                   push edi
// 00453711  a188518b00           mov eax, dword ptr [0x8b5188]
// 00453716  33c4                 xor eax, esp
// 00453718  50                   push eax
// 00453719  8d442410             lea eax, [esp + 0x10]
// 0045371d  64a300000000         mov dword ptr fs:[0], eax
// 00453723  8bf1                 mov esi, ecx
// 00453725  8b442420             mov eax, dword ptr [esp + 0x20]
// 00453729  50                   push eax
// 0045372a  e8f1ea1f00           call 0x652220
// 0045372f  83f8ff               cmp eax, -1
// 00453732  7517                 jne 0x45374b
// 00453734  0bc0                 or eax, eax
// 00453736  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045373a  64890d00000000       mov dword ptr fs:[0], ecx
// 00453741  59                   pop ecx
// 00453742  5f                   pop edi
// 00453743  5e                   pop esi
// 00453744  5b                   pop ebx
// 00453745  83c40c               add esp, 0xc
// 00453748  c20400               ret 4
// 0045374b  8b16                 mov edx, dword ptr [esi]
// 0045374d  8b828c010000         mov eax, dword ptr [edx + 0x18c]
// 00453753  8bce                 mov ecx, esi
// 00453755  ffd0                 call eax
// 00453757  8bf0                 mov esi, eax
// 00453759  33db                 xor ebx, ebx
// 0045375b  8bce                 mov ecx, esi
// 0045375d  899e60010000         mov dword ptr [esi + 0x160], ebx
// 00453763  e8d8462000           call 0x657e40
// 00453768  8b16                 mov edx, dword ptr [esi]
// 0045376a  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 00453770  8bce                 mov ecx, esi
// 00453772  ffd0                 call eax
// 00453774  8b8600020000         mov eax, dword ptr [esi + 0x200]
// 0045377a  899888000000         mov dword ptr [eax + 0x88], ebx
// 00453780  8b8600020000         mov eax, dword ptr [esi + 0x200]
// 00453786  89587c               mov dword ptr [eax + 0x7c], ebx
// 00453789  8b8e00020000         mov ecx, dword ptr [esi + 0x200]
// 0045378f  6a01                 push 1
// 00453791  e82ad02000           call 0x6607c0
// 00453796  68b4000000           push 0xb4
// 0045379b  e856c71d00           call 0x62fef6
// 004537a0  83c404               add esp, 4
// 004537a3  89442420             mov dword ptr [esp + 0x20], eax
// 004537a7  3bc3                 cmp eax, ebx
// 004537a9  895c2418             mov dword ptr [esp + 0x18], ebx
// 004537ad  741c                 je 0x4537cb
// 004537af  6a01                 push 1
// 004537b1  6a01                 push 1
// 004537b3  6aff                 push -1
// 004537b5  6a01                 push 1
// 004537b7  68c8000000           push 0xc8
// 004537bc  68d47e7800           push 0x787ed4
// 004537c1  53                   push ebx
// 004537c2  8bc8                 mov ecx, eax
// 004537c4  e887af2000           call 0x65e750
// 004537c9  eb02                 jmp 0x4537cd
// 004537cb  33c0                 xor eax, eax
// 004537cd  50                   push eax
// 004537ce  8bce                 mov ecx, esi
// 004537d0  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004537d8  e823272000           call 0x655f00
// 004537dd  8bf8                 mov edi, eax
// 004537df  6a01                 push 1
// 004537e1  8bcf                 mov ecx, edi
// 004537e3  e848b12000           call 0x65e930
// 004537e8  68b4000000           push 0xb4
// 004537ed  899fac000000         mov dword ptr [edi + 0xac], ebx
// 004537f3  e8fec61d00           call 0x62fef6
// 004537f8  83c404               add esp, 4
// 004537fb  89442420             mov dword ptr [esp + 0x20], eax
// 004537ff  3bc3                 cmp eax, ebx
// 00453801  c744241801000000     mov dword ptr [esp + 0x18], 1
// 00453809  741d                 je 0x453828
// 0045380b  6a01                 push 1
// 0045380d  6a01                 push 1
// 0045380f  6aff                 push -1
// 00453811  6a01                 push 1
// 00453813  68c8000000           push 0xc8
// 00453818  68c41e7900           push 0x791ec4
// 0045381d  6a01                 push 1
// 0045381f  8bc8                 mov ecx, eax
// 00453821  e82aaf2000           call 0x65e750
// 00453826  eb02                 jmp 0x45382a
// 00453828  33c0                 xor eax, eax
// 0045382a  50                   push eax
// 0045382b  8bce                 mov ecx, esi
// 0045382d  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00453835  e8c6262000           call 0x655f00
// 0045383a  8998ac000000         mov dword ptr [eax + 0xac], ebx
// 00453840  33c0                 xor eax, eax
// 00453842  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00453846  64890d00000000       mov dword ptr fs:[0], ecx
// 0045384d  59                   pop ecx
// 0045384e  5f                   pop edi
// 0045384f  5e                   pop esi
// 00453850  5b                   pop ebx
// 00453851  83c40c               add esp, 0xc
// 00453854  c20400               ret 4

struct tagCREATESTRUCTA;

struct ReportHeader {
    char pad0[0x7c];
    int field7c;
    char pad80[0x88 - 0x80];
    int field88;
    void enable(int value);
};

struct ReportColumn {
    ReportColumn(int index, const char* caption, int width, int autoSize, int iconId, int sortable, int visible);
    void setEditable(int value);
    char pad0[0xac];
    int fieldac;
    char padb0[0xb4 - 0xb0];
};

struct ReportControl {
    virtual void v0();
    char pad4[0x160 - 4];
    int field160;
    char pad164[0x200 - 0x164];
    ReportHeader* header;
    void reset();
    ReportHeader* getHeader() const { return header; }
    ReportColumn* addColumn(ReportColumn* column);
};

struct ReportCtrlSlots {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4c();
    virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5c();
    virtual void s60(); virtual void s64(); virtual void s68(); virtual void s6c();
    virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7c();
    virtual void s80(); virtual void s84(); virtual void s88(); virtual void s8c();
    virtual void s90(); virtual void s94(); virtual void s98(); virtual void s9c();
    virtual void sa0(); virtual void sa4(); virtual void sa8(); virtual void sac();
    virtual void sb0(); virtual void sb4(); virtual void sb8(); virtual void sbc();
    virtual void sc0(); virtual void sc4(); virtual void sc8(); virtual void scc();
    virtual void sd0(); virtual void sd4(); virtual void sd8(); virtual void sdc();
    virtual void se0(); virtual void se4(); virtual void se8(); virtual void sec();
    virtual void sf0(); virtual void sf4(); virtual void sf8(); virtual void sfc();
    virtual void s100(); virtual void s104(); virtual void s108(); virtual void s10c();
    virtual void s110(); virtual void s114(); virtual void s118(); virtual void s11c();
    virtual void s120(); virtual void s124(); virtual void s128(); virtual void s12c();
    virtual void s130(); virtual void s134(); virtual void s138(); virtual void s13c();
    virtual void s140(); virtual void s144(); virtual void s148(); virtual void s14c();
    virtual void s150();
    virtual void populate();
};

struct ReportViewBase {
    virtual void v0();
    int OnCreate(tagCREATESTRUCTA* cs);
};

struct PropertiesView : ReportViewBase {
    int OnCreate(tagCREATESTRUCTA* cs);
};

struct ViewSlots {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4c();
    virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5c();
    virtual void s60(); virtual void s64(); virtual void s68(); virtual void s6c();
    virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7c();
    virtual void s80(); virtual void s84(); virtual void s88(); virtual void s8c();
    virtual void s90(); virtual void s94(); virtual void s98(); virtual void s9c();
    virtual void sa0(); virtual void sa4(); virtual void sa8(); virtual void sac();
    virtual void sb0(); virtual void sb4(); virtual void sb8(); virtual void sbc();
    virtual void sc0(); virtual void sc4(); virtual void sc8(); virtual void scc();
    virtual void sd0(); virtual void sd4(); virtual void sd8(); virtual void sdc();
    virtual void se0(); virtual void se4(); virtual void se8(); virtual void sec();
    virtual void sf0(); virtual void sf4(); virtual void sf8(); virtual void sfc();
    virtual void s100(); virtual void s104(); virtual void s108(); virtual void s10c();
    virtual void s110(); virtual void s114(); virtual void s118(); virtual void s11c();
    virtual void s120(); virtual void s124(); virtual void s128(); virtual void s12c();
    virtual void s130(); virtual void s134(); virtual void s138(); virtual void s13c();
    virtual void s140(); virtual void s144(); virtual void s148(); virtual void s14c();
    virtual void s150(); virtual void s154(); virtual void s158(); virtual void s15c();
    virtual void s160(); virtual void s164(); virtual void s168(); virtual void s16c();
    virtual void s170(); virtual void s174(); virtual void s178(); virtual void s17c();
    virtual void s180(); virtual void s184(); virtual void s188();
    virtual ReportControl* getReportCtrl();
};

int PropertiesView::OnCreate(tagCREATESTRUCTA* cs)
{
    if (ReportViewBase::OnCreate(cs) == -1)
        return -1;
    ReportControl* report = ((ViewSlots*)this)->getReportCtrl();
    report->field160 = 0;
    report->reset();
    ((ReportCtrlSlots*)report)->populate();
    report->getHeader()->field88 = 0;
    report->getHeader()->field7c = 0;
    report->getHeader()->enable(1);
    ReportColumn* column = report->addColumn(new ReportColumn(0, "Name", 200, 1, -1, 1, 1));
    column->setEditable(1);
    column->fieldac = 0;
    column = report->addColumn(new ReportColumn(1, "Value", 200, 1, -1, 1, 1));
    column->fieldac = 0;
    return 0;
}
