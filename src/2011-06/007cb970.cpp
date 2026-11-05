// from server: 43% by colin
struct ChatLine {
    char pad[8];
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* p);
extern "C" int __stdcall type_info_equal(const void* a, const void* b);

struct ChatLineHolder {
    ChatLine* ptr;
};

struct ChatLineFactory {
    static void Create(ChatLineHolder* out, ChatLineHolder* src, int op);
};

void ChatLineFactory::Create(ChatLineHolder* out, ChatLineHolder* src, int op) {
    if (op == 0) {
        ChatLine* s = src->ptr;
        ChatLine* n = (ChatLine*)operator_new(0x38);
        if (n) {
            out->ptr = n;
        } else {
            out->ptr = 0;
        }
    } else if (op == 1) {
        out->ptr = src->ptr;
        src->ptr = 0;
    } else if (op == 2) {
        ChatLine* s = src->ptr;
        if (s) {
            operator_delete(s);
        }
        src->ptr = 0;
    } else if (op == 3) {
        if (type_info_equal(out->ptr, (const void*)0xc93360)) {
            out->ptr = src->ptr;
        } else {
            out->ptr = 0;
        }
    } else {
        out->ptr = (ChatLine*)0xc93360;
        ((char*)out)[4] = 0;
        ((char*)out)[5] = 0;
    }
}
