// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: all types are opaque; layout of locals guessed from the frame offsets.
extern "C" {
void __fastcall fn_005410b0(void* self, int unusedEdx);
void __fastcall fn_0053f200(void* self, int unusedEdx, int key);
int __fastcall fn_005409e0(void* self, int unusedEdx, void* out, void* key);
int __fastcall fn_005409b0(void* self, int unusedEdx, void* a1);
int __fastcall fn_00540ed0(void* self, int unusedEdx, int a1);
int fn_006a0920(int a1);
int __fastcall fn_00540390(void* self, int unusedEdx);
void __fastcall fn_00540e60(void* self, int unusedEdx, int src);
int __fastcall fn_00540830(void* self, int unusedEdx, void* key, void* val);
int __fastcall fn_00540e40(void* self, int unusedEdx, int a1);
int __fastcall fn_00540370(void* self, int unusedEdx);
int __fastcall fn_00540e80(void* self, int unusedEdx);
int __fastcall fn_00540e90(void* self, int unusedEdx);
void __fastcall fn_00540e20(void* self, int unusedEdx);
int __fastcall fn_0053f720(void* self, int unusedEdx, int a1);

int __fastcall fn_0053f340(char* self, int unusedEdx, int arg)
{
    int set10[3];
    int it18[3];
    int end2c[3];
    int key24[5];

    fn_005410b0(set10, 0);
    fn_0053f200(key24, 0, arg);
    fn_005409e0(self + 8, 0, it18, key24);
    int endIt = fn_005409b0(self + 8, 0, end2c);
    if ((unsigned char)fn_00540ed0(it18, 0, endIt)) {
        int mem = fn_006a0920(0x24);
        int made = mem ? fn_00540390((void*)mem, 0) : 0;
        fn_00540e60(set10, 0, made);
        int slot = fn_00540830(self + 8, 0, key24, set10);
        fn_00540e40((void*)slot, 0, 0);
    } else {
        int p = fn_00540e90(it18, 0);
        fn_00540e40(set10, 0, p + 0xc);
    }
    fn_00540370(key24, 0);
    int q = fn_00540e80(set10, 0);
    int r = fn_0053f720((void*)q, 0, arg);
    fn_00540e20(set10, 0);
    return r;
}
}
