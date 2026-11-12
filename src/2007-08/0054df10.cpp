// from server: 90% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 53% by colin
// roc 2007-08 0054df10  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054df10
//
// 0054df10  64a100000000         mov eax, dword ptr fs:[0]
// 0054df16  6aff                 push -1
// 0054df18  68d8bc7500           push 0x75bcd8
// 0054df1d  50                   push eax
// 0054df1e  64892500000000       mov dword ptr fs:[0], esp
// 0054df25  83ec08               sub esp, 8
// 0054df28  56                   push esi
// 0054df29  8bf1                 mov esi, ecx
// 0054df2b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0054df2f  83f9ff               cmp ecx, -1
// 0054df32  57                   push edi
// 0054df33  7505                 jne 0x54df3a
// 0054df35  b980000000           mov ecx, 0x80
// 0054df3a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0054df3e  83f8ff               cmp eax, -1
// 0054df41  7509                 jne 0x54df4c
// 0054df43  b804000000           mov eax, 4
// 0054df48  89442428             mov dword ptr [esp + 0x28], eax
// 0054df4c  83f802               cmp eax, 2
// 0054df4f  c744242402000000     mov dword ptr [esp + 0x24], 2
// 0054df57  8d442428             lea eax, [esp + 0x28]
// 0054df5b  7f04                 jg 0x54df61
// 0054df5d  8d442424             lea eax, [esp + 0x24]
// 0054df61  85c9                 test ecx, ecx
// 0054df63  8b00                 mov eax, dword ptr [eax]
// 0054df65  894658               mov dword ptr [esi + 0x58], eax
// 0054df68  7505                 jne 0x54df6f
// 0054df6a  b901000000           mov ecx, 1
// 0054df6f  8d3c08               lea edi, [eax + ecx]
// 0054df72  397e54               cmp dword ptr [esi + 0x54], edi
// 0054df75  7429                 je 0x54dfa0
// 0054df77  6a00                 push 0
// 0054df79  57                   push edi
// 0054df7a  8d4c2430             lea ecx, [esp + 0x30]
// 0054df7e  ff1518e67700         call dword ptr [0x77e618]
// 0054df84  8b5654               mov edx, dword ptr [esi + 0x54]
// 0054df87  897e54               mov dword ptr [esi + 0x54], edi
// 0054df8a  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0054df8d  85c9                 test ecx, ecx
// 0054df8f  894650               mov dword ptr [esi + 0x50], eax
// 0054df92  740c                 je 0x54dfa0
// 0054df94  52                   push edx
// 0054df95  51                   push ecx
// 0054df96  8d4c2430             lea ecx, [esp + 0x30]
// 0054df9a  ff1510e67700         call dword ptr [0x77e610]
// 0054dfa0  8b06                 mov eax, dword ptr [esi]
// 0054dfa2  8b5054               mov edx, dword ptr [eax + 0x54]
// 0054dfa5  8bce                 mov ecx, esi
// 0054dfa7  ffd2                 call edx
// 0054dfa9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0054dfad  8b7804               mov edi, dword ptr [eax + 4]
// 0054dfb0  85ff                 test edi, edi
// 0054dfb2  8b08                 mov ecx, dword ptr [eax]
// 0054dfb4  894c2408             mov dword ptr [esp + 8], ecx
// 0054dfb8  897c240c             mov dword ptr [esp + 0xc], edi
// 0054dfbc  740c                 je 0x54dfca
// 0054dfbe  8d5704               lea edx, [edi + 4]
// 0054dfc1  b801000000           mov eax, 1
// 0054dfc6  f00fc102             lock xadd dword ptr [edx], eax
// 0054dfca  8d4c2408             lea ecx, [esp + 8]
// 0054dfce  51                   push ecx
// 0054dfcf  8d4e40               lea ecx, [esi + 0x40]
// 0054dfd2  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0054dfda  e861f3ffff           call 0x54d340
// 0054dfdf  85ff                 test edi, edi
// 0054dfe1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0054dfe9  742a                 je 0x54e015
// 0054dfeb  8d5704               lea edx, [edi + 4]
// 0054dfee  83c8ff               or eax, 0xffffffff
// 0054dff1  f00fc102             lock xadd dword ptr [edx], eax
// 0054dff5  751e                 jne 0x54e015
// 0054dff7  8b17                 mov edx, dword ptr [edi]
// 0054dff9  8b4204               mov eax, dword ptr [edx + 4]
// 0054dffc  8bcf                 mov ecx, edi
// 0054dffe  ffd0                 call eax
// 0054e000  8d4f08               lea ecx, [edi + 8]
// 0054e003  83caff               or edx, 0xffffffff
// 0054e006  f00fc111             lock xadd dword ptr [ecx], edx
// 0054e00a  7509                 jne 0x54e015
// 0054e00c  8b07                 mov eax, dword ptr [edi]
// 0054e00e  8b5008               mov edx, dword ptr [eax + 8]
// 0054e011  8bcf                 mov ecx, edi
// 0054e013  ffd2                 call edx
// 0054e015  834e5c01             or dword ptr [esi + 0x5c], 1
// 0054e019  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054e01d  c6463c00             mov byte ptr [esi + 0x3c], 0
// 0054e021  5f                   pop edi
// 0054e022  5e                   pop esi
// 0054e023  64890d00000000       mov dword ptr fs:[0], ecx
// 0054e02a  83c414               add esp, 0x14

#include <memory>
#include <intrin.h>

struct CountedBase {
    long use_count;     // +4
    long weak_count;    // +8
    virtual ~CountedBase();
    virtual void dispose();
    virtual void destroy();
    void add_ref() { _InterlockedIncrement(&use_count); }
    void release() {
        if (_InterlockedDecrement(&use_count) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count) == 0)
                destroy();
        }
    }
};

struct SharedCount {
    CountedBase* pi;
    SharedCount(const SharedCount& r) : pi(r.pi) { if (pi) pi->add_ref(); }
    ~SharedCount() { if (pi) pi->release(); }
};

struct Device {
    void* px;
    SharedCount pn;
};

struct ConceptAdapter {
    explicit ConceptAdapter(const Device& t) : t_(t) {}
    Device t_;
};

inline ConceptAdapter wrapper(const Device& t) { return ConceptAdapter(t); }

struct Storage {
    void reset(const ConceptAdapter& t);
    char pad[0x10];
};

#include <algorithm>

struct __declspec(dllimport) CharAlloc {
    CharAlloc() {}
    char* allocate(unsigned int n, const void* hint);
    void deallocate(char* p, unsigned int n);
};

struct Buffer {
    char* buf;
    int size;
    Buffer(int n) : buf(CharAlloc().allocate(n, 0)), size(n) {}
    ~Buffer() { if (buf) CharAlloc().deallocate(buf, size); }
    void resize(int n) {
        if (size != n) {
            Buffer temp(n);
            std::swap(size, temp.size);
            std::swap(buf, temp.buf);
        }
    }
};

struct StreambufBase {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void init_get_area();   // slot +0x54
    char pad04[0x3c - 4];
    bool true_eof;                  // +0x3c
};

struct IndirectStreambuf : StreambufBase {
    Storage storage;                // +0x40
    Buffer in;                      // +0x50
    int pback_size;                 // +0x58
    int flags;                      // +0x5c
    void open(const Device& t, int buffer_size, int pback_size);
};

void IndirectStreambuf::open(const Device& t, int buffer_size, int pback_size_arg)
{
    buffer_size = (buffer_size != -1) ? buffer_size : 0x80;
    pback_size_arg = (pback_size_arg != -1) ? pback_size_arg : 4;
    pback_size = (std::max)(2, pback_size_arg);
    int size = pback_size + (buffer_size ? buffer_size : 1);
    in.resize(size);
    init_get_area();
    storage.reset(wrapper(t));
    flags |= 1;
    true_eof = false;
}
