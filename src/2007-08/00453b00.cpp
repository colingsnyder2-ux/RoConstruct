// from server: 100% by EspClaude
// roc 2007-08 00453b00  unit: CRobloxReportView::CStatsItemRecord::CNameItem  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00453b00
//
// 00453b00  6aff                 push -1
// 00453b02  6892147400           push 0x741492
// 00453b07  64a100000000         mov eax, dword ptr fs:[0]
// 00453b0d  50                   push eax
// 00453b0e  83ec14               sub esp, 0x14
// 00453b11  56                   push esi
// 00453b12  a188518b00           mov eax, dword ptr [0x8b5188]
// 00453b17  33c4                 xor eax, esp
// 00453b19  50                   push eax
// 00453b1a  8d44241c             lea eax, [esp + 0x1c]
// 00453b1e  64a300000000         mov dword ptr fs:[0], eax
// 00453b24  8bf1                 mov esi, ecx
// 00453b26  c744240800000000     mov dword ptr [esp + 8], 0
// 00453b2e  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00453b31  83ec08               sub esp, 8
// 00453b34  8bcc                 mov ecx, esp
// 00453b36  8901                 mov dword ptr [ecx], eax
// 00453b38  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 00453b3e  85c0                 test eax, eax
// 00453b40  89642414             mov dword ptr [esp + 0x14], esp
// 00453b44  894104               mov dword ptr [ecx + 4], eax
// 00453b47  740c                 je 0x453b55
// 00453b49  83c004               add eax, 4
// 00453b4c  b901000000           mov ecx, 1
// 00453b51  f00fc108             lock xadd dword ptr [eax], ecx
// 00453b55  8d4c2418             lea ecx, [esp + 0x18]
// 00453b59  e8f299fbff           call 0x40d550
// 00453b5e  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 00453b64  81c1c8000000         add ecx, 0xc8
// 00453b6a  c744242401000000     mov dword ptr [esp + 0x24], 1
// 00453b72  ff15a8e67700         call dword ptr [0x77e6a8]
// 00453b78  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00453b7c  50                   push eax
// 00453b7d  8bce                 mov ecx, esi
// 00453b7f  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00453b85  8d4c2410             lea ecx, [esp + 0x10]
// 00453b89  c744240801000000     mov dword ptr [esp + 8], 1
// 00453b91  c644242400           mov byte ptr [esp + 0x24], 0
// 00453b96  e8055a1000           call 0x5595a0
// 00453b9b  8bc6                 mov eax, esi
// 00453b9d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00453ba1  64890d00000000       mov dword ptr fs:[0], ecx
// 00453ba8  59                   pop ecx
// 00453ba9  5e                   pop esi
// 00453baa  83c420               add esp, 0x20
// 00453bad  c20800               ret 8

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

struct Instance {
    char pad[0xc8];
    std::string name;
};

class __declspec(dllimport) CString {
    char* data;
public:
    CString(const char*);
    ~CString();
};

struct CNameItem {
    char pad[0x7c];
    SharedDataModel dataModel;
    Instance* instance;

    CString GetText(int column);
};

CString CNameItem::GetText(int column)
{
    Lock lock(dataModel);
    return CString(instance->name.c_str());
}
