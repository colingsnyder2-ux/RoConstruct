// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeB0 { virtual ~ExeB0(); int a[4]; };
struct ExeB1 { virtual ~ExeB1(); };
struct ExeB2 { virtual ~ExeB2(); int x; };
struct ExeB3 { virtual ~ExeB3(); };
class Instance : public ExeB0, public ExeB1, public ExeB2, public ExeB3 {
public:
    char exePad[0x8c - 0x24];
    virtual ~Instance();
};
class TouchTransmitterBase : public Instance {
public:
    TouchTransmitterBase(const char* name);
};
class TouchTransmitter : public TouchTransmitterBase {
    struct Pair { void* a; void* b; Pair() : a(0), b(0) {} } pair;
public:
    TouchTransmitter();
    ~TouchTransmitter();
};
TouchTransmitter::TouchTransmitter() : TouchTransmitterBase("TouchTransmitter") {}
}
