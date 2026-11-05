// from server: 100% by Yeetserama
// roc 2010-06 0045aa00  unit: VCRobloxDoc::?$VerbBinder  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0045aa00
//
// 0045aa00  8b442408             mov eax, dword ptr [esp + 8]
// 0045aa04  56                   push esi
// 0045aa05  57                   push edi
// 0045aa06  8bf1                 mov esi, ecx
// 0045aa08  85c0                 test eax, eax
// 0045aa0a  741f                 je 0x45aa2b
// 0045aa0c  8b7804               mov edi, dword ptr [eax + 4]
// 0045aa0f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045aa13  8d4c240c             lea ecx, [esp + 0xc]
// 0045aa17  51                   push ecx
// 0045aa18  8d4e54               lea ecx, [esi + 0x54]
// 0045aa1b  89442410             mov dword ptr [esp + 0x10], eax
// 0045aa1f  e86cc2feff           call 0x446c90
// 0045aa24  8938                 mov dword ptr [eax], edi
// 0045aa26  5f                   pop edi
// 0045aa27  5e                   pop esi
// 0045aa28  c20800               ret 8
// 0045aa2b  e8c0991300           call 0x5943f0
// 0045aa30  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0045aa34  8bf8                 mov edi, eax
// 0045aa36  8d44240c             lea eax, [esp + 0xc]
// 0045aa3a  50                   push eax
// 0045aa3b  8d4e54               lea ecx, [esi + 0x54]
// 0045aa3e  89542410             mov dword ptr [esp + 0x10], edx
// 0045aa42  e849c2feff           call 0x446c90
// 0045aa47  8938                 mov dword ptr [eax], edi
// 0045aa49  5f                   pop edi
// 0045aa4a  5e                   pop esi
// 0045aa4b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_00451a10@@QAEXPAUKey@@PAX@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct Name;
struct KeyBase { int x; };
struct Key : KeyBase {};

Name const& __cdecl getLocalScope();

struct Map {
    char data[84];
    void*& lookup(KeyBase* const& key);
};

struct S_func_00451a10 {
    char pad[84];
    Map map;
    void f(Key* key, void* node);
};

void S_func_00451a10::f(Key* key, void* node)
{
    if (node) {
        void* value = *(void**)((char*)node + 4);
        map.lookup(key) = value;
    } else {
        void* value = (void*)&getLocalScope();
        map.lookup(key) = value;
    }
}