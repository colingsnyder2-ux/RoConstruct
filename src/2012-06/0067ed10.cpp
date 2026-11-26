// from server: 100% by Xemicl
// roc 2012-06 0067ed10  unit: RBX::VTaskSchedulerSettings::?$GlobalAdvancedSettingsItem  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067ed10
//
// 0067ed10  b801000000           mov eax, 1
// 0067ed15  8405c4a1e200         test byte ptr [0xe2a1c4], al
// 0067ed1b  751b                 jne 0x67ed38
// 0067ed1d  0905c4a1e200         or dword ptr [0xe2a1c4], eax
// 0067ed23  680057b100           push 0xb15700
// 0067ed28  c705c0a1e20000000000 mov dword ptr [0xe2a1c0], 0
// 0067ed32  e8be443000           call 0x9831f5
// 0067ed37  59                   pop ecx
// 0067ed38  c3                   ret 
// copied from an identical function in another client (function ?initInstance@@YAXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item { int* p; Item() : p(0) {} ~Item() {} };
static Item& instance() { static Item s; return s; }
void initInstance() { instance(); }