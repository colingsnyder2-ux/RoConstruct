// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 004423d0  unit: CDataModelPropGrid  size: 374 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004423d0
//
// 004423d0  6aff                 push -1
// 004423d2  68d7f27300           push 0x73f2d7
// 004423d7  64a100000000         mov eax, dword ptr fs:[0]
// 004423dd  50                   push eax
// Destructor: primary base at +0 (dtor 0x682930 out of line), secondary base at +0x17c
// (vtable only, inline dtor restoring 0x788344). Members: 0x180 (dtor 0x725720), a VS2005
// vector at 0x18c (_Myfirst/_Mylast/_Myend at 0x190/0x194/0x198), std::set/map trees at 0x19c,
// 0x1a8 (same erase 0x44efc0), 0x1b8 (erase 0x439dc0), 0x1c4 (erase 0x441c70): _Myhead at +4,
// _Mysize at +8, freed with operator delete 0x62fc62. All offsets from the target bytes.
#include <set>
#include <vector>

class CGridBase
{
public:
    virtual ~CGridBase();
    char pad_[0x17c - 4];
};

class IGridListener
{
public:
    virtual ~IGridListener() {}
    virtual void OnEvent() = 0;
};

class CMember180
{
public:
    ~CMember180();
    int pad_[3];
};

struct ItemA; struct ItemB; struct ItemC; struct ItemD;

class CDataModelPropGrid : public CGridBase, public IGridListener
{
public:
    virtual ~CDataModelPropGrid();
    virtual void OnEvent();
    CMember180 m_180;
    std::vector<ItemD*> m_18c;
    std::set<ItemC*> m_19c;
    std::set<ItemC*> m_1a8;
    int m_1b4;
    std::set<ItemB*> m_1b8;
    std::set<ItemA*> m_1c4;
};

CDataModelPropGrid::~CDataModelPropGrid()
{
}
