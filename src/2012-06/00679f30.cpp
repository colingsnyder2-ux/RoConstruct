// from server: 100% by Xemicl
// roc 2012-06 00679f30  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00679f30
//
// 00679f30  6aff                 push -1
// 00679f32  6808c8ac00           push 0xacc808
// 00679f37  64a100000000         mov eax, dword ptr fs:[0]
// 00679f3d  50                   push eax
// 00679f3e  64892500000000       mov dword ptr fs:[0], esp
// 00679f45  83ec10               sub esp, 0x10
// 00679f48  8d442408             lea eax, [esp + 8]
// 00679f4c  56                   push esi
// 00679f4d  50                   push eax
// 00679f4e  e88d1fdcff           call 0x43bee0
// 00679f53  8b00                 mov eax, dword ptr [eax]
// 00679f55  8b502c               mov edx, dword ptr [eax + 0x2c]
// 00679f58  8d4c2408             lea ecx, [esp + 8]
// 00679f5c  51                   push ecx
// 00679f5d  52                   push edx
// 00679f5e  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00679f66  e875a72f00           call 0x9746e0
// 00679f6b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00679f6f  83c40c               add esp, 0xc
// 00679f72  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00679f7a  85f6                 test esi, esi
// 00679f7c  742a                 je 0x679fa8
// 00679f7e  8d4604               lea eax, [esi + 4]
// 00679f81  83c9ff               or ecx, 0xffffffff
// 00679f84  f00fc108             lock xadd dword ptr [eax], ecx
// 00679f88  751e                 jne 0x679fa8
// 00679f8a  8b16                 mov edx, dword ptr [esi]
// 00679f8c  8b4204               mov eax, dword ptr [edx + 4]
// 00679f8f  8bce                 mov ecx, esi
// 00679f91  ffd0                 call eax
// 00679f93  8d4e08               lea ecx, [esi + 8]
// 00679f96  83caff               or edx, 0xffffffff
// 00679f99  f00fc111             lock xadd dword ptr [ecx], edx
// 00679f9d  7509                 jne 0x679fa8
// 00679f9f  8b06                 mov eax, dword ptr [esi]
// 00679fa1  8b5008               mov edx, dword ptr [eax + 8]
// 00679fa4  8bce                 mov ecx, esi
// 00679fa6  ffd2                 call edx
// 00679fa8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00679fac  dd442404             fld qword ptr [esp + 4]
// 00679fb0  5e                   pop esi
// 00679fb1  64890d00000000       mov dword ptr fs:[0], ecx
// 00679fb8  83c41c               add esp, 0x1c
// 00679fbb  c3                   ret 
// copied from an identical function in another client (function ?getValue@RBX@@YANXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base
{
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
private:
    long use_count_;
    long weak_count_;
};

template <class T>
class shared_ptr
{
public:
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
private:
    T* px;
    sp_counted_base* pn;
};

namespace RBX {
struct Settings
{
    char pad[0x2c];
    int handle;
};

shared_ptr<Settings> getSettings();
bool queryValue(int handle, double& value);

double getValue()
{
    double value;
    queryValue(getSettings()->handle, value);
    return value;
}
}