// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct RunService {
    void step();
    void onEvent(void* source, int ev);
};
void RunService::onEvent(void* source, int ev) {
    if (source) step();
}
