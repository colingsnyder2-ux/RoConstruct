// from server: 100% by Intel
// from server: 97% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 00407720  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407720
//
// 00407720  57                   push edi
// 00407721  8b7c2408             mov edi, dword ptr [esp + 8]
// 00407725  85ff                 test edi, edi
// 00407727  7405                 je 0x40772e
// 00407729  8d47fc               lea eax, [edi - 4]
// 0040772c  eb02                 jmp 0x407730
// 0040772e  33c0                 xor eax, eax
// 00407730  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00407733  8d542408             lea edx, [esp + 8]
// 00407737  52                   push edx
// 00407738  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040773c  83c014               add eax, 0x14
// 0040773f  52                   push edx
// 00407740  50                   push eax
// 00407741  8b01                 mov eax, dword ptr [ecx]
// 00407743  ffd0                 call eax
// 00407745  85c0                 test eax, eax
// 00407747  7d09                 jge 0x407752
// 00407749  b802400080           mov eax, 0x80004002
// 0040774e  5f                   pop edi
// 0040774f  c21000               ret 0x10
// 00407752  8b442408             mov eax, dword ptr [esp + 8]
// 00407756  8b08                 mov ecx, dword ptr [eax]
// 00407758  8b5108               mov edx, dword ptr [ecx + 8]
// 0040775b  56                   push esi
// 0040775c  50                   push eax
// 0040775d  ffd2                 call edx
// 0040775f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00407763  f7c6feffffff         test esi, 0xfffffffe
// 00407769  740a                 je 0x407775
// 0040776b  5e                   pop esi
// 0040776c  b805400080           mov eax, 0x80004005
// 00407771  5f                   pop edi
// 00407772  c21000               ret 0x10
// 00407775  8bcf                 mov ecx, edi
// 00407777  e884fdffff           call 0x407500
// 0040777c  85c0                 test eax, eax
// 0040777e  7512                 jne 0x407792
// 00407780  8bc6                 mov eax, esi
// 00407782  23742418             and esi, dword ptr [esp + 0x18]
// 00407786  f7d0                 not eax
// 00407788  234704               and eax, dword ptr [edi + 4]
// 0040778b  0bc6                 or eax, esi
// 0040778d  894704               mov dword ptr [edi + 4], eax
// 00407790  33c0                 xor eax, eax
// 00407792  5e                   pop esi
// 00407793  5f                   pop edi
// 00407794  c21000               ret 0x10

// from server: 100% by EspClaude
// roc 2008-06 00404db0  unit: VCWorkspace::?$CComObject  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00404db0
//
// 00404db0  57                   push edi
// 00404db1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00404db5  85ff                 test edi, edi
// 00404db7  7405                 je 0x404dbe
// 00404db9  8d47f8               lea eax, [edi - 8]
// 00404dbc  eb02                 jmp 0x404dc0
// 00404dbe  33c0                 xor eax, eax
// 00404dc0  8b08                 mov ecx, dword ptr [eax]
// 00404dc2  8d542408             lea edx, [esp + 8]
// 00404dc6  52                   push edx
// 00404dc7  8b542410             mov edx, dword ptr [esp + 0x10]
// 00404dcb  52                   push edx
// 00404dcc  50                   push eax
// 00404dcd  8b01                 mov eax, dword ptr [ecx]
// 00404dcf  ffd0                 call eax
// 00404dd1  85c0                 test eax, eax
// 00404dd3  7d09                 jge 0x404dde
// 00404dd5  b802400080           mov eax, 0x80004002
// 00404dda  5f                   pop edi
// 00404ddb  c21000               ret 0x10
// 00404dde  8b442408             mov eax, dword ptr [esp + 8]
// 00404de2  8b08                 mov ecx, dword ptr [eax]
// 00404de4  8b5108               mov edx, dword ptr [ecx + 8]
// 00404de7  56                   push esi
// 00404de8  50                   push eax
// 00404de9  ffd2                 call edx
// 00404deb  8b742414             mov esi, dword ptr [esp + 0x14]
// 00404def  f7c6feffffff         test esi, 0xfffffffe
// 00404df5  740a                 je 0x404e01
// 00404df7  5e                   pop esi
// 00404df8  b805400080           mov eax, 0x80004005
// 00404dfd  5f                   pop edi
// 00404dfe  c21000               ret 0x10
// 00404e01  8bcf                 mov ecx, edi
// 00404e03  e858edffff           call 0x403b60
// 00404e08  85c0                 test eax, eax
// 00404e0a  7512                 jne 0x404e1e
// 00404e0c  8bc6                 mov eax, esi
// 00404e0e  23742418             and esi, dword ptr [esp + 0x18]
// 00404e12  f7d0                 not eax
// 00404e14  234704               and eax, dword ptr [edi + 4]
// 00404e17  0bc6                 or eax, esi
// 00404e19  894704               mov dword ptr [edi + 4], eax
// 00404e1c  33c0                 xor eax, eax
// 00404e1e  5e                   pop esi
// 00404e1f  5f                   pop edi
// 00404e20  c21000               ret 0x10

// from server: 92% by king_originala
// roc 2008-06 00404db0  unit: VCWorkspace::?$CComObject  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00404db0
//
// 00404db0  57                   push edi
// 00404db1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00404db5  85ff                 test edi, edi
// 00404db7  7405                 je 0x404dbe
// 00404db9  8d47f8               lea eax, [edi - 8]
// 00404dbc  eb02                 jmp 0x404dc0
// 00404dbe  33c0                 xor eax, eax
// 00404dc0  8b08                 mov ecx, dword ptr [eax]
// 00404dc2  8d542408             lea edx, [esp + 8]
// 00404dc6  52                   push edx
// 00404dc7  8b542410             mov edx, dword ptr [esp + 0x10]
// 00404dcb  52                   push edx
// 00404dcc  50                   push eax
// 00404dcd  8b01                 mov eax, dword ptr [ecx]
// 00404dcf  ffd0                 call eax
// 00404dd1  85c0                 test eax, eax
// 00404dd3  7d09                 jge 0x404dde
// 00404dd5  b802400080           mov eax, 0x80004002
// 00404dda  5f                   pop edi
// 00404ddb  c21000               ret 0x10
// 00404dde  8b442408             mov eax, dword ptr [esp + 8]
// 00404de2  8b08                 mov ecx, dword ptr [eax]
// 00404de4  8b5108               mov edx, dword ptr [ecx + 8]
// 00404de7  56                   push esi
// 00404de8  50                   push eax
// 00404de9  ffd2                 call edx
// 00404deb  8b742414             mov esi, dword ptr [esp + 0x14]
// 00404def  f7c6feffffff         test esi, 0xfffffffe
// 00404df5  740a                 je 0x404e01
// 00404df7  5e                   pop esi
// 00404df8  b805400080           mov eax, 0x80004005
// 00404dfd  5f                   pop edi
// 00404dfe  c21000               ret 0x10
// 00404e01  8bcf                 mov ecx, edi
// 00404e03  e858edffff           call 0x403b60
// 00404e08  85c0                 test eax, eax
// 00404e0a  7512                 jne 0x404e1e
// 00404e0c  8bc6                 mov eax, esi
// 00404e0e  23742418             and esi, dword ptr [esp + 0x18]
// 00404e12  f7d0                 not eax
// 00404e14  234704               and eax, dword ptr [edi + 4]
// 00404e17  0bc6                 or eax, esi
// 00404e19  894704               mov dword ptr [edi + 4], eax
// 00404e1c  33c0                 xor eax, eax
// 00404e1e  5e                   pop esi
// 00404e1f  5f                   pop edi
// 00404e20  c21000               ret 0x10

struct Interface;

struct VTable {
    long (__stdcall *query)(Interface *, const void *, void **);
    unsigned long (__stdcall *addRef)(Interface *);
    unsigned long (__stdcall *release)(Interface *);
};

struct Interface {
    VTable *vtable;
};

struct Object {
    unsigned long reserved;
    unsigned long flags;
    long check();
};

struct Root { virtual ~Root(); char bytes[0x10]; };
struct Pad { char bytes[8]; };
struct IFace { VTable* vtable; long QueryInterface(const void* id, void** p) { return vtable->query(reinterpret_cast<Interface*>(this),id,p); } unsigned long Release() { return vtable->release(reinterpret_cast<Interface*>(this)); } };
struct Full : Root, Object, Pad, IFace {};

extern "C" long __stdcall update(Object *object, const void *iid,
                                unsigned long mask, unsigned long value)
{
    Full* full = static_cast<Full*>(object);
    IFace* base = reinterpret_cast<IFace*>(reinterpret_cast<char*>(full) + 0x24);
    void *p;
    if (base->QueryInterface(iid, &p) < 0)
        return 0x80004002L;

    IFace *result = reinterpret_cast<IFace *>(p);
    result->Release();

    if (mask & 0xFFFFFFFEUL)
        return 0x80004005L;

    long status = object->check();
    if (status == 0) {
        object->flags = (object->flags & ~mask) | (mask & value);
        return 0;
    }
    return status;
}
