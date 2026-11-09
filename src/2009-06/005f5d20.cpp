// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct B0 { virtual ~B0(); char pad[0x10]; };
struct B1 { virtual ~B1(); };
struct B2 { virtual ~B2(); int x; };
struct B3 { virtual ~B3(); char pad[0x68]; };
struct DescribedBase { virtual ~DescribedBase(); };
struct __declspec(novtable) VB { virtual void vf(); char pad[0x10]; };
struct PartBase : B0, B1, B2, B3, DescribedBase, virtual VB { char pad[8]; };
struct X9c { virtual ~X9c(); char pad[8]; };
struct Xa8 { virtual ~Xa8(); char pad[0xc]; };
struct Xb8 : virtual VB { virtual ~Xb8(); virtual void own(); };
struct SeatBase : PartBase, X9c, Xa8, Xb8 { SeatBase(); virtual ~SeatBase(); char pad[0x250 - 0xc0]; };
class Seat : public SeatBase {
public:
    Seat();
    virtual ~Seat();
    virtual void vf();
};
Seat::Seat()
{
}
}
