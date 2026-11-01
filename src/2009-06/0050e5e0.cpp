// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct Result { int a, b, c, d; };
struct Holder { char pad[0xc8]; double time; };
class ExeObj {
public:
    Holder* getHolder();
    Result compute(int arg, double t);
    Result run(int arg);
};
Result ExeObj::run(int arg) { return compute(arg, getHolder()->time); }
}
