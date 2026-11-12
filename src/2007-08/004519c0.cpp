// from server: 68% by EspClaude
// from server: 41% by colin
// roc 2007-08 004519c0  unit: ReportAbuseVerb  size: 532 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004519c0
//
// 004519c0  6aff                 push -1
// 004519c2  68180f7400           push 0x740f18
// 004519c7  64a100000000         mov eax, dword ptr fs:[0]
// 004519cd  50                   push eax
// 004519ce  83ec4c               sub esp, 0x4c
// 004519d1  a188518b00           mov eax, dword ptr [0x8b5188]
// 004519d6  33c4                 xor eax, esp
// 004519d8  89442448             mov dword ptr [esp + 0x48], eax
// 004519dc  53                   push ebx
// 004519dd  55                   push ebp
// 004519de  56                   push esi
// 004519df  57                   push edi
// 004519e0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004519e5  33c4                 xor eax, esp
// 004519e7  50                   push eax
// 004519e8  8d442460             lea eax, [esp + 0x60]
// 004519ec  64a300000000         mov dword ptr fs:[0], eax
// 004519f2  8b442470             mov eax, dword ptr [esp + 0x70]
// 004519f6  8bf1                 mov esi, ecx
// 004519f8  8d4c2418             lea ecx, [esp + 0x18]
// 004519fc  51                   push ecx
// 004519fd  8bce                 mov ecx, esi
// 004519ff  89442418             mov dword ptr [esp + 0x18], eax
// 00451a03  e8281efbff           call 0x403830
// 00451a08  833800               cmp dword ptr [eax], 0
// 00451a0b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00451a0f  0f95c3               setne bl
// 00451a12  85c0                 test eax, eax
// 00451a14  742c                 je 0x451a42
// 00451a16  8bf8                 mov edi, eax
// 00451a18  83c004               add eax, 4
// 00451a1b  83caff               or edx, 0xffffffff
// 00451a1e  f00fc110             lock xadd dword ptr [eax], edx
// 00451a22  751e                 jne 0x451a42
// 00451a24  8b07                 mov eax, dword ptr [edi]
// 00451a26  8b5004               mov edx, dword ptr [eax + 4]
// 00451a29  8bcf                 mov ecx, edi
// 00451a2b  ffd2                 call edx
// 00451a2d  8d4708               lea eax, [edi + 8]
// 00451a30  83c9ff               or ecx, 0xffffffff
// 00451a33  f00fc108             lock xadd dword ptr [eax], ecx
// 00451a37  7509                 jne 0x451a42
// 00451a39  8b17                 mov edx, dword ptr [edi]
// 00451a3b  8b4208               mov eax, dword ptr [edx + 8]
// 00451a3e  8bcf                 mov ecx, edi
// 00451a40  ffd0                 call eax
// 00451a42  84db                 test bl, bl
// 00451a44  0f8469010000         je 0x451bb3
// 00451a4a  8d4c2420             lea ecx, [esp + 0x20]
// 00451a4e  51                   push ecx
// 00451a4f  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 00451a52  e8a91dfbff           call 0x403800
// 00451a57  8b10                 mov edx, dword ptr [eax]
// 00451a59  83ec08               sub esp, 8
// 00451a5c  8bcc                 mov ecx, esp
// 00451a5e  8911                 mov dword ptr [ecx], edx
// 00451a60  8b4004               mov eax, dword ptr [eax + 4]
// 00451a63  85c0                 test eax, eax
// 00451a65  c744247000000000     mov dword ptr [esp + 0x70], 0
// 00451a6d  89642420             mov dword ptr [esp + 0x20], esp
// 00451a71  894104               mov dword ptr [ecx + 4], eax
// 00451a74  740c                 je 0x451a82
// 00451a76  83c004               add eax, 4
// 00451a79  b901000000           mov ecx, 1
// 00451a7e  f00fc108             lock xadd dword ptr [eax], ecx
// 00451a82  8d4c2438             lea ecx, [esp + 0x38]
// 00451a86  e8c5bafbff           call 0x40d550
// 00451a8b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00451a8f  85ff                 test edi, edi
// 00451a91  b302                 mov bl, 2
// 00451a93  885c2468             mov byte ptr [esp + 0x68], bl
// 00451a97  742a                 je 0x451ac3
// 00451a99  8d5704               lea edx, [edi + 4]
// 00451a9c  83c8ff               or eax, 0xffffffff
// 00451a9f  f00fc102             lock xadd dword ptr [edx], eax
// 00451aa3  751e                 jne 0x451ac3
// 00451aa5  8b17                 mov edx, dword ptr [edi]
// 00451aa7  8b4204               mov eax, dword ptr [edx + 4]
// 00451aaa  8bcf                 mov ecx, edi
// 00451aac  ffd0                 call eax
// 00451aae  8d4f08               lea ecx, [edi + 8]
// 00451ab1  83caff               or edx, 0xffffffff
// 00451ab4  f00fc111             lock xadd dword ptr [ecx], edx
// 00451ab8  7509                 jne 0x451ac3
// 00451aba  8b07                 mov eax, dword ptr [edi]
// 00451abc  8b5008               mov edx, dword ptr [eax + 8]
// 00451abf  8bcf                 mov ecx, edi
// 00451ac1  ffd2                 call edx
// 00451ac3  8d442418             lea eax, [esp + 0x18]
// 00451ac7  50                   push eax
// 00451ac8  8bce                 mov ecx, esi
// 00451aca  e8611dfbff           call 0x403830
// 00451acf  8b08                 mov ecx, dword ptr [eax]
// 00451ad1  c644246803           mov byte ptr [esp + 0x68], 3
// 00451ad6  e8e5f3ffff           call 0x450ec0
// 00451adb  8ba84c010000         mov ebp, dword ptr [eax + 0x14c]
// 00451ae1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00451ae5  85c0                 test eax, eax
// 00451ae7  885c2468             mov byte ptr [esp + 0x68], bl
// 00451aeb  742c                 je 0x451b19
// 00451aed  8bf8                 mov edi, eax
// 00451aef  83c004               add eax, 4
// 00451af2  83c9ff               or ecx, 0xffffffff
// 00451af5  f00fc108             lock xadd dword ptr [eax], ecx
// 00451af9  751e                 jne 0x451b19
// 00451afb  8b17                 mov edx, dword ptr [edi]
// 00451afd  8b4204               mov eax, dword ptr [edx + 4]
// 00451b00  8bcf                 mov ecx, edi
// 00451b02  ffd0                 call eax
// 00451b04  8d4f08               lea ecx, [edi + 8]
// 00451b07  83caff               or edx, 0xffffffff
// 00451b0a  f00fc111             lock xadd dword ptr [ecx], edx
// 00451b0e  7509                 jne 0x451b19
// 00451b10  8b07                 mov eax, dword ptr [edi]
// 00451b12  8b5008               mov edx, dword ptr [eax + 8]
// 00451b15  8bcf                 mov ecx, edi
// 00451b17  ffd2                 call edx
// 00451b19  83fd01               cmp ebp, 1
// 00451b1c  7410                 je 0x451b2e
// 00451b1e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00451b22  8b01                 mov eax, dword ptr [ecx]
// 00451b24  8b500c               mov edx, dword ptr [eax + 0xc]
// 00451b27  6854597800           push 0x785954
// 00451b2c  eb72                 jmp 0x451ba0
// 00451b2e  8d442428             lea eax, [esp + 0x28]
// 00451b32  50                   push eax
// 00451b33  8bce                 mov ecx, esi
// 00451b35  e8f61cfbff           call 0x403830
// 00451b3a  8b00                 mov eax, dword ptr [eax]
// 00451b3c  8b80e0010000         mov eax, dword ptr [eax + 0x1e0]
// 00451b42  dd4040               fld qword ptr [eax + 0x40]
// 00451b45  83ec08               sub esp, 8
// 00451b48  dd1c24               fstp qword ptr [esp]
// 00451b4b  8d4c2444             lea ecx, [esp + 0x44]
// 00451b4f  68bc197900           push 0x7919bc
// 00451b54  51                   push ecx
// 00451b55  ff1568e97700         call dword ptr [0x77e968]
// 00451b5b  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00451b5f  83c410               add esp, 0x10
// 00451b62  85c0                 test eax, eax
// 00451b64  742c                 je 0x451b92
// 00451b66  8bf0                 mov esi, eax
// 00451b68  83c004               add eax, 4
// 00451b6b  83caff               or edx, 0xffffffff
// 00451b6e  f00fc110             lock xadd dword ptr [eax], edx
// 00451b72  751e                 jne 0x451b92
// 00451b74  8b06                 mov eax, dword ptr [esi]
// 00451b76  8b5004               mov edx, dword ptr [eax + 4]
// 00451b79  8bce                 mov ecx, esi
// 00451b7b  ffd2                 call edx
// 00451b7d  8d4608               lea eax, [esi + 8]
// 00451b80  83c9ff               or ecx, 0xffffffff
// 00451b83  f00fc108             lock xadd dword ptr [eax], ecx
// 00451b87  7509                 jne 0x451b92
// 00451b89  8b16                 mov edx, dword ptr [esi]
// 00451b8b  8b4208               mov eax, dword ptr [edx + 8]
// 00451b8e  8bce                 mov ecx, esi
// 00451b90  ffd0                 call eax
// 00451b92  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00451b96  8b11                 mov edx, dword ptr [ecx]
// 00451b98  8b520c               mov edx, dword ptr [edx + 0xc]
// 00451b9b  8d44243c             lea eax, [esp + 0x3c]
// 00451b9f  50                   push eax
// 00451ba0  ffd2                 call edx
// 00451ba2  8d4c2430             lea ecx, [esp + 0x30]
// 00451ba6  c7442468ffffffff     mov dword ptr [esp + 0x68], 0xffffffff
// 00451bae  e8ed791000           call 0x5595a0
// 00451bb3  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00451bb7  64890d00000000       mov dword ptr fs:[0], ecx
// 00451bbe  59                   pop ecx
// 00451bbf  5f                   pop edi
// 00451bc0  5e                   pop esi
// 00451bc1  5d                   pop ebp
// 00451bc2  5b                   pop ebx
// 00451bc3  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00451bc7  33cc                 xor ecx, esp
// 00451bc9  e850ee1d00           call 0x630a1e
// 00451bce  83c458               add esp, 0x58
// 00451bd1  c20400               ret 4

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

extern "C" __declspec(dllimport) int __cdecl sprintf(char* buffer, const char* format, ...);

class CCmdUIText : public CCmdUI {
public:
    virtual void SetCheck(int nCheck);
    virtual void SetRadio(int bOn);
    virtual void SetText(const char* lpszText);
};

class RunState {
public:
    char pad[0x14c];
    int mode;
};

class FrameStats {
public:
    char pad[0x40];
    double fps;
};

class Workspace {
public:
    char pad[0x1e0];
    FrameStats* stats;
    RunState* getRunState();
};

class ReportAbuseVerb {
public:
    char pad[0x78];
    DocumentHost* host;
    shared_ptr<Workspace> getWorkspace();
    void updateText(CCmdUIText* ui);
};

void ReportAbuseVerb::updateText(CCmdUIText* ui)
{
    if (getWorkspace().get() != 0)
    {
        DataModelLock lock(host->getDataModel());
        int mode = getWorkspace()->getRunState()->mode;
        if (mode != 1)
        {
            ui->SetText("");
        }
        else
        {
            char buf[32];
            sprintf(buf, "%.3gfps", getWorkspace()->stats->fps);
            ui->SetText(buf);
        }
    }
}
