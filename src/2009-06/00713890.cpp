// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int __stdcall search(const char* s, int start, int n);
class C {
public:
    int pad;
    int num;
    int find(const char* s) const {
        if (num > 0) return search(s, 0, num);
        return -1;
    }
    bool contains(const char* s) const;
};
bool C::contains(const char* s) const { return find(s) != -1; }
