// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// zlib 1.2.3 inflate.c (ZLIB_WINAPI build). The 2008 exe has a second, VS2005-built copy of zlib.
#include <string.h>

typedef unsigned char Bytef;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct gz_header {
    int text;
    uLong time;
    int xflags;
    int os;
    Bytef* extra;
    uInt extra_len;
    uInt extra_max;
    Bytef* name;
    uInt name_max;
    Bytef* comment;
    uInt comment_max;
    int hcrc;
    int done;
};

struct z_stream {
    Bytef* next_in;
    uInt avail_in;
    uLong total_in;
    Bytef* next_out;
    uInt avail_out;
    uLong total_out;
    const char* msg;
    struct inflate_state* state;
    void* (__stdcall* zalloc)(void*, uInt, uInt);
    void (__stdcall* zfree)(void*, void*);
    void* opaque;
    int data_type;
    uLong adler;
    uLong reserved;
};

struct code {
    unsigned char op;
    unsigned char bits;
    unsigned short val;
};

enum { HEAD, FLAGS, TIME, OS, EXLEN, EXTRA, NAME, COMMENT, HCRC, DICTID, DICT, TYPE, TYPEDO,
       STORED, COPY, TABLE, LENLENS, CODELENS, LEN, LENEXT, DIST, DISTEXT, MATCH, LIT, CHECK,
       LENGTH, DONE, BAD, MEM, SYNC };

struct inflate_state {
    int mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned dmax;
    unsigned long check;
    unsigned long total;
    gz_header* head;
    unsigned wbits;
    unsigned wsize;
    unsigned whave;
    unsigned write;
    unsigned char* window;
    unsigned long hold;
    unsigned bits;
    unsigned length;
    unsigned offset;
    unsigned extra;
    const code* lencode;
    const code* distcode;
    unsigned lenbits;
    unsigned distbits;
    unsigned ncode;
    unsigned nlen;
    unsigned ndist;
    unsigned have;
    code* next;
    unsigned short lens[320];
    unsigned short work[288];
    code codes[1444];
};

extern "C" {
unsigned long __stdcall crc32(unsigned long crc, const Bytef* buf, uInt len);
unsigned long __stdcall adler32(unsigned long adler, const Bytef* buf, uInt len);
int inflate_table(int type, unsigned short* lens, unsigned codes, code** table, unsigned* bits,
                  unsigned short* work);
void inflate_fast(z_stream* strm, unsigned start);
// INFERRED: fixed tables from inffixed.h, at the addresses used in the disassembly
extern const code g_00874078[512];
extern const code g_00874878[32];
}

enum { CODES, LENS, DISTS };

static int updatewindow(z_stream* strm, unsigned out)
{
    inflate_state* state = strm->state;
    unsigned copy, dist;

    if (state->window == 0) {
        state->window = (unsigned char*)(*strm->zalloc)(strm->opaque, 1U << state->wbits, 1);
        if (state->window == 0) return 1;
    }
    if (state->wsize == 0) {
        state->wsize = 1U << state->wbits;
        state->write = 0;
        state->whave = 0;
    }
    copy = out - strm->avail_out;
    if (copy >= state->wsize) {
        memcpy(state->window, strm->next_out - state->wsize, state->wsize);
        state->write = 0;
        state->whave = state->wsize;
    } else {
        dist = state->wsize - state->write;
        if (dist > copy) dist = copy;
        memcpy(state->window + state->write, strm->next_out - copy, dist);
        copy -= dist;
        if (copy) {
            memcpy(state->window, strm->next_out - copy, copy);
            state->write = copy;
            state->whave = state->wsize;
        } else {
            state->write += dist;
            if (state->write == state->wsize) state->write = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}

#define UPDATE(check, buf, len) (state->flags ? crc32(check, buf, len) : adler32(check, buf, len))
#define CRC2(check, word) \
    do { \
        hbuf[0] = (unsigned char)(word); \
        hbuf[1] = (unsigned char)((word) >> 8); \
        check = crc32(check, hbuf, 2); \
    } while (0)
#define CRC4(check, word) \
    do { \
        hbuf[0] = (unsigned char)(word); \
        hbuf[1] = (unsigned char)((word) >> 8); \
        hbuf[2] = (unsigned char)((word) >> 16); \
        hbuf[3] = (unsigned char)((word) >> 24); \
        check = crc32(check, hbuf, 4); \
    } while (0)
#define LOAD() \
    do { put = strm->next_out; left = strm->avail_out; next = strm->next_in; have = strm->avail_in; \
         hold = state->hold; bits = state->bits; } while (0)
#define RESTORE() \
    do { strm->next_out = put; strm->avail_out = left; strm->next_in = next; strm->avail_in = have; \
         state->hold = hold; state->bits = bits; } while (0)
#define INITBITS() do { hold = 0; bits = 0; } while (0)
#define PULLBYTE() \
    do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0)
#define NEEDBITS(n) do { while (bits < (unsigned)(n)) PULLBYTE(); } while (0)
#define BITS(n) ((unsigned)hold & ((1U << (n)) - 1))
#define DROPBITS(n) do { hold >>= (n); bits -= (unsigned)(n); } while (0)
#define BYTEBITS() do { hold >>= bits & 7; bits -= bits & 7; } while (0)
#define REVERSE(q) \
    ((((q) >> 24) & 0xff) + (((q) >> 8) & 0xff00) + (((q) & 0xff00) << 8) + (((q) & 0xff) << 24))

extern "C" int __stdcall inflate(z_stream* strm, int flush)
{
    inflate_state* state;
    unsigned char* next;
    unsigned char* put;
    unsigned have, left;
    unsigned long hold;
    unsigned bits;
    unsigned in, out;
    unsigned copy;
    unsigned char* from;
    code thisc;
    code last;
    unsigned len;
    int ret;
    unsigned char hbuf[4];
    static const unsigned short order[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

    if (strm == 0 || strm->state == 0 || strm->next_out == 0 ||
        (strm->next_in == 0 && strm->avail_in != 0))
        return -2;

    state = strm->state;
    if (state->mode == TYPE) state->mode = TYPEDO;
    LOAD();
    in = have;
    out = left;
    ret = 0;
    for (;;)
        switch (state->mode) {
        case HEAD:
            if (state->wrap == 0) {
                state->mode = TYPEDO;
                break;
            }
            NEEDBITS(16);
            if ((state->wrap & 2) && hold == 0x8b1f) {
                state->check = crc32(0L, 0, 0);
                CRC2(state->check, hold);
                INITBITS();
                state->mode = FLAGS;
                break;
            }
            state->flags = 0;
            if (state->head != 0) state->head->done = -1;
            if (!(state->wrap & 1) || ((BITS(8) << 8) + (hold >> 8)) % 31) {
                strm->msg = "incorrect header check";
                state->mode = BAD;
                break;
            }
            if (BITS(4) != 8) {
                strm->msg = "unknown compression method";
                state->mode = BAD;
                break;
            }
            DROPBITS(4);
            len = BITS(4) + 8;
            if (len > state->wbits) {
                strm->msg = "invalid window size";
                state->mode = BAD;
                break;
            }
            state->dmax = 1U << len;
            strm->adler = state->check = adler32(0L, 0, 0);
            state->mode = hold & 0x200 ? DICTID : TYPE;
            INITBITS();
            break;
        case FLAGS:
            NEEDBITS(16);
            state->flags = (int)(hold);
            if ((state->flags & 0xff) != 8) {
                strm->msg = "unknown compression method";
                state->mode = BAD;
                break;
            }
            if (state->flags & 0xe000) {
                strm->msg = "unknown header flags set";
                state->mode = BAD;
                break;
            }
            if (state->head != 0) state->head->text = (int)((hold >> 8) & 1);
            if (state->flags & 0x0200) CRC2(state->check, hold);
            INITBITS();
            state->mode = TIME;
        case TIME:
            NEEDBITS(32);
            if (state->head != 0) state->head->time = hold;
            if (state->flags & 0x0200) CRC4(state->check, hold);
            INITBITS();
            state->mode = OS;
        case OS:
            NEEDBITS(16);
            if (state->head != 0) {
                state->head->xflags = (int)(hold & 0xff);
                state->head->os = (int)(hold >> 8);
            }
            if (state->flags & 0x0200) CRC2(state->check, hold);
            INITBITS();
            state->mode = EXLEN;
        case EXLEN:
            if (state->flags & 0x0400) {
                NEEDBITS(16);
                state->length = (unsigned)(hold);
                if (state->head != 0) state->head->extra_len = (unsigned)hold;
                if (state->flags & 0x0200) CRC2(state->check, hold);
                INITBITS();
            } else if (state->head != 0)
                state->head->extra = 0;
            state->mode = EXTRA;
        case EXTRA:
            if (state->flags & 0x0400) {
                copy = state->length;
                if (copy > have) copy = have;
                if (copy) {
                    if (state->head != 0 && state->head->extra != 0 &&
                        (len = state->head->extra_len - state->length) < state->head->extra_max) {
                        memcpy(state->head->extra + len, next,
                               len + copy > state->head->extra_max ? state->head->extra_max - len : copy);
                    }
                    if (state->flags & 0x0200) state->check = crc32(state->check, next, copy);
                    have -= copy;
                    next += copy;
                    state->length -= copy;
                }
                if (state->length) goto inf_leave;
            }
            state->length = 0;
            state->mode = NAME;
        case NAME:
            if (state->flags & 0x0800) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                    if (state->head != 0 && state->head->name != 0 && state->length < state->head->name_max)
                        state->head->name[state->length++] = len;
                } while (len && copy < have);
                if (state->flags & 0x0200) state->check = crc32(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            } else if (state->head != 0)
                state->head->name = 0;
            state->length = 0;
            state->mode = COMMENT;
        case COMMENT:
            if (state->flags & 0x1000) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                    if (state->head != 0 && state->head->comment != 0 && state->length < state->head->comment_max)
                        state->head->comment[state->length++] = len;
                } while (len && copy < have);
                if (state->flags & 0x0200) state->check = crc32(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            } else if (state->head != 0)
                state->head->comment = 0;
            state->mode = HCRC;
        case HCRC:
            if (state->flags & 0x0200) {
                NEEDBITS(16);
                if (hold != (state->check & 0xffff)) {
                    strm->msg = "header crc mismatch";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            if (state->head != 0) {
                state->head->hcrc = (int)((state->flags >> 9) & 1);
                state->head->done = 1;
            }
            strm->adler = state->check = crc32(0L, 0, 0);
            state->mode = TYPE;
            break;
        case DICTID:
            NEEDBITS(32);
            strm->adler = state->check = REVERSE(hold);
            INITBITS();
            state->mode = DICT;
        case DICT:
            if (state->havedict == 0) {
                RESTORE();
                return 2;
            }
            strm->adler = state->check = adler32(0L, 0, 0);
            state->mode = TYPE;
        case TYPE:
            if (flush == 5) goto inf_leave;
        case TYPEDO:
            if (state->last) {
                BYTEBITS();
                state->mode = CHECK;
                break;
            }
            NEEDBITS(3);
            state->last = BITS(1);
            DROPBITS(1);
            switch (BITS(2)) {
            case 0:
                state->mode = STORED;
                break;
            case 1:
                state->lencode = g_00874078;
                state->lenbits = 9;
                state->distcode = g_00874878;
                state->distbits = 5;
                state->mode = LEN;
                break;
            case 2:
                state->mode = TABLE;
                break;
            case 3:
                strm->msg = "invalid block type";
                state->mode = BAD;
            }
            DROPBITS(2);
            break;
        case STORED:
            BYTEBITS();
            NEEDBITS(32);
            if ((hold & 0xffff) != ((hold >> 16) ^ 0xffff)) {
                strm->msg = "invalid stored block lengths";
                state->mode = BAD;
                break;
            }
            state->length = (unsigned)hold & 0xffff;
            INITBITS();
            state->mode = COPY;
        case COPY:
            copy = state->length;
            if (copy) {
                if (copy > have) copy = have;
                if (copy > left) copy = left;
                if (copy == 0) goto inf_leave;
                memcpy(put, next, copy);
                have -= copy;
                next += copy;
                left -= copy;
                put += copy;
                state->length -= copy;
                break;
            }
            state->mode = TYPE;
            break;
        case TABLE:
            NEEDBITS(14);
            state->nlen = BITS(5) + 257;
            DROPBITS(5);
            state->ndist = BITS(5) + 1;
            DROPBITS(5);
            state->ncode = BITS(4) + 4;
            DROPBITS(4);
            if (state->nlen > 286 || state->ndist > 30) {
                strm->msg = "too many length or distance symbols";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = LENLENS;
        case LENLENS:
            while (state->have < state->ncode) {
                NEEDBITS(3);
                state->lens[order[state->have++]] = (unsigned short)BITS(3);
                DROPBITS(3);
            }
            while (state->have < 19) state->lens[order[state->have++]] = 0;
            state->next = state->codes;
            state->lencode = (const code*)(state->next);
            state->lenbits = 7;
            ret = inflate_table(CODES, state->lens, 19, &(state->next), &(state->lenbits), state->work);
            if (ret) {
                strm->msg = "invalid code lengths set";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = CODELENS;
        case CODELENS:
            while (state->have < state->nlen + state->ndist) {
                for (;;) {
                    thisc = state->lencode[BITS(state->lenbits)];
                    if ((unsigned)(thisc.bits) <= bits) break;
                    PULLBYTE();
                }
                if (thisc.val < 16) {
                    NEEDBITS(thisc.bits);
                    DROPBITS(thisc.bits);
                    state->lens[state->have++] = thisc.val;
                } else {
                    if (thisc.val == 16) {
                        NEEDBITS(thisc.bits + 2);
                        DROPBITS(thisc.bits);
                        if (state->have == 0) {
                            strm->msg = "invalid bit length repeat";
                            state->mode = BAD;
                            break;
                        }
                        len = state->lens[state->have - 1];
                        copy = 3 + BITS(2);
                        DROPBITS(2);
                    } else if (thisc.val == 17) {
                        NEEDBITS(thisc.bits + 3);
                        DROPBITS(thisc.bits);
                        len = 0;
                        copy = 3 + BITS(3);
                        DROPBITS(3);
                    } else {
                        NEEDBITS(thisc.bits + 7);
                        DROPBITS(thisc.bits);
                        len = 0;
                        copy = 11 + BITS(7);
                        DROPBITS(7);
                    }
                    if (state->have + copy > state->nlen + state->ndist) {
                        strm->msg = "invalid bit length repeat";
                        state->mode = BAD;
                        break;
                    }
                    while (copy--) state->lens[state->have++] = (unsigned short)len;
                }
            }
            if (state->mode == BAD) break;
            state->next = state->codes;
            state->lencode = (const code*)(state->next);
            state->lenbits = 9;
            ret = inflate_table(LENS, state->lens, state->nlen, &(state->next), &(state->lenbits), state->work);
            if (ret) {
                strm->msg = "invalid literal/lengths set";
                state->mode = BAD;
                break;
            }
            state->distcode = (const code*)(state->next);
            state->distbits = 6;
            ret = inflate_table(DISTS, state->lens + state->nlen, state->ndist, &(state->next),
                                &(state->distbits), state->work);
            if (ret) {
                strm->msg = "invalid distances set";
                state->mode = BAD;
                break;
            }
            state->mode = LEN;
        case LEN:
            if (have >= 6 && left >= 258) {
                RESTORE();
                inflate_fast(strm, out);
                LOAD();
                break;
            }
            for (;;) {
                thisc = state->lencode[BITS(state->lenbits)];
                if ((unsigned)(thisc.bits) <= bits) break;
                PULLBYTE();
            }
            if (thisc.op && (thisc.op & 0xf0) == 0) {
                last = thisc;
                for (;;) {
                    thisc = state->lencode[last.val + (BITS(last.bits + last.op) >> last.bits)];
                    if ((unsigned)(last.bits + thisc.bits) <= bits) break;
                    PULLBYTE();
                }
                DROPBITS(last.bits);
            }
            DROPBITS(thisc.bits);
            state->length = (unsigned)thisc.val;
            if ((int)(thisc.op) == 0) {
                state->mode = LIT;
                break;
            }
            if (thisc.op & 32) {
                state->mode = TYPE;
                break;
            }
            if (thisc.op & 64) {
                strm->msg = "invalid literal/length code";
                state->mode = BAD;
                break;
            }
            state->extra = (unsigned)(thisc.op) & 15;
            state->mode = LENEXT;
        case LENEXT:
            if (state->extra) {
                NEEDBITS(state->extra);
                state->length += BITS(state->extra);
                DROPBITS(state->extra);
            }
            state->mode = DIST;
        case DIST:
            for (;;) {
                thisc = state->distcode[BITS(state->distbits)];
                if ((unsigned)(thisc.bits) <= bits) break;
                PULLBYTE();
            }
            if ((thisc.op & 0xf0) == 0) {
                last = thisc;
                for (;;) {
                    thisc = state->distcode[last.val + (BITS(last.bits + last.op) >> last.bits)];
                    if ((unsigned)(last.bits + thisc.bits) <= bits) break;
                    PULLBYTE();
                }
                DROPBITS(last.bits);
            }
            DROPBITS(thisc.bits);
            if (thisc.op & 64) {
                strm->msg = "invalid distance code";
                state->mode = BAD;
                break;
            }
            state->offset = (unsigned)thisc.val;
            state->extra = (unsigned)(thisc.op) & 15;
            state->mode = DISTEXT;
        case DISTEXT:
            if (state->extra) {
                NEEDBITS(state->extra);
                state->offset += BITS(state->extra);
                DROPBITS(state->extra);
            }
            state->mode = MATCH;
        case MATCH:
            if (left == 0) goto inf_leave;
            copy = out - left;
            if (state->offset > copy) {
                copy = state->offset - copy;
                if (copy > state->whave) {
                    strm->msg = "invalid distance too far back";
                    state->mode = BAD;
                    break;
                }
                if (copy > state->write) {
                    copy -= state->write;
                    from = state->window + (state->wsize - copy);
                } else
                    from = state->window + (state->write - copy);
                if (copy > state->length) copy = state->length;
            } else {
                from = put - state->offset;
                copy = state->length;
            }
            if (copy > left) copy = left;
            left -= copy;
            state->length -= copy;
            do {
                *put++ = *from++;
            } while (--copy);
            if (state->length == 0) state->mode = LEN;
            break;
        case LIT:
            if (left == 0) goto inf_leave;
            *put++ = (unsigned char)(state->length);
            left--;
            state->mode = LEN;
            break;
        case CHECK:
            if (state->wrap) {
                NEEDBITS(32);
                out -= left;
                strm->total_out += out;
                state->total += out;
                if (out) strm->adler = state->check = UPDATE(state->check, put - out, out);
                out = left;
                if ((state->flags ? hold : REVERSE(hold)) != state->check) {
                    strm->msg = "incorrect data check";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            state->mode = LENGTH;
        case LENGTH:
            if (state->wrap && state->flags) {
                NEEDBITS(32);
                if (hold != (state->total & 0xffffffffUL)) {
                    strm->msg = "incorrect length check";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            state->mode = DONE;
        case DONE:
            ret = 1;
            goto inf_leave;
        case BAD:
            ret = -3;
            goto inf_leave;
        case MEM:
            return -4;
        case SYNC:
        default:
            return -2;
        }

inf_leave:
    RESTORE();
    if (state->wsize || (state->mode < BAD && out != strm->avail_out && state->mode < CHECK))
        if (updatewindow(strm, out)) {
            state->mode = MEM;
            return -4;
        }
    in -= strm->avail_in;
    out -= strm->avail_out;
    strm->total_in += in;
    strm->total_out += out;
    state->total += out;
    if (state->wrap && out) strm->adler = state->check = UPDATE(state->check, strm->next_out - out, out);
    strm->data_type = state->bits + (state->last ? 64 : 0) + (state->mode == TYPE ? 128 : 0);
    if (((in == 0 && out == 0) || flush == 4) && ret == 0) ret = -5;
    return ret;
}
