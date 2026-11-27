// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
struct V3 { float x,y,z; };
V3* __fastcall f(V3 *d, const V3 *s){ d->x=s->x; d->y=s->y; d->z=s->z; return d; }
