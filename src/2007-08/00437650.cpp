// from server: 100% by EspClaude
// from server: 53% by colin
// roc 2007-08 00437650  unit: RBX::VStandardOut::?$MarshaledListener  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437650
//
// 00437650  83ec0c               sub esp, 0xc
// 00437653  53                   push ebx
// 00437654  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00437658  56                   push esi
// 00437659  57                   push edi
// 0043765a  8bf9                 mov edi, ecx
// 0043765c  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043765f  83c02c               add eax, 0x2c
// 00437662  8d4c240c             lea ecx, [esp + 0xc]
// 00437666  8944240c             mov dword ptr [esp + 0xc], eax
// 0043766a  c644241000           mov byte ptr [esp + 0x10], 0
// 0043766f  e8fc61feff           call 0x41d870
// 00437674  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00437678  83ec28               sub esp, 0x28
// 0043767b  8bf4                 mov esi, esp
// 0043767d  8d54244c             lea edx, [esp + 0x4c]
// 00437681  8964243c             mov dword ptr [esp + 0x3c], esp
// 00437685  890e                 mov dword ptr [esi], ecx
// 00437687  52                   push edx
// 00437688  8d4e04               lea ecx, [esi + 4]
// 0043768b  ff159ce67700         call dword ptr [0x77e69c]
// 00437691  8b442468             mov eax, dword ptr [esp + 0x68]
// 00437695  894620               mov dword ptr [esi + 0x20], eax
// 00437698  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0043769c  894e24               mov dword ptr [esi + 0x24], ecx
// 0043769f  8b17                 mov edx, dword ptr [edi]
// 004376a1  8b420c               mov eax, dword ptr [edx + 0xc]
// 004376a4  53                   push ebx
// 004376a5  8bcf                 mov ecx, edi
// 004376a7  ffd0                 call eax
// 004376a9  807c241000           cmp byte ptr [esp + 0x10], 0
// 004376ae  740b                 je 0x4376bb
// 004376b0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004376b4  51                   push ecx
// 004376b5  ff15f8d27700         call dword ptr [0x77d2f8]
// 004376bb  8d4c2424             lea ecx, [esp + 0x24]
// 004376bf  ff15ace67700         call dword ptr [0x77e6ac]
// 004376c5  5f                   pop edi
// 004376c6  5e                   pop esi
// 004376c7  5b                   pop ebx
// 004376c8  83c40c               add esp, 0xc
// 004376cb  c22c00               ret 0x2c

#include <string>

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

namespace RBX {

// message passed by value: 0x28 bytes (ret 0x2c = 4 + 0x28)
struct StandardOutMessage {
    int type;               // +0
    std::string message;    // +4
    int time0;              // +0x20
    int time1;              // +0x24
};

struct Mutex { char cs[1]; };

struct scoped_lock {
    Mutex* m_mutex;
    bool m_locked;
    scoped_lock(Mutex& m) : m_mutex(&m), m_locked(false) { lock(); }
    ~scoped_lock() { if (m_locked) LeaveCriticalSection(m_mutex); }
    void lock();            // 0x41d870, thiscall
};

struct Owner { char pad[0x2c]; Mutex mutex; };   // mutex at +0x2c

class VStandardOut;

template<class Event>
class MarshaledListener {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void onEventMarshaled(VStandardOut* source, Event event);   // slot +0xc
    void onEvent(VStandardOut* source, Event event) throw();
    char pad[0x14];
    Owner* owner;           // +0x18
};

template<class Event>
void MarshaledListener<Event>::onEvent(VStandardOut* source, Event event) throw()
{
    scoped_lock lock(owner->mutex);
    onEventMarshaled(source, event);
}

template class MarshaledListener<StandardOutMessage>;
}
