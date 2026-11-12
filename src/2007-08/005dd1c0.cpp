// from server: 100% by EspClaude
// roc 2007-08 005dd1c0  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 276 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005dd1c0
// 005dd1c0  6aff                 push -1
// 005dd1c2  68c8a77500           push 0x75a7c8
// 005dd1c7  64a100000000         mov eax, dword ptr fs:[0]
// 005dd1cd  50                   push eax
// 005dd1ce  64892500000000       mov dword ptr fs:[0], esp
// 005dd1d5  83ec24               sub esp, 0x24
// 005dd1d8  53                   push ebx
// 005dd1d9  56                   push esi
// 005dd1da  8bf1                 mov esi, ecx
// 005dd1dc  6894000000           push 0x94
// 005dd1e1  8974240c             mov dword ptr [esp + 0xc], esi
// 005dd1e5  e80c2d0500           call 0x62fef6
// 005dd1ea  83c404               add esp, 4
// 005dd1ed  8944240c             mov dword ptr [esp + 0xc], eax
// 005dd1f1  33db                 xor ebx, ebx
// 005dd1f3  3bc3                 cmp eax, ebx
// 005dd1f5  895c2434             mov dword ptr [esp + 0x34], ebx
// 005dd1f9  7409                 je 0x5dd204
// 005dd1fb  8bc8                 mov ecx, eax
// 005dd1fd  e84e72fdff           call 0x5b4450
// 005dd202  eb02                 jmp 0x5dd206
// 005dd204  33c0                 xor eax, eax
// 005dd206  50                   push eax
// 005dd207  8bce                 mov ecx, esi
// 005dd209  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 005dd211  e84afeffff           call 0x5dd060
// 005dd216  c7069cc27b00         mov dword ptr [esi], 0x7bc29c
// 005dd21c  c7460490c27b00       mov dword ptr [esi + 4], 0x7bc290
// 005dd223  c7461088c27b00       mov dword ptr [esi + 0x10], 0x7bc288
// 005dd22a  c7461478c27b00       mov dword ptr [esi + 0x14], 0x7bc278
// 005dd231  c7462c68c27b00       mov dword ptr [esi + 0x2c], 0x7bc268
// 005dd238  c7464458c27b00       mov dword ptr [esi + 0x44], 0x7bc258
// 005dd23f  c7465c48c27b00       mov dword ptr [esi + 0x5c], 0x7bc248
// 005dd246  c7467438c27b00       mov dword ptr [esi + 0x74], 0x7bc238
// 005dd24d  c7868c00000028c27b00 mov dword ptr [esi + 0x8c], 0x7bc228
// 005dd257  c786e800000010c27b00 mov dword ptr [esi + 0xe8], 0x7bc210
// 005dd261  899efc000000         mov dword ptr [esi + 0xfc], ebx
// 005dd267  c744243401000000     mov dword ptr [esp + 0x34], 1
// 005dd26f  899e00010000         mov dword ptr [esi + 0x100], ebx
// 005dd275  899e08010000         mov dword ptr [esi + 0x108], ebx
// 005dd27b  899e0c010000         mov dword ptr [esi + 0x10c], ebx
// 005dd281  889e10010000         mov byte ptr [esi + 0x110], bl
// 005dd287  889e14010000         mov byte ptr [esi + 0x114], bl
// 005dd28d  b303                 mov bl, 3
// 005dd28f  6848c87b00           push 0x7bc848
// 005dd294  8d4c2414             lea ecx, [esp + 0x14]
// 005dd298  885c2438             mov byte ptr [esp + 0x38], bl
// 005dd29c  ff1598e67700         call dword ptr [0x77e698]
// 005dd2a2  8d442410             lea eax, [esp + 0x10]
// 005dd2a6  50                   push eax
// 005dd2a7  8bce                 mov ecx, esi
// 005dd2a9  c644243804           mov byte ptr [esp + 0x38], 4
// 005dd2ae  e83d49f6ff           call 0x541bf0
// 005dd2b3  8d4c2410             lea ecx, [esp + 0x10]
// 005dd2b7  885c2434             mov byte ptr [esp + 0x34], bl
// 005dd2bb  ff15ace67700         call dword ptr [0x77e6ac]
// 005dd2c1  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005dd2c5  8bc6                 mov eax, esi
// 005dd2c7  5e                   pop esi
// 005dd2c8  5b                   pop ebx
// 005dd2c9  64890d00000000       mov dword ptr fs:[0], ecx
// 005dd2d0  83c430               add esp, 0x30
// 005dd2d3  c3                   ret 
// RBX::VelocityMotor::VelocityMotor() : DescribedCreatable(new MotorJoint()) { setName("VelocityMotor"); }
// 2007-08 layout from the bytes: new MotorJoint is 0x94 bytes; the base
// (DescribedCreatable<VelocityMotor, JointInstance>) ends at 0xfc and has
// vfptrs at 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c,0xe8; hole (shared_ptr)
// at 0xfc; holeAncestorChanged (boost::signals::scoped_connection) at 0x104:
// con at 0x108, controlling_connection at 0x110, released at 0x114.
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

namespace RBX {
class Joint { public: virtual ~Joint(); };
class MotorJoint : public Joint {
public:
    MotorJoint();
    char data[0x90];
};

struct B00 { virtual void f00(); };
struct B04 { virtual void f04(); int d[2]; };
struct B10 { virtual void f10(); };
struct B14 { virtual void f14(); int d[5]; };
struct B2c { virtual void f2c(); int d[5]; };
struct B44 { virtual void f44(); int d[5]; };
struct B5c { virtual void f5c(); int d[5]; };
struct B74 { virtual void f74(); int d[5]; };
struct B8c { virtual void f8c(); int d[0x16]; };
struct Be8 { virtual void fe8(); int d[4]; };

class JointInstanceBase : public B00, public B04, public B10, public B14, public B2c,
                          public B44, public B5c, public B74, public B8c, public Be8 {
public:
    JointInstanceBase(Joint* joint);
    virtual ~JointInstanceBase();
    void setName(const std::string& name);
};

class Hole;
struct shared_count {
    void* pi_;
    shared_count() : pi_(0) {}
    ~shared_count();
};
struct HolePtr {
    Hole* px;
    shared_count pn;
    HolePtr() : px(0), pn() {}
};

struct less_than_comparable1 {};
struct equality_comparable1 {};
class connection : private less_than_comparable1, private equality_comparable1 {
public:
    connection() : con_px(0), con_pn(0), controlling_connection(false) {}
    ~connection();
    void* con_px;
    void* con_pn;
    bool controlling_connection;
};
class scoped_connection : public connection {
public:
    scoped_connection() : connection(), released(false) {}
    ~scoped_connection();
    bool released;
};

class VelocityMotor : public JointInstanceBase {
    HolePtr hole;
    scoped_connection holeAncestorChanged;
public:
    VelocityMotor();
    virtual ~VelocityMotor();
};

VelocityMotor::VelocityMotor()
    : JointInstanceBase(new MotorJoint())
{
    setName("VelocityMotor");
}
}
