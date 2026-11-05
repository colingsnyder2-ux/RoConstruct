// from server: 84% by EspClaude
// true extent: 0x20 bytes (server extent 0x2c swallows next fn 004b3930); real class FactoryProduct<Network::Player,Instance,&sPlayer>
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
    virtual ~Instance();
};
class CharacterAppearance : public Instance {
public:
    ~CharacterAppearance();
};
CharacterAppearance::~CharacterAppearance() {}
}
