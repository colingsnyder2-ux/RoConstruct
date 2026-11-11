// from server: 100% by EspClaude
// from server: 76% by colin
// roc 2007-08 0054de80  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054de80
//
// 0054de80  56                   push esi
// 0054de81  8bf1                 mov esi, ecx
// 0054de83  8b4624               mov eax, dword ptr [esi + 0x24]
// 0054de86  833800               cmp dword ptr [eax], 0
// 0054de89  7406                 je 0x54de91
// 0054de8b  ff1504e67700         call dword ptr [0x77e604]
// 0054de91  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0054de95  83f901               cmp ecx, 1
// 0054de98  7516                 jne 0x54deb0
// 0054de9a  8b5620               mov edx, dword ptr [esi + 0x20]
// 0054de9d  833a00               cmp dword ptr [edx], 0
// 0054dea0  740e                 je 0x54deb0
// 0054dea2  8b4630               mov eax, dword ptr [esi + 0x30]
// 0054dea5  8b00                 mov eax, dword ptr [eax]
// 0054dea7  99                   cdq 
// 0054dea8  2944240c             sub dword ptr [esp + 0xc], eax
// 0054deac  19542410             sbb dword ptr [esp + 0x10], edx
// 0054deb0  8b5610               mov edx, dword ptr [esi + 0x10]
// 0054deb3  c70200000000         mov dword ptr [edx], 0
// 0054deb9  8b4620               mov eax, dword ptr [esi + 0x20]
// 0054debc  c70000000000         mov dword ptr [eax], 0
// 0054dec2  8b5630               mov edx, dword ptr [esi + 0x30]
// 0054dec5  c70200000000         mov dword ptr [edx], 0
// 0054decb  8b4614               mov eax, dword ptr [esi + 0x14]
// 0054dece  c70000000000         mov dword ptr [eax], 0
// 0054ded4  8b5624               mov edx, dword ptr [esi + 0x24]
// 0054ded7  c70200000000         mov dword ptr [edx], 0
// 0054dedd  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054dee0  c70000000000         mov dword ptr [eax], 0
// 0054dee6  8b564c               mov edx, dword ptr [esi + 0x4c]
// 0054dee9  8b442418             mov eax, dword ptr [esp + 0x18]
// 0054deed  52                   push edx
// 0054deee  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054def2  50                   push eax
// 0054def3  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054def7  51                   push ecx
// 0054def8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054defc  51                   push ecx
// 0054defd  52                   push edx
// 0054defe  50                   push eax
// 0054deff  8d4e40               lea ecx, [esi + 0x40]
// 0054df02  e8f9160000           call 0x54f600
// 0054df07  5e                   pop esi

struct Pos {
    long long off;
    int state;
};

struct Next;

struct Dev {
    __declspec(noreturn) Pos seek(long long off, int way, int which, Next* next);
};

struct __declspec(dllimport) StreambufBase {
    void* vtbl;
    void* mylock;
    char** gfirst;
    char** pfirst;
    char** igfirst;
    char** ipfirst;
    char** gnext;
    char** pnext;
    char** ignext;
    char** ipnext;
    int* gcount;
    int* pcount;
    int* igcount;
    int* ipcount;
    int pubsync();
};

struct S : StreambufBase {
    char pad[0x8];
    Dev obj;
    char pad2[0x8];
    Next* next;
    Pos seek_impl(long long off, int way, int which);
};

Pos S::seek_impl(long long off, int way, int which)
{
    if (*ipnext != 0)
        pubsync();
    if (way == 1 && *ignext != 0)
        off -= *igcount;
    *igfirst = 0;
    *ignext = 0;
    *igcount = 0;
    *ipfirst = 0;
    *ipnext = 0;
    *ipcount = 0;
    return obj.seek(off, way, which, next);
}
