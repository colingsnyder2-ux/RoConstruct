// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
struct IA { virtual ~IA(); };
struct IB { virtual ~IB(); char pad[0x10]; };
struct IC { virtual ~IC(); };
struct ID { virtual ~ID(); char pad[0x60]; };
struct IE { virtual ~IE(); };
struct IF { virtual ~IF(); };
class PVAdornment : public IA, public IB, public IC, public ID, public IE, public IF {
public:
    PVAdornment(const char* name);
};
class SelectionBox : public PVAdornment {
public:
    SelectionBox();
    virtual ~SelectionBox();
};
SelectionBox::SelectionBox() : PVAdornment("SelectionBox") {}
}