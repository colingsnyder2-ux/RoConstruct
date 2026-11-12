// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00451be0  unit: ReportAbuseVerb  size: 318 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00451be0
//
// 00451be0  6aff                 push -1
// 00451be2  68580f7400           push 0x740f58
// 00451be7  64a100000000         mov eax, dword ptr fs:[0]
// 00451bed  50                   push eax
// 00451bee  83ec1c               sub esp, 0x1c
// 00451bf1  56                   push esi
// 00451bf2  57                   push edi
// 00451bf3  a188518b00           mov eax, dword ptr [0x8b5188]
// 00451bf8  33c4                 xor eax, esp
// 00451bfa  50                   push eax
// 00451bfb  8d442428             lea eax, [esp + 0x28]
// 00451bff  64a300000000         mov dword ptr fs:[0], eax
// 00451c05  8bf9                 mov edi, ecx
// 00451c07  8b4f78               mov ecx, dword ptr [edi + 0x78]
// 00451c0a  8d442414             lea eax, [esp + 0x14]
// 00451c0e  50                   push eax
// 00451c0f  e8ec1bfbff           call 0x403800
// 00451c14  8b10                 mov edx, dword ptr [eax]
// 00451c16  83ec08               sub esp, 8
// 00451c19  8bcc                 mov ecx, esp
// 00451c1b  8911                 mov dword ptr [ecx], edx
// 00451c1d  8b4004               mov eax, dword ptr [eax + 4]
// 00451c20  85c0                 test eax, eax
// 00451c22  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00451c2a  89642414             mov dword ptr [esp + 0x14], esp
// 00451c2e  894104               mov dword ptr [ecx + 4], eax
// 00451c31  740c                 je 0x451c3f
// 00451c33  83c004               add eax, 4
// 00451c36  b901000000           mov ecx, 1
// 00451c3b  f00fc108             lock xadd dword ptr [eax], ecx
// 00451c3f  8d4c2424             lea ecx, [esp + 0x24]
// 00451c43  e808b9fbff           call 0x40d550
// 00451c48  8b742418             mov esi, dword ptr [esp + 0x18]
// 00451c4c  85f6                 test esi, esi
// 00451c4e  c644243002           mov byte ptr [esp + 0x30], 2
// 00451c53  742a                 je 0x451c7f
// 00451c55  8d5604               lea edx, [esi + 4]
// 00451c58  83c8ff               or eax, 0xffffffff
// 00451c5b  f00fc102             lock xadd dword ptr [edx], eax
// 00451c5f  751e                 jne 0x451c7f
// 00451c61  8b16                 mov edx, dword ptr [esi]
// 00451c63  8b4204               mov eax, dword ptr [edx + 4]
// 00451c66  8bce                 mov ecx, esi
// 00451c68  ffd0                 call eax
// 00451c6a  8d4e08               lea ecx, [esi + 8]
// 00451c6d  83caff               or edx, 0xffffffff
// 00451c70  f00fc111             lock xadd dword ptr [ecx], edx
// 00451c74  7509                 jne 0x451c7f
// 00451c76  8b06                 mov eax, dword ptr [esi]
// 00451c78  8b5008               mov edx, dword ptr [eax + 8]
// 00451c7b  8bce                 mov ecx, esi
// 00451c7d  ffd2                 call edx
// 00451c7f  8d44240c             lea eax, [esp + 0xc]
// 00451c83  50                   push eax
// 00451c84  8bcf                 mov ecx, edi
// 00451c86  e8a51bfbff           call 0x403830
// 00451c8b  8b08                 mov ecx, dword ptr [eax]
// 00451c8d  85c9                 test ecx, ecx
// 00451c8f  c644243003           mov byte ptr [esp + 0x30], 3
// 00451c94  7409                 je 0x451c9f
// 00451c96  e875c7fdff           call 0x42e410
// 00451c9b  8bf8                 mov edi, eax
// 00451c9d  eb02                 jmp 0x451ca1
// 00451c9f  33ff                 xor edi, edi
// 00451ca1  8b742410             mov esi, dword ptr [esp + 0x10]
// 00451ca5  85f6                 test esi, esi
// 00451ca7  c644243002           mov byte ptr [esp + 0x30], 2
// 00451cac  742a                 je 0x451cd8
// 00451cae  8d4e04               lea ecx, [esi + 4]
// 00451cb1  83caff               or edx, 0xffffffff
// 00451cb4  f00fc111             lock xadd dword ptr [ecx], edx
// 00451cb8  751e                 jne 0x451cd8
// 00451cba  8b06                 mov eax, dword ptr [esi]
// 00451cbc  8b5004               mov edx, dword ptr [eax + 4]
// 00451cbf  8bce                 mov ecx, esi
// 00451cc1  ffd2                 call edx
// 00451cc3  8d4608               lea eax, [esi + 8]
// 00451cc6  83c9ff               or ecx, 0xffffffff
// 00451cc9  f00fc108             lock xadd dword ptr [eax], ecx
// 00451ccd  7509                 jne 0x451cd8
// 00451ccf  8b16                 mov edx, dword ptr [esi]
// 00451cd1  8b4208               mov eax, dword ptr [edx + 8]
// 00451cd4  8bce                 mov ecx, esi
// 00451cd6  ffd0                 call eax
// 00451cd8  85ff                 test edi, edi
// 00451cda  7410                 je 0x451cec
// 00451cdc  83bff000000000       cmp dword ptr [edi + 0xf0], 0
// 00451ce3  7407                 je 0x451cec
// 00451ce5  b801000000           mov eax, 1
// 00451cea  eb02                 jmp 0x451cee
// 00451cec  33c0                 xor eax, eax
// 00451cee  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00451cf2  8b11                 mov edx, dword ptr [ecx]
// 00451cf4  50                   push eax
// 00451cf5  8b02                 mov eax, dword ptr [edx]
// 00451cf7  ffd0                 call eax
// 00451cf9  8d4c241c             lea ecx, [esp + 0x1c]
// 00451cfd  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00451d05  e896781000           call 0x5595a0
// 00451d0a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00451d0e  64890d00000000       mov dword ptr fs:[0], ecx
// 00451d15  59                   pop ecx
// 00451d16  5f                   pop edi
// 00451d17  5e                   pop esi
// 00451d18  83c428               add esp, 0x28
// 00451d1b  c20400               ret 4

#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    T* get() const { return px; }
    T* operator->() const { return px; }
};

class CCmdUI {
public:
    virtual void Enable(int bOn);
};

class Instance {};
class DataModel : public Instance {};

class DataModelLock {
public:
    DataModelLock(shared_ptr<Instance> instance);
    ~DataModelLock();
private:
    int state[3];
};

class DocumentHost {
public:
    shared_ptr<DataModel> getDataModel();
};

class Player {
public:
    char pad[0xf0];
    void* field_f0;
};

class Workspace {
public:
    Player* getLocalPlayer();
};

inline Player* findLocalPlayer(Workspace* w)
{
    return w ? w->getLocalPlayer() : 0;
}

class ReportAbuseVerb {
public:
    char pad[0x78];
    DocumentHost* host;
    shared_ptr<Workspace> getWorkspace();
    void updateCmdUI(CCmdUI* ui);
};

void ReportAbuseVerb::updateCmdUI(CCmdUI* ui)
{
    DataModelLock lock(host->getDataModel());
    Player* player = findLocalPlayer(getWorkspace().get());
    ui->Enable(player && player->field_f0 != 0);
}
