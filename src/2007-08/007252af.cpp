// from server: 80% by colin
extern int G1;
extern void *(__stdcall *G2)(void *);
extern void *(__stdcall *G3)(void *);
extern void (__stdcall *G4)(void *);

void func_007252af(void *a)
{
    int v = G1;
    if (v != 1) {
        G4(G3(G2(0)));
    } else {
        G4((void*)v);
    }
}
