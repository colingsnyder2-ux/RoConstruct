// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 43% by colin
// roc 2007-08 00550230  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 194 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00550230
// 00550230  6aff                 push -1
// 00550232  6850297500           push 0x752950
// 00550237  64a100000000         mov eax, dword ptr fs:[0]
// 0055023d  50                   push eax
// 0055023e  64892500000000       mov dword ptr fs:[0], esp
// 00550245  83ec0c               sub esp, 0xc
// 00550248  53                   push ebx
// 00550249  56                   push esi
// 0055024a  8bf1                 mov esi, ecx
// 0055024c  57                   push edi
// 0055024d  8974240c             mov dword ptr [esp + 0xc], esi
// 00550251  ff1518e57700         call dword ptr [0x77e518]
// 00550257  33db                 xor ebx, ebx
// 00550259  885e3c               mov byte ptr [esi + 0x3c], bl
// 0055025c  885e48               mov byte ptr [esi + 0x48], bl
// 0055025f  895e4c               mov dword ptr [esi + 0x4c], ebx
// 00550262  895e50               mov dword ptr [esi + 0x50], ebx
// 00550265  895e54               mov dword ptr [esi + 0x54], ebx
// 00550268  895e58               mov dword ptr [esi + 0x58], ebx
// 0055026b  c7465c10000000       mov dword ptr [esi + 0x5c], 0x10
// 00550272  8b442428             mov eax, dword ptr [esp + 0x28]
// 00550276  53                   push ebx
// 00550277  50                   push eax
// 00550278  8d4c2418             lea ecx, [esp + 0x18]
// 0055027c  51                   push ecx
// 0055027d  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00550281  c7060c7b7a00         mov dword ptr [esi], 0x7a7b0c
// 00550287  e8541ff1ff           call 0x4621e0
// 0055028c  83c40c               add esp, 0xc
// 0055028f  8b542430             mov edx, dword ptr [esp + 0x30]
// 00550293  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00550297  52                   push edx
// 00550298  51                   push ecx
// 00550299  50                   push eax
// 0055029a  8bce                 mov ecx, esi
// 0055029c  c644242c01           mov byte ptr [esp + 0x2c], 1
// 005502a1  e89aefffff           call 0x54f240
// 005502a6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005502aa  3bfb                 cmp edi, ebx
// 005502ac  885c2420             mov byte ptr [esp + 0x20], bl
// 005502b0  742a                 je 0x5502dc
// 005502b2  8d5704               lea edx, [edi + 4]
// 005502b5  83c8ff               or eax, 0xffffffff
// 005502b8  f00fc102             lock xadd dword ptr [edx], eax
// 005502bc  751e                 jne 0x5502dc
// 005502be  8b17                 mov edx, dword ptr [edi]
// 005502c0  8b4204               mov eax, dword ptr [edx + 4]
// 005502c3  8bcf                 mov ecx, edi
// 005502c5  ffd0                 call eax
// 005502c7  8d4f08               lea ecx, [edi + 8]
// 005502ca  83caff               or edx, 0xffffffff
// 005502cd  f00fc111             lock xadd dword ptr [ecx], edx
// 005502d1  7509                 jne 0x5502dc
// 005502d3  8b07                 mov eax, dword ptr [edi]
// 005502d5  8b5008               mov edx, dword ptr [eax + 8]
// 005502d8  8bcf                 mov ecx, edi
// 005502da  ffd2                 call edx
// 005502dc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005502e0  5f                   pop edi
// 005502e1  8bc6                 mov eax, esi
// 005502e3  5e                   pop esi
// 005502e4  5b                   pop ebx
// 005502e5  64890d00000000       mov dword ptr fs:[0], ecx
// 005502ec  83c418               add esp, 0x18
// 005502ef  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};

struct T;

struct shared_ptr_T {
    T* px;
    sp_counted_base* pn;
    ~shared_ptr_T() {
        if (pn != 0) pn->release();
    }
};

shared_ptr_T make_device(void* a, int b);

struct StreambufBase {
    __declspec(dllimport) StreambufBase();
    __declspec(dllimport) virtual ~StreambufBase();
    int base_data[14];
};

struct IndirectBuf : StreambufBase {
    bool flag3c;
    int pad40[2];
    bool flag48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;

    IndirectBuf()
        : flag3c(false), flag48(false), f4c(0), f50(0), f54(0), f58(0), f5c(0x10)
    {
    }
    virtual ~IndirectBuf();
};

struct StreamBuffer : IndirectBuf {
    StreamBuffer(void* a1, void* a2, void* a3);
    virtual ~StreamBuffer();
    void open(const shared_ptr_T& dev, void* a2, void* a3);
};

StreamBuffer::StreamBuffer(void* a1, void* a2, void* a3)
{
    open(make_device(a1, 0), a2, a3);
}
