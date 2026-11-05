// from server: 48% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ChatLine {
    char pad0[16];
    void* field10;
    void* field14;
    void* field18;
};

ChatLine* __stdcall ChatLine_CopyConstruct(ChatLine* this_, const ChatLine* src) {
    this_->pad0[0] = src->pad0[0];
    this_->pad0[1] = src->pad0[1];
    this_->pad0[2] = src->pad0[2];
    this_->pad0[3] = src->pad0[3];
    this_->pad0[4] = src->pad0[4];
    this_->pad0[5] = src->pad0[5];
    this_->pad0[6] = src->pad0[6];
    this_->pad0[7] = src->pad0[7];
    this_->pad0[8] = src->pad0[8];
    this_->pad0[9] = src->pad0[9];
    this_->pad0[10] = src->pad0[10];
    this_->pad0[11] = src->pad0[11];
    this_->pad0[12] = src->pad0[12];
    this_->pad0[13] = src->pad0[13];
    this_->pad0[14] = src->pad0[14];
    this_->pad0[15] = src->pad0[15];

    this_->field10 = src->field10;
    if (src->field10) {
        _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(static_cast<char*>(src->field10) + 8), 1);
    }

    this_->field14 = src->field14;

    this_->field18 = src->field18;
    if (src->field18) {
        _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(static_cast<char*>(src->field18) + 8), 1);
    }

    return this_;
}
