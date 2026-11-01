// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O1 /GS- /EHsc /MD /Oy- /hotpatch /fp:fast
#define FLT_EPSILON 1.192092896e-07F
int __stdcall FloatEqual(float a, float b)
{
    float d = a - b; return d >= -FLT_EPSILON && d <= FLT_EPSILON;
}
