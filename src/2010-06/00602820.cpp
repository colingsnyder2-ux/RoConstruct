// from server: 50% by atomic.potato
struct RBX_HeartbeatInstance {
    char pad[0x4c];
    RBX_HeartbeatInstance* field_4c;
    RBX_HeartbeatInstance* find_root(RBX_HeartbeatInstance* node);
};

RBX_HeartbeatInstance* RBX_HeartbeatInstance::find_root(RBX_HeartbeatInstance* node) {
    RBX_HeartbeatInstance* esi = node->field_4c;
    RBX_HeartbeatInstance* edi = esi;
    RBX_HeartbeatInstance* ecx = edi->field_4c;
    RBX_HeartbeatInstance* edx = ecx->field_4c;
    while (edx != 0) {
        edi = ecx;
        ecx = edx;
        edx = ecx->field_4c;
    }
    if (esi != edi) {
        do {
            RBX_HeartbeatInstance* eax = esi;
            esi = eax->field_4c;
        } while (esi != edi);
    }
    return edi;
}
