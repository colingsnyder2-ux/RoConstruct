// from server: 90% by atomic.potato
struct ChatLine {
    char pad0[8];
    void* field8;
    char padC[0x59 - 0xC];
    char field59;
    void func(void*);
};

extern "C" void __cdecl sub_982114(void*);

void ChatLine::func(void* arg) {
    ChatLine* p = (ChatLine*)arg;
    ChatLine* esi = p;
    if (p->field59 == 0) {
        do {
            this->func(esi->field8);
            esi = *(ChatLine**)esi;
            sub_982114(p);
            p = esi;
        } while (esi->field59 == 0);
    }
}
