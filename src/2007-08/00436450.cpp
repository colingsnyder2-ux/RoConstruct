// from server: 100% by Yeetserama
// roc 2007-08 00436450  unit: CDeclarationView  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00436450
//
// 00436450  56                   push esi
// 00436451  8b742408             mov esi, dword ptr [esp + 8]
// 00436455  833e00               cmp dword ptr [esi], 0
// 00436458  57                   push edi
// 00436459  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0043645d  7e0d                 jle 0x43646c
// 0043645f  6840cc7800           push 0x78cc40
// 00436464  8bcf                 mov ecx, edi
// 00436466  ff1560e67700         call dword ptr [0x77e660]
// 0043646c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00436470  8b00                 mov eax, dword ptr [eax]
// 00436472  8d4804               lea ecx, [eax + 4]
// 00436475  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043647b  50                   push eax
// 0043647c  8bcf                 mov ecx, edi
// 0043647e  ff1560e67700         call dword ptr [0x77e660]
// 00436484  830601               add dword ptr [esi], 1
// 00436487  5f                   pop edi
// 00436488  5e                   pop esi
// 00436489  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000016_00435510@ns_ROCX000016@@YAXPAHPAUString@1@PAPAUEntry@1@@Z)

namespace ns_ROCX000016 {
// from server: 100% by tester
struct String {};
extern String& (__thiscall *append)(String*, const char*);
extern const char* (__thiscall *get_text)(const String*);
struct Entry {
    int value;
    String text;
};
void fn_ROCX000016_00435510(int* count, String* output, Entry** entry)
{
    if (*count > 0)
        append(output, ", ");
    Entry* e = *entry;
    append(output, get_text(&e->text));
    ++*count;
}
}
