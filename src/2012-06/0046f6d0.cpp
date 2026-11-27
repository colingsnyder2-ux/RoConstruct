// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct SD { int pad; int len; int alloc; int refs; };
struct S { char* p; void Fork(int); void Realloc(int); void pw2(int n); };
void S::pw2(int n) {
  SD* d = (SD*)p - 1;
  if (d->len > n) n = d->len;
  if (d->refs > 1) { Fork(n); }
  else if (d->alloc < n) {
    int nn = d->alloc;
    if (nn > 1024) nn += 1024; else nn *= 2;
    if (nn < n) nn = n;
    Realloc(nn);
  }
}
