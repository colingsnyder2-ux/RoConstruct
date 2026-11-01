// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 00649310  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 469 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00649310
//
// 00649310  51                   push ecx
// 00649311  56                   push esi
// 00649312  8bf1                 mov esi, ecx
// 00649314  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0064931a  8b4804               mov ecx, dword ptr [eax + 4]
// 0064931d  57                   push edi
// 0064931e  8dbe94000000         lea edi, [esi + 0x94]
// 00649324  51                   push ecx
// 00649325  8bcf                 mov ecx, edi
// 00649327  e804e4e9ff           call 0x4e7730
// 0064932c  8b4718               mov eax, dword ptr [edi + 0x18]
// 0064932f  894004               mov dword ptr [eax + 4], eax
// 00649332  8b4718               mov eax, dword ptr [edi + 0x18]
// 00649335  c7471c00000000       mov dword ptr [edi + 0x1c], 0
// 0064933c  8900                 mov dword ptr [eax], eax
// 0064933e  8b7f18               mov edi, dword ptr [edi + 0x18]
// 00649341  8bce                 mov ecx, esi
// 00649343  897f08               mov dword ptr [edi + 8], edi
// 00649346  e8058ff8ff           call 0x5d2250
// 0064934b  83ec1c               sub esp, 0x1c
// 0064934e  8bcc                 mov ecx, esp
// 00649350  89642424             mov dword ptr [esp + 0x24], esp
// 00649354  68e8ec8d00           push 0x8dece8
// 00649359  ff15b4e48900         call dword ptr [0x89e4b4]
// 0064935f  6a01                 push 1
// 00649361  8bce                 mov ecx, esi
// 00649363  e858fcffff           call 0x648fc0
// 00649368  83ec1c               sub esp, 0x1c
// 0064936b  8bcc                 mov ecx, esp
// 0064936d  89642424             mov dword ptr [esp + 0x24], esp
// 00649371  68d4ec8d00           push 0x8decd4
// 00649376  ff15b4e48900         call dword ptr [0x89e4b4]
// 0064937c  6a02                 push 2
// 0064937e  8bce                 mov ecx, esi
// 00649380  e83bfcffff           call 0x648fc0
// 00649385  83ec1c               sub esp, 0x1c
// 00649388  8bcc                 mov ecx, esp
// 0064938a  89642424             mov dword ptr [esp + 0x24], esp
// 0064938e  68bcec8d00           push 0x8decbc
// 00649393  ff15b4e48900         call dword ptr [0x89e4b4]
// 00649399  6a03                 push 3
// 0064939b  8bce                 mov ecx, esi
// 0064939d  e81efcffff           call 0x648fc0
// 006493a2  83ec1c               sub esp, 0x1c
// 006493a5  8bcc                 mov ecx, esp
// 006493a7  89642424             mov dword ptr [esp + 0x24], esp
// 006493ab  68a8ec8d00           push 0x8deca8
// 006493b0  ff15b4e48900         call dword ptr [0x89e4b4]
// 006493b6  6a04                 push 4
// 006493b8  8bce                 mov ecx, esi
// 006493ba  e801fcffff           call 0x648fc0
// 006493bf  83ec1c               sub esp, 0x1c
// 006493c2  8bcc                 mov ecx, esp
// 006493c4  89642424             mov dword ptr [esp + 0x24], esp
// 006493c8  6890ec8d00           push 0x8dec90
// 006493cd  ff15b4e48900         call dword ptr [0x89e4b4]
// 006493d3  6a05                 push 5
// 006493d5  8bce                 mov ecx, esi
// 006493d7  e8e4fbffff           call 0x648fc0
// 006493dc  83ec1c               sub esp, 0x1c
// 006493df  8bcc                 mov ecx, esp
// 006493e1  89642424             mov dword ptr [esp + 0x24], esp
// 006493e5  686cec8d00           push 0x8dec6c
// 006493ea  ff15b4e48900         call dword ptr [0x89e4b4]
// 006493f0  6a06                 push 6
// 006493f2  8bce                 mov ecx, esi
// 006493f4  e8c7fbffff           call 0x648fc0
// 006493f9  83ec1c               sub esp, 0x1c
// 006493fc  8bcc                 mov ecx, esp
// 006493fe  89642424             mov dword ptr [esp + 0x24], esp
// 00649402  6858ec8d00           push 0x8dec58
// 00649407  ff15b4e48900         call dword ptr [0x89e4b4]
// 0064940d  6a07                 push 7
// 0064940f  8bce                 mov ecx, esi
// 00649411  e8aafbffff           call 0x648fc0
// 00649416  83ec1c               sub esp, 0x1c
// 00649419  8bcc                 mov ecx, esp
// 0064941b  89642424             mov dword ptr [esp + 0x24], esp
// 0064941f  6838ec8d00           push 0x8dec38
// 00649424  ff15b4e48900         call dword ptr [0x89e4b4]
// 0064942a  6a08                 push 8
// 0064942c  8bce                 mov ecx, esi
// 0064942e  e88dfbffff           call 0x648fc0
// 00649433  83ec1c               sub esp, 0x1c
// 00649436  8bcc                 mov ecx, esp
// 00649438  89642424             mov dword ptr [esp + 0x24], esp
// 0064943c  6828ec8d00           push 0x8dec28
// 00649441  ff15b4e48900         call dword ptr [0x89e4b4]
// 00649447  6a09                 push 9
// 00649449  8bce                 mov ecx, esi
// 0064944b  e870fbffff           call 0x648fc0
// 00649450  83ec1c               sub esp, 0x1c
// 00649453  8bcc                 mov ecx, esp
// 00649455  89642424             mov dword ptr [esp + 0x24], esp
// 00649459  6814ec8d00           push 0x8dec14
// 0064945e  ff15b4e48900         call dword ptr [0x89e4b4]
// 00649464  6a0a                 push 0xa
// 00649466  8bce                 mov ecx, esi
// 00649468  e853fbffff           call 0x648fc0
// 0064946d  83ec1c               sub esp, 0x1c
// 00649470  8bcc                 mov ecx, esp
// 00649472  89642424             mov dword ptr [esp + 0x24], esp
// 00649476  6800ec8d00           push 0x8dec00
// 0064947b  ff15b4e48900         call dword ptr [0x89e4b4]
// 00649481  6a0b                 push 0xb
// 00649483  8bce                 mov ecx, esi
// 00649485  e836fbffff           call 0x648fc0
// 0064948a  83ec1c               sub esp, 0x1c
// 0064948d  8bcc                 mov ecx, esp
// 0064948f  89642424             mov dword ptr [esp + 0x24], esp
// 00649493  68e8eb8d00           push 0x8debe8
// 00649498  ff15b4e48900         call dword ptr [0x89e4b4]
// 0064949e  6a0c                 push 0xc
// 006494a0  8bce                 mov ecx, esi
// 006494a2  e819fbffff           call 0x648fc0
// 006494a7  83ec1c               sub esp, 0x1c
// 006494aa  8bcc                 mov ecx, esp
// 006494ac  89642424             mov dword ptr [esp + 0x24], esp
// 006494b0  68d4eb8d00           push 0x8debd4
// 006494b5  ff15b4e48900         call dword ptr [0x89e4b4]
// 006494bb  6a0d                 push 0xd
// 006494bd  8bce                 mov ecx, esi
// 006494bf  e8fcfaffff           call 0x648fc0
// 006494c4  83ec1c               sub esp, 0x1c
// 006494c7  8bcc                 mov ecx, esp
// 006494c9  89642424             mov dword ptr [esp + 0x24], esp
// 006494cd  68c0eb8d00           push 0x8debc0
// 006494d2  ff15b4e48900         call dword ptr [0x89e4b4]
// 006494d8  6a0e                 push 0xe
// 006494da  8bce                 mov ecx, esi
// 006494dc  e8dffaffff           call 0x648fc0
// 006494e1  5f                   pop edi
// 006494e2  5e                   pop esi
// 006494e3  59                   pop ecx
// 006494e4  c3                   ret 

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <string>
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
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    shared_ptr() : px(0), pn() {}
};

namespace RBX {
class Sound;

class StockSound {
public:
    char pad[0x94];
    std::map<int, shared_ptr<Sound> > sounds;
    void removeAllChildren();
    void addSound(int id, std::string path);
    void loadSounds();
};

void StockSound::loadSounds()
{
    sounds.clear();
    removeAllChildren();
    addSound(1, "Sounds\\bass.wav");
    addSound(2, "Sounds\\collide.wav");
    addSound(3, "Sounds\\glassbreak.wav");
    addSound(4, "Sounds\\switch.wav");
    addSound(5, "Sounds\\clickfast.wav");
    addSound(6, "Sounds\\Rubber band sling shot.wav");
    addSound(7, "Sounds\\pageturn.wav");
    addSound(8, "Sounds\\electronicpingshort.wav");
    addSound(9, "Sounds\\snap.wav");
    addSound(10, "Sounds\\splat.wav");
    addSound(11, "Sounds\\SWITCH3.wav");
    addSound(12, "Sounds\\flashbulb.wav");
    addSound(13, "Sounds\\swoosh.wav");
    addSound(14, "Sounds\\victory.wav");
}
}
