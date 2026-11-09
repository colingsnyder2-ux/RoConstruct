// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Settings { char pad[0xa0]; double value; };
Settings& settings();
double getValue_005c9440() { return settings().value; }
