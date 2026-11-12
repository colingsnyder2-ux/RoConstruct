// from server: 98% by EspClaude
// from server: 49% by colin
// roc 2007-08 004598a0  unit: CRobloxWnd  size: 767 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004598a0
//
// 004598a0  6aff                 push -1
// 004598a2  6888217400           push 0x742188
// 004598a7  64a100000000         mov eax, dword ptr fs:[0]
// 004598ad  50                   push eax
// 004598ae  83ec58               sub esp, 0x58
// 004598b1  56                   push esi
// 004598b2  57                   push edi
// 004598b3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004598b8  33c4                 xor eax, esp
// 004598ba  50                   push eax
// 004598bb  8d442464             lea eax, [esp + 0x64]
// 004598bf  64a300000000         mov dword ptr fs:[0], eax
// 004598c5  8bf1                 mov esi, ecx
// 004598c7  8d4c2414             lea ecx, [esp + 0x14]
// 004598cb  c744241478c08b00     mov dword ptr [esp + 0x14], 0x8bc078
// 004598d3  c644241800           mov byte ptr [esp + 0x18], 0
// 004598d8  e8933ffcff           call 0x41d870
// 004598dd  dd05a8347900         fld qword ptr [0x7934a8]
// 004598e3  dc9680000000         fcom qword ptr [esi + 0x80]
// 004598e9  dfe0                 fnstsw ax
// 004598eb  f6c444               test ah, 0x44
// 004598ee  7a2a                 jp 0x45991a
// 004598f0  807c241800           cmp byte ptr [esp + 0x18], 0
// 004598f5  ddd8                 fstp st(0)
// 004598f7  0f8490020000         je 0x459b8d
// 004598fd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00459901  50                   push eax
// 00459902  ff15f8d27700         call dword ptr [0x77d2f8]
// 00459908  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0045990c  64890d00000000       mov dword ptr fs:[0], ecx
// 00459913  59                   pop ecx
// 00459914  5f                   pop edi
// 00459915  5e                   pop esi
// 00459916  83c464               add esp, 0x64
// 00459919  c3                   ret 
// 0045991a  807c241800           cmp byte ptr [esp + 0x18], 0
// 0045991f  dd8680000000         fld qword ptr [esi + 0x80]
// 00459925  dd5c241c             fstp qword ptr [esp + 0x1c]
// 00459929  dd9e80000000         fstp qword ptr [esi + 0x80]
// 0045992f  740b                 je 0x45993c
// 00459931  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00459935  51                   push ecx
// 00459936  ff15f8d27700         call dword ptr [0x77d2f8]
// 0045993c  83bea000000000       cmp dword ptr [esi + 0xa0], 0
// 00459943  0f8444020000         je 0x459b8d
// 00459949  837e6800             cmp dword ptr [esi + 0x68], 0
// 0045994d  0f843a020000         je 0x459b8d
// 00459953  8b5668               mov edx, dword ptr [esi + 0x68]
// 00459956  83ec08               sub esp, 8
// 00459959  8bcc                 mov ecx, esp
// 0045995b  8911                 mov dword ptr [ecx], edx
// 0045995d  8b466c               mov eax, dword ptr [esi + 0x6c]
// 00459960  85c0                 test eax, eax
// 00459962  8964241c             mov dword ptr [esp + 0x1c], esp
// 00459966  894104               mov dword ptr [ecx + 4], eax
// 00459969  740c                 je 0x459977
// 0045996b  83c004               add eax, 4
// 0045996e  b901000000           mov ecx, 1
// 00459973  f00fc108             lock xadd dword ptr [eax], ecx
// 00459977  8d4c2430             lea ecx, [esp + 0x30]
// 0045997b  e8d03bfbff           call 0x40d550
// 00459980  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00459986  8b11                 mov edx, dword ptr [ecx]
// 00459988  8b4208               mov eax, dword ptr [edx + 8]
// 0045998b  c744246c00000000     mov dword ptr [esp + 0x6c], 0
// 00459993  ffd0                 call eax
// 00459995  d95c2410             fstp dword ptr [esp + 0x10]
// 00459999  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 0045999f  8b11                 mov edx, dword ptr [ecx]
// 004599a1  8b420c               mov eax, dword ptr [edx + 0xc]
// 004599a4  ffd0                 call eax
// 004599a6  d95c240c             fstp dword ptr [esp + 0xc]
// 004599aa  dd0518367900         fld qword ptr [0x793618]
// 004599b0  dd44241c             fld qword ptr [esp + 0x1c]
// 004599b4  d8d1                 fcom st(1)
// 004599b6  dfe0                 fnstsw ax
// 004599b8  ddd9                 fstp st(1)
// 004599ba  f6c405               test ah, 5
// 004599bd  7a1a                 jp 0x4599d9
// 004599bf  ddd8                 fstp st(0)
// 004599c1  d9442410             fld dword ptr [esp + 0x10]
// 004599c5  dd0510367900         fld qword ptr [0x793610]
// 004599cb  dcc9                 fmul st(1), st(0)
// 004599cd  d9c9                 fxch st(1)
// 004599cf  d95c2410             fstp dword ptr [esp + 0x10]
// 004599d3  d84c240c             fmul dword ptr [esp + 0xc]
// 004599d7  eb29                 jmp 0x459a02
// 004599d9  dc1d08367900         fcomp qword ptr [0x793608]
// 004599df  dfe0                 fnstsw ax
// 004599e1  f6c441               test ah, 0x41
// 004599e4  7520                 jne 0x459a06
// 004599e6  d9442410             fld dword ptr [esp + 0x10]
// 004599ea  dd0500367900         fld qword ptr [0x793600]
// 004599f0  dcc9                 fmul st(1), st(0)
// 004599f2  d9e8                 fld1 
// 004599f4  dcc2                 fadd st(2), st(0)
// 004599f6  d9ca                 fxch st(2)
// 004599f8  d95c2410             fstp dword ptr [esp + 0x10]
// 004599fc  d84c240c             fmul dword ptr [esp + 0xc]
// 00459a00  dec1                 faddp st(1)
// 00459a02  d95c240c             fstp dword ptr [esp + 0xc]
// 00459a06  e85556fbff           call 0x40f060
// 00459a0b  d980ec000000         fld dword ptr [eax + 0xec]
// 00459a11  d95c2414             fstp dword ptr [esp + 0x14]
// 00459a15  d9442414             fld dword ptr [esp + 0x14]
// 00459a19  d9442410             fld dword ptr [esp + 0x10]
// 00459a1d  ded9                 fcompp 
// 00459a1f  dfe0                 fnstsw ax
// 00459a21  f6c441               test ah, 0x41
// 00459a24  8d442414             lea eax, [esp + 0x14]
// 00459a28  7404                 je 0x459a2e
// 00459a2a  8d442410             lea eax, [esp + 0x10]
// 00459a2e  d900                 fld dword ptr [eax]
// 00459a30  d95c2410             fstp dword ptr [esp + 0x10]
// 00459a34  e82756fbff           call 0x40f060
// 00459a39  d980e8000000         fld dword ptr [eax + 0xe8]
// 00459a3f  d95c2414             fstp dword ptr [esp + 0x14]
// 00459a43  d9442410             fld dword ptr [esp + 0x10]
// 00459a47  d9442414             fld dword ptr [esp + 0x14]
// 00459a4b  ded9                 fcompp 
// 00459a4d  dfe0                 fnstsw ax
// 00459a4f  f6c441               test ah, 0x41
// 00459a52  8d442414             lea eax, [esp + 0x14]
// 00459a56  7404                 je 0x459a5c
// 00459a58  8d442410             lea eax, [esp + 0x10]
// 00459a5c  d900                 fld dword ptr [eax]
// 00459a5e  d95c2410             fstp dword ptr [esp + 0x10]
// 00459a62  e8f955fbff           call 0x40f060
// 00459a67  d980f4000000         fld dword ptr [eax + 0xf4]
// 00459a6d  d95c2414             fstp dword ptr [esp + 0x14]
// 00459a71  d9442414             fld dword ptr [esp + 0x14]
// 00459a75  d944240c             fld dword ptr [esp + 0xc]
// 00459a79  ded9                 fcompp 
// 00459a7b  dfe0                 fnstsw ax
// 00459a7d  f6c441               test ah, 0x41
// 00459a80  8d442414             lea eax, [esp + 0x14]
// 00459a84  7404                 je 0x459a8a
// 00459a86  8d44240c             lea eax, [esp + 0xc]
// 00459a8a  d900                 fld dword ptr [eax]
// 00459a8c  d95c240c             fstp dword ptr [esp + 0xc]
// 00459a90  e8cb55fbff           call 0x40f060
// 00459a95  d980f0000000         fld dword ptr [eax + 0xf0]
// 00459a9b  d95c2414             fstp dword ptr [esp + 0x14]
// 00459a9f  d944240c             fld dword ptr [esp + 0xc]
// 00459aa3  d9442414             fld dword ptr [esp + 0x14]
// 00459aa7  ded9                 fcompp 
// 00459aa9  dfe0                 fnstsw ax
// 00459aab  f6c441               test ah, 0x41
// 00459aae  8d442414             lea eax, [esp + 0x14]
// 00459ab2  7404                 je 0x459ab8
// 00459ab4  8d44240c             lea eax, [esp + 0xc]
// 00459ab8  d900                 fld dword ptr [eax]
// 00459aba  8b4668               mov eax, dword ptr [esi + 0x68]
// 00459abd  83b88801000000       cmp dword ptr [eax + 0x188], 0
// 00459ac4  d95c240c             fstp dword ptr [esp + 0xc]
// 00459ac8  0f84ae000000         je 0x459b7c
// 00459ace  8b8088010000         mov eax, dword ptr [eax + 0x188]
// 00459ad4  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00459ada  8d8828020000         lea ecx, [eax + 0x228]
// 00459ae0  8b4204               mov eax, dword ptr [edx + 4]
// 00459ae3  ffd0                 call eax
// 00459ae5  85c0                 test eax, eax
// 00459ae7  0f848f000000         je 0x459b7c
// 00459aed  8b4668               mov eax, dword ptr [esi + 0x68]
// 00459af0  8b8088010000         mov eax, dword ptr [eax + 0x188]
// 00459af6  8d8828020000         lea ecx, [eax + 0x228]
// 00459afc  8b01                 mov eax, dword ptr [ecx]
// 00459afe  8d542434             lea edx, [esp + 0x34]
// 00459b02  52                   push edx
// 00459b03  8b5004               mov edx, dword ptr [eax + 4]
// 00459b06  ffd2                 call edx
// 00459b08  8bc8                 mov ecx, eax
// 00459b0a  e801e4ffff           call 0x457f10
// 00459b0f  8b4668               mov eax, dword ptr [esi + 0x68]
// 00459b12  8b8088010000         mov eax, dword ptr [eax + 0x188]
// 00459b18  8d8828020000         lea ecx, [eax + 0x228]
// 00459b1e  8b01                 mov eax, dword ptr [ecx]
// 00459b20  8b5004               mov edx, dword ptr [eax + 4]
// 00459b23  ffd2                 call edx
// 00459b25  0580010000           add eax, 0x180
// 00459b2a  50                   push eax
// 00459b2b  8d442420             lea eax, [esp + 0x20]
// 00459b2f  50                   push eax
// 00459b30  8d4c2460             lea ecx, [esp + 0x60]
// 00459b34  e857e1ffff           call 0x457c90
// 00459b39  8bc8                 mov ecx, eax
// 00459b3b  e8a0e7ffff           call 0x4582e0
// 00459b40  d95c2414             fstp dword ptr [esp + 0x14]
// 00459b44  8bb6a0000000         mov esi, dword ptr [esi + 0xa0]
// 00459b4a  d9442414             fld dword ptr [esp + 0x14]
// 00459b4e  8b3e                 mov edi, dword ptr [esi]
// 00459b50  51                   push ecx
// 00459b51  d91c24               fstp dword ptr [esp]
// 00459b54  83c710               add edi, 0x10
// 00459b57  e80455fbff           call 0x40f060
// 00459b5c  8bc8                 mov ecx, eax
// 00459b5e  e86db2feff           call 0x444dd0
// 00459b63  d9442410             fld dword ptr [esp + 0x10]
// 00459b67  8b17                 mov edx, dword ptr [edi]
// 00459b69  8bce                 mov ecx, esi
// 00459b6b  50                   push eax
// 00459b6c  83ec08               sub esp, 8
// 00459b6f  d95c2404             fstp dword ptr [esp + 4]
// 00459b73  d9442420             fld dword ptr [esp + 0x20]
// 00459b77  d91c24               fstp dword ptr [esp]
// 00459b7a  ffd2                 call edx
// 00459b7c  8d4c2428             lea ecx, [esp + 0x28]
// 00459b80  c744246cffffffff     mov dword ptr [esp + 0x6c], 0xffffffff
// 00459b88  e813fa0f00           call 0x5595a0
// 00459b8d  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00459b91  64890d00000000       mov dword ptr fs:[0], ecx
// 00459b98  59                   pop ecx
// 00459b99  5f                   pop edi
// 00459b9a  5e                   pop esi
// 00459b9b  83c464               add esp, 0x64
// 00459b9e  c3                   ret 
// roc-cl: 50727
#include <intrin.h>
#include <algorithm>

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);

class Mutex {
public:
    int criticalSection;
};

class scoped_lock {
public:
    explicit scoped_lock(Mutex& m) : m_mutex(m), m_locked(false) { lock(); }
    ~scoped_lock() { if (m_locked) unlock(); }
    void lock();
    void unlock()
    {
        LeaveCriticalSection(&m_mutex.criticalSection);
        m_locked = false;
    }
private:
    Mutex& m_mutex;
    bool m_locked;
};

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator bool() const { return px != 0; }
    T* px;
    detail::shared_count pn;
};
}

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3 operator-(const Vector3& v) const;
    float length() const;
};
class Matrix3 {
public:
    float elt[3][3];
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
};
}

namespace RBX {
class Camera {
public:
    char pad_00[0x180];
    G3D::Vector3 focusPosition;
    G3D::CoordinateFrame getCameraCoordinateFrame() const;
};

class ICameraOwner {
public:
    virtual ~ICameraOwner();
    virtual Camera* getCamera() = 0;
};

class Instance {
public:
    virtual ~Instance();
    char pad_04[0x228 - 4];
};

class Workspace : public Instance, public ICameraOwner {
};

class DataModel {
public:
    char pad_00[0x188];
    Workspace* workspace;
    Workspace* getWorkspace() const { return workspace; }

    class scoped_write_request {
    public:
        scoped_write_request(boost::shared_ptr<DataModel> dataModel);
        ~scoped_write_request();
        int data[3];
    };
};

class GameSettings {
public:
    static GameSettings& singleton();
    char pad_00[0xe8];
    float minZoomX;
    float maxZoomX;
    float minZoomY;
    float maxZoomY;
    float getMinZoomX() const { return minZoomX; }
    float getMaxZoomX() const { return maxZoomX; }
    float getMinZoomY() const { return minZoomY; }
    float getMaxZoomY() const { return maxZoomY; }
    bool getFlag() const;
};
}

class IZoomView {
public:
    virtual ~IZoomView();
    virtual void unused04();
    virtual float getZoomX();
    virtual float getZoomY();
    virtual void setZoom(float x, float y, bool flag, float distance);
};

class CRobloxWnd {
public:
    char pad_00[0x68];
    boost::shared_ptr<RBX::DataModel> dataModel;
    char pad_70[0x80 - 0x70];
    double wheelDelta;
    char pad_88[0xa0 - 0x88];
    IZoomView* view;

    static Mutex wheelMutex;
    void processWheel();
};

void CRobloxWnd::processWheel()
{
    double delta;
    {
        scoped_lock lock(wheelMutex);
        if (wheelDelta == 666.0)
            return;
        delta = wheelDelta;
        wheelDelta = 666.0;
    }
    if (!view)
        return;
    if (!dataModel)
        return;

    RBX::DataModel::scoped_write_request request(dataModel);

    float x = view->getZoomX();
    float y = view->getZoomY();
    if (delta < -0.01) {
        x *= 0.8f;
        y *= 0.8f;
    } else if (delta > 0.002) {
        x = x * 1.05f + 1.0f;
        y = y * 1.05f + 1.0f;
    }
    x = std::min(x, RBX::GameSettings::singleton().getMaxZoomX());
    x = std::max(x, RBX::GameSettings::singleton().getMinZoomX());
    y = std::min(y, RBX::GameSettings::singleton().getMaxZoomY());
    y = std::max(y, RBX::GameSettings::singleton().getMinZoomY());

    if (dataModel->getWorkspace() && dataModel->getWorkspace()->getCamera()) {
        G3D::CoordinateFrame cameraFrame = dataModel->getWorkspace()->getCamera()->getCameraCoordinateFrame();
        float distance = (cameraFrame.translation - dataModel->getWorkspace()->getCamera()->focusPosition).length();
        IZoomView* zoomView = view;
        zoomView->setZoom(x, y, RBX::GameSettings::singleton().getFlag(), distance);
    }
}
