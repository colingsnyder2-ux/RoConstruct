// from server: 100% by colin
// from server: 79% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern float* _FInf;
extern float* _FNan;
extern float* _FSnan;

int f(float value)
{
    return value == *_FInf ||
           value == -*_FInf ||
           value == *_FNan ||
           value == *_FSnan;
}
