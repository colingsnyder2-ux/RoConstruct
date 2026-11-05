// from server: 100% by Intel
struct CScriptEditor {
    void sub_460120(int);
};

extern "C" void* __stdcall sub_45D230(int, int);
extern "C" int __fastcall sub_45C460(void*);

void CScriptEditor::sub_460120(int a2) {
    int* p = (int*)a2;
    int* obj = (int*)*p;
    void* r = sub_45D230(0, 1);
    int ok = sub_45C460(r);
    int flag = ok != 0;
    ((void (__thiscall*)(void*, int))obj[1])(p, flag);
}
