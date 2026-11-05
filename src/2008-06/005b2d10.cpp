// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

struct __declspec(novtable) VB0 { virtual void a0(); };
struct __declspec(novtable) VB1 : virtual VB0 { virtual void b0(); };
struct V4 { ~V4() {} };

struct P00 { virtual void m00(); unsigned long pad[3]; };
struct P10 { virtual void m10(); };
struct P14 { virtual void m14(); unsigned long pad[2]; };
struct P20 { virtual void m20(); };
struct P24 { virtual void m24(); unsigned long pad[7]; };
struct P44 { virtual void m44(); unsigned long pad[7]; };
struct P64 { virtual void m64(); unsigned long pad[7]; };
struct P84 { virtual void m84(); unsigned long pad[7]; };
struct PA4 { virtual void mA4(); unsigned long pad[7]; };
struct PC4 { virtual void mC4(); unsigned long pad[26]; };
struct P130 { virtual void m130(); unsigned long pad[3]; };
struct P140 { virtual void m140(); unsigned long pad[3]; };

struct Mid : P00, P10, P14, P20, P24, P44, P64, P84, PA4, PC4, P130, P140, virtual VB0, virtual VB1, virtual V4
{
    Mid();
    ~Mid();
    unsigned long pad[28];
};

struct Acc : Mid
{
    Acc();
    virtual void a0();
    virtual void b0();
    void setName(const std::string&);
};

struct Hat : Acc
{
    Hat();
    virtual void a0();
    virtual void b0();
};

Hat::Hat()
{
    std::string s("Hat");
    setName(s);
}
