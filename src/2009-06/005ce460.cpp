// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SP { void* p; void* c; SP(const SP&); ~SP(); };
struct COW { SP read() const; };
class Instance {
public:
    char pad[0x4c];
    COW children;
    SP getChildren2();
};
SP Instance::getChildren2()
{
    return children.read();
}
