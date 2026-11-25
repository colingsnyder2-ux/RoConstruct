// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// zlib-1.2.3 inflate.c: updatewindow
#include <string.h>

// INFERRED: file-local mirrors of z_stream / inflate_state with the original member offsets.
struct Local_007a8290_Stream;
typedef void* (__cdecl *Local_007a8290_Alloc)(void* opaque, unsigned items, unsigned size);

struct Local_007a8290_State {
    int mode;               // 0x00
    int last;               // 0x04
    int wrap;               // 0x08
    int havedict;           // 0x0c
    int flags;              // 0x10
    unsigned dmax;          // 0x14
    unsigned long check;    // 0x18
    unsigned long total;    // 0x1c
    void* head;             // 0x20
    unsigned wbits;         // 0x24
    unsigned wsize;         // 0x28
    unsigned whave;         // 0x2c
    unsigned write;         // 0x30
    unsigned char* window;  // 0x34
};

struct Local_007a8290_Stream {
    const unsigned char* next_in;   // 0x00
    unsigned avail_in;              // 0x04
    unsigned long total_in;         // 0x08
    unsigned char* next_out;        // 0x0c
    unsigned avail_out;             // 0x10
    unsigned long total_out;        // 0x14
    char* msg;                      // 0x18
    Local_007a8290_State* state;    // 0x1c
    Local_007a8290_Alloc zalloc;    // 0x20
    void* zfree;                    // 0x24
    void* opaque;                   // 0x28
};

// INFERRED: original uses a custom register convention (strm=ebx, out=eax) from
// the optimizer; expressed here as a plain cdecl function under the fixed name.
extern "C" int fn_007a8290(Local_007a8290_Stream* strm, unsigned out)
{
    Local_007a8290_State* state = strm->state;
    unsigned copy, dist;

    if (state->window == 0) {
        state->window = (unsigned char*)strm->zalloc(strm->opaque, 1U << state->wbits, 1);
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
    }
    else {
        dist = state->wsize - state->write;
        if (dist > copy) dist = copy;
        memcpy(state->window + state->write, strm->next_out - copy, dist);
        copy -= dist;
        if (copy) {
            memcpy(state->window, strm->next_out - copy, copy);
            state->write = copy;
            state->whave = state->wsize;
        }
        else {
            state->write += dist;
            if (state->write == state->wsize) state->write = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}
