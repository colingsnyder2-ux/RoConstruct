// from server: 100% by colin
extern "C" {
    __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
    __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount, long* lpPreviousCount);
}

struct boost_thread_resource_error {
    void* m_handle;
    int m_pad[3];
    int m_count;
    void release();
};

void boost_thread_resource_error::release() {
    WaitForSingleObject(m_handle, 0xFFFFFFFF);
    m_count += 1;
    ReleaseSemaphore(m_handle, 1, 0);
}
