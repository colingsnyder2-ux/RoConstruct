// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
void __cdecl sortThree(float& a, float& b, float& c)
{
    if (b < a && &b != &a) {
        float temp = b;
        b = a;
        a = temp;
    }
    if (c < b && &c != &b) {
        float temp = c;
        c = b;
        b = temp;
    }
    if (b < a && &b != &a) {
        float temp = b;
        b = a;
        a = temp;
    }
}
