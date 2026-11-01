// from server: 100% by EspClaude
// roc 2009-06 006f3dc0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Connection;
class Signal {
public:
    void visit(void (*f)(Connection*));
};
class Humanoid {
public:
    void setSit(bool value);
    char pad[0x254];
    Signal* seatSignal;
};
class INamed { public: virtual const char* name() const = 0; };
class HitTestFilter { public: virtual int filter() const = 0; };
namespace HUMAN {
void disconnectSeat(Connection* c);
class HumanoidState : public INamed, public HitTestFilter {
public:
    virtual ~HumanoidState();
    Humanoid* getHumanoid() const;
protected:
    Humanoid* humanoid;
};
template<class B, const char* const& s>
class Named : public B {
public:
    const char* name() const { return s; }
};
extern const char* const sSeated;
class Seated : public Named<HumanoidState, sSeated> {
public:
    ~Seated();
    int filter() const;
};
Seated::~Seated()
{
    getHumanoid()->setSit(false);
    Signal*& r = getHumanoid()->seatSignal;
    if (r)
        r->visit(&disconnectSeat);
}
}
}
