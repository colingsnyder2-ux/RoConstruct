// from server: 30% by colin
extern "C" {
    __declspec(dllimport) void* __stdcall FindFirstFileA(const char*, void*);
    __declspec(dllimport) int __stdcall FindNextFileA(void*, void*);
    __declspec(dllimport) int __stdcall DeleteFileA(const char*);
    __declspec(dllimport) char* __stdcall PathAddBackslashA(char*);
    __declspec(dllimport) int __stdcall PathAppendA(char*, const char*);
    __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();
}

struct CPath {
    char path[260];
    CPath();
    ~CPath();
    void Append(const char*);
    operator const char*() const;
};

struct String {
    char* data;
    int size;
    int cap;
    String();
    ~String();
    void assign(const char*, int);
    void insert(int, const char*);
    void append(const char*);
    const char* c_str() const;
};

struct FindData {
    unsigned int dwFileAttributes;
    char cFileName[260];
};

struct Node {
    Node* next;
    Node* prev;
    char data[0x30];
};

struct List {
    Node* head;
    int size;
    List();
    ~List();
    void clear();
    void push_back(const char*);
};

struct ThreadLogManager {
    void* log;
    unsigned int threadID;
    String name;
    void* mainLogManager;
    List fastLogChannels;
    void* crashReporter;
    const char* crashExtention;
    const char* crashEventExtention;

    void getLogFileName(String* out);
    void cullLogs();
};

extern "C" void __stdcall PathAddBackslashA_wrap();
extern "C" void __stdcall PathAppendA_wrap();

void ThreadLogManager::cullLogs()
{
    CPath path;
    String fileName;
    String id;
    FindData findData;
    void* hFind;
    int result;
    Node* node;
    Node* next;
    List tempList;
    int i;

    this->getLogFileName(&fileName);

    hFind = FindFirstFileA(fileName.c_str(), &findData);
    if (hFind != (void*)-1) {
        do {
            if ((findData.dwFileAttributes & 0x10) == 0) {
                CPath filePath;
                filePath.Append(findData.cFileName);
                DeleteFileA(filePath);
            }
        } while (FindNextFileA(hFind, &findData));
    }

    tempList.clear();
    node = this->fastLogChannels.head;
    while (node != (Node*)&this->fastLogChannels) {
        next = node->next;
        tempList.push_back(node->data);
        node = next;
    }

    this->fastLogChannels.clear();

    for (i = 0; i < tempList.size; i++) {
        CPath filePath;
        filePath.Append(tempList.head->data);
        DeleteFileA(filePath);
        tempList.head = tempList.head->next;
    }

    tempList.clear();
}
