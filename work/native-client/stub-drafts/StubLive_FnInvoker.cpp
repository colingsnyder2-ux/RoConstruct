// native-flags: /O2 /GS- /MD /DNDEBUG
// 005a19e0 (15 B, unnamed): a boost::function invoker -- buffer = { function pointer, bound argument }:
//   mov eax,[esp+4] / mov ecx,[eax+4] / mov [esp+4],ecx / mov edx,[eax] / jmp edx
// i.e. invoke(buf) == buf.fn(buf.arg). It stayed a `mov eax,0 / ret 8` stub: Stats::TypedStatsItem<double>::update
// (005a4020) called its getter through it, got the stack shifted by 8 and "returned" into the middle of
// CRobloxReportView::CStatsItemRecord::CValueItem (func_00456770+0x53) -> crash drawing the stats view (TTD trace).
// INFERRED analog: void return so the callee's eax / st0 result passes through untouched.
typedef void (__cdecl* roc_fn1)(void*);
void __cdecl roc_invoke_005a19e0(void** buf)
{
    ((roc_fn1)buf[0])(buf[1]);
}
