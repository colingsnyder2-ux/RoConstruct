// from server: 100% by EspClaude
// roc 2009-06 00450050  unit: VCRobloxDoc::?$VerbBinder  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00450050
//
// 00450050  8b442408             mov eax, dword ptr [esp + 8]
// 00450054  56                   push esi
// 00450055  57                   push edi
// 00450056  8bf1                 mov esi, ecx
// 00450058  85c0                 test eax, eax
// 0045005a  741f                 je 0x45007b
// 0045005c  8b7804               mov edi, dword ptr [eax + 4]
// 0045005f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00450063  8d4c240c             lea ecx, [esp + 0xc]
// 00450067  51                   push ecx
// 00450068  8d4e54               lea ecx, [esi + 0x54]
// 0045006b  89442410             mov dword ptr [esp + 0x10], eax
// 0045006f  e85c942400           call 0x6994d0
// 00450074  8938                 mov dword ptr [eax], edi
// 00450076  5f                   pop edi
// 00450077  5e                   pop esi
// 00450078  c20800               ret 8
// 0045007b  e8e0d81700           call 0x5cd960
// 00450080  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00450084  8bf8                 mov edi, eax
// 00450086  8d44240c             lea eax, [esp + 0xc]
// 0045008a  50                   push eax
// 0045008b  8d4e54               lea ecx, [esi + 0x54]
// 0045008e  89542410             mov dword ptr [esp + 0x10], edx
// 00450092  e839942400           call 0x6994d0
// 00450097  8938                 mov dword ptr [eax], edi
// 00450099  5f                   pop edi
// 0045009a  5e                   pop esi
// 0045009b  c20800               ret 8
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