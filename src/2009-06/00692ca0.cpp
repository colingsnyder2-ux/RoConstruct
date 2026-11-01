// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct once_flag { long v; };
template<typename F> void call_once(once_flag& flag, F f);
extern once_flag fl1, fl2, fl3, fl4, fl5, fl6, fl7;
void i1(); void i2(); void i3(); void i4(); void i5(); void i6(); void i7();
void g1(); void g2(); void g3(); void g4(); void g5(); void g6(); void g7();
void initAll()
{
    call_once(fl1, &i1); g1();
    call_once(fl2, &i2); g2();
    call_once(fl3, &i3); g3();
    call_once(fl4, &i4); g4();
    call_once(fl5, &i5); g5();
    call_once(fl6, &i6); g6();
    call_once(fl7, &i7); g7();
}
