// from server: 100% by tajop
inline void* __cdecl operator new(unsigned int, void* p) { return p; }

struct LogEntryValue
{
    int data[80];
};

struct LogNode
{
    int key;
    int link;
    LogEntryValue value;
};

struct ThreadLogManager
{
    LogNode* buyNode(int key, int link, const LogEntryValue& value);
};

LogNode* ThreadLogManager::buyNode(int key, int link, const LogEntryValue& value)
{
    LogNode* node = (LogNode*)operator new(sizeof(LogNode));
    new (&node->key) int(key);
    new (&node->link) int(link);
    new (&node->value) LogEntryValue(value);
    return node;
}
