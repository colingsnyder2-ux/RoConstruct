// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { class ios_base { public: __declspec(dllimport) int setf(int, int); }; }
std::ios_base& myhex(std::ios_base& s) { s.setf(0x800, 0xe00); return s; }
