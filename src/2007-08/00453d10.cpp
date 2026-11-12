// from server: 100% by EspClaude
// roc 2007-08 00453d10  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00453d10
//
// 00453d10  6aff                 push -1
// 00453d12  6892147400           push 0x741492
// 00453d17  64a100000000         mov eax, dword ptr fs:[0]
// 00453d1d  50                   push eax
// 00453d1e  83ec14               sub esp, 0x14
// 00453d21  56                   push esi
// 00453d22  a188518b00           mov eax, dword ptr [0x8b5188]
// 00453d27  33c4                 xor eax, esp
// 00453d29  50                   push eax
// 00453d2a  8d44241c             lea eax, [esp + 0x1c]
// 00453d2e  64a300000000         mov dword ptr fs:[0], eax
// 00453d34  8bf1                 mov esi, ecx
// 00453d36  c744240800000000     mov dword ptr [esp + 8], 0
// 00453d3e  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00453d41  83ec08               sub esp, 8
// 00453d44  8bcc                 mov ecx, esp
// 00453d46  8901                 mov dword ptr [ecx], eax
// 00453d48  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 00453d4e  85c0                 test eax, eax
// 00453d50  89642414             mov dword ptr [esp + 0x14], esp
// 00453d54  894104               mov dword ptr [ecx + 4], eax
// 00453d57  740c                 je 0x453d65
// 00453d59  83c004               add eax, 4
// 00453d5c  b901000000           mov ecx, 1
// 00453d61  f00fc108             lock xadd dword ptr [eax], ecx
// 00453d65  8d4c2418             lea ecx, [esp + 0x18]
// 00453d69  e8e297fbff           call 0x40d550
// 00453d6e  8bb684000000         mov esi, dword ptr [esi + 0x84]
// 00453d74  8b16                 mov edx, dword ptr [esi]
// 00453d76  8b4244               mov eax, dword ptr [edx + 0x44]
// 00453d79  8bce                 mov ecx, esi
// 00453d7b  c744242401000000     mov dword ptr [esp + 0x24], 1
// 00453d83  ffd0                 call eax
// 00453d85  8d8ef0000000         lea ecx, [esi + 0xf0]
// 00453d8b  ff15a8e67700         call dword ptr [0x77e6a8]
// 00453d91  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00453d95  50                   push eax
// 00453d96  8bce                 mov ecx, esi
// 00453d98  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00453d9e  8d4c2410             lea ecx, [esp + 0x10]
// 00453da2  c744240801000000     mov dword ptr [esp + 8], 1
// 00453daa  c644242400           mov byte ptr [esp + 0x24], 0
// 00453daf  e8ec571000           call 0x5595a0
// 00453db4  8bc6                 mov eax, esi
// 00453db6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00453dba  64890d00000000       mov dword ptr fs:[0], ecx
// 00453dc1  59                   pop ecx
// 00453dc2  5e                   pop esi
// 00453dc3  83c420               add esp, 0x20
// 00453dc6  c20800               ret 8

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control {
    virtual void dispose();
    volatile long strong;
    volatile long weak;
};

struct DataModel;

struct SharedDataModel {
    DataModel* object;
    Control* control;
    SharedDataModel(const SharedDataModel& other) : object(other.object), control(other.control)
    {
        if (control)
            _InterlockedIncrement(&control->strong);
    }
    ~SharedDataModel();
};

struct Lock {
    void* first;
    void* second;
    void* third;
    Lock(SharedDataModel dataModel);
    ~Lock();
};

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        const T* c_str() const;
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Item {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40();
    virtual void update();
    char pad[0xf0 - 4];
    std::string value;
};

class __declspec(dllimport) CString {
    char* data;
public:
    CString(const char*);
    ~CString();
};

struct CValueItem {
    char pad[0x7c];
    SharedDataModel dataModel;
    Item* item;

    CString GetText(int column);
};

CString CValueItem::GetText(int column)
{
    Lock lock(dataModel);
    Item* current = item;
    current->update();
    return CString(current->value.c_str());
}
