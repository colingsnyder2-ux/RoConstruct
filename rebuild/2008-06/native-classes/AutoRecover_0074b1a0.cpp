// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afxwin.h>
#include <mbstring.h>

// INFERRED: best-effort reconstruction, not verified byte-exact.
extern "C" int GetTextExtentX_raw(CDC* dc, char* s, int n);       // 0x00746ae0
extern "C" int GetTextExtentX_str(CDC* dc, const CString& s);     // 0x007469f0

struct XtpHyperlink {
    char pad[0x30];
    int nStart;   // +0x30
    int nLen;     // +0x34
};

struct XtpDrawCtx {
    char pad0[0x10];
    void* pItems;   // +0x10
    char pad1[0x10];
    CDC* pDC;       // +0x24
    int  nFlags;    // +0x28
};

typedef int (__thiscall *GetCountFn)(void*);
typedef XtpHyperlink* (__thiscall *GetAtFn)(void*, int);

extern "C" void __fastcall fn_0074b1a0(void* self, int unusedEdx, XtpDrawCtx* ctx, CString* pText,
                                       int startX, int y, int right, int bottom,
                                       int pos, int endPos, int textWidth)
{
    CDC* pDC = ctx->pDC;
    void* items = ctx->pItems;
    int flags = ctx->nFlags & 3;
    int curX = startX;
    int eax = right;

    if (flags & 2) {
        eax = right - textWidth;
        curX = eax;
        if (!(eax > startX)) curX = startX;
    } else if (flags & 1) {
        eax = (right - startX - textWidth) / 2 + startX;
        curX = eax;
        if (!(eax > startX)) curX = startX;
    } else {
        curX = startX;
    }
    int x = curX;
    int i = pos;

    int count = ((GetCountFn)(*(void***)items)[0xb8 / 4])(items);
    CString word;
    CString s1, s2;
    int flag = 0;

    CString tmp = *pText + " ";
    char* buf = tmp.GetBuffer(tmp.GetLength());
    int spaceW = GetTextExtentX_raw(pDC, " ", 1);

    if (!(pos > endPos)) {
        do {
            char c = buf[i++];
            if (!c) break;
            if (c != ' ' && c != '\t' && c != '\n') {
                word += c;
                continue;
            }
            if (word.IsEmpty())
                continue;
            if (flag) {
                CString sp;
                sp = " ";
                // INFERRED: virtual output call at DC vtable +0x70
                RECT r = { curX, y, right, bottom };
                pDC->DrawText(sp, &r, 0);
                curX += spaceW;
            }
            for (int k = 0; k < count; k++) {
                XtpHyperlink* h = ((GetAtFn)(*(void***)items)[0xbc / 4])(items, k);
                int st = h->nStart;
                if (st < 0 || st > pText->GetLength() - 1 || h->nLen <= 1 ||
                    h->nLen + st > pText->GetLength())
                    continue;
                int ok = 0;
                if (pos > st) {
                    CString pre = pText->Mid(st, pos - st);
                    if (_mbsspnp((const unsigned char*)(const char*)pre,
                                 (const unsigned char*)" ") == 0)
                        ok = 1;
                }
                if (st >= pos || h->nLen + st > endPos) {
                    if (!ok) continue;
                }
                CString link = pText->Mid(st, h->nLen);
                link.MakeLower();
                int found = word.Find(link, 0);
                if (found != -1 && st < i) {
                    CString before = word.Mid(0, word.GetLength() + (st - i) + 1);
                    if (!before.IsEmpty()) {
                        RECT r = { curX, y, right, bottom };
                        pDC->DrawText(before, &r, 0x8800);
                        curX += GetTextExtentX_str(pDC, before);
                    }
                    RECT r2 = { curX, y, right, bottom };
                    pDC->DrawText(link, &r2, 0x8000);
                    curX = x;
                    int rest = word.GetLength() + (st - i) + h->nLen + 1;
                    if (rest >= 0 && word.GetLength() - rest > 0) {
                        CString after = word.Mid(rest, word.GetLength() - rest);
                        if (!after.IsEmpty()) {
                            RECT r3 = { curX, y, right, bottom };
                            pDC->DrawText(after, &r3, 0x8800);
                            curX += GetTextExtentX_str(pDC, after);
                        }
                    }
                    word.Empty();
                }
            }
            RECT rw = { curX, y, right, bottom };
            pDC->DrawText(word, &rw, 0x8800);
            curX += GetTextExtentX_str(pDC, word);
            word.Empty();
            flag = 1;
        } while (i <= endPos);
    }
}
