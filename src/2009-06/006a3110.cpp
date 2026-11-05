// from server: 100% by atomic.potato
struct CMap {
    void* GetValueAt(void* key);
};

void* __cdecl sub_6A3110(void* key, CMap* map) {
    return map->GetValueAt(&key);
}
