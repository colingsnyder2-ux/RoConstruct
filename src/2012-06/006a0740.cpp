// from server: 33% by 41k
struct VFriendService {
    void EventDesc(void* param1, void* param2);
};

extern "C" void func_006a0290(void* param1, void* param2);
extern "C" void func_0069c830(void* param1, void* param2);

void VFriendService::EventDesc(void* param1, void* param2) {
    void* this_ptr = this;
    void* local_1c = param2;
    void* local_18 = param1;

    func_006a0290(this_ptr, local_1c);
    if (local_1c) {
        local_1c = (char*)local_1c + 0x1c;
    } else {
        local_1c = 0;
    }

    func_0069c830(this_ptr, local_1c);
}
