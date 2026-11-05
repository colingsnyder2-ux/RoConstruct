// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Settings { char pad[0x150]; double value; };
Settings& settings();
double getValue_005c9420() { return settings().value; }
