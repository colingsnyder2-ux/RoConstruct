// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00462d40  unit: CInstanceExplorer  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00462d40
//
// 00462d40  6aff                 push -1
// 00462d42  68fad87300           push 0x73d8fa
// 00462d47  64a100000000         mov eax, dword ptr fs:[0]
// 00462d4d  50                   push eax
// DECLARE_DYNCREATE-style CreateObject analog: new of 0x310 bytes (push 0x310), base ctor
// called thiscall (0x41e690), then the derived vtables stored at +0, +0x2cc and +0x2e8
// (three polymorphic subobjects, offsets from the target stores).

class CPart0 { public: virtual ~CPart0(); char pad_[0x2cc - 4]; };
class CPart1 { public: virtual ~CPart1(); char pad_[0x2e8 - 0x2cc - 4]; };
class CPart2 { public: virtual ~CPart2(); char pad_[0x310 - 0x2e8 - 4]; };

class CExplorerBase : public CPart0, public CPart1, public CPart2
{
public:
    CExplorerBase();
    virtual ~CExplorerBase();
};

class CInstanceExplorer : public CExplorerBase
{
public:
    CInstanceExplorer() {}
    virtual ~CInstanceExplorer() {}
    static CPart0* __stdcall CreateObject();
};

CPart0* __stdcall CInstanceExplorer::CreateObject()
{
    return new CInstanceExplorer;
}
