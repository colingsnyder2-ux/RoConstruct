// Boundary between the MFC client and the recovered player engine.
#ifndef P6_ENGINE_H
#define P6_ENGINE_H
#ifdef __cplusplus
extern "C" {
#endif
int P6EngineReadable(const char* path);
int P6EngineOpen(void* window, const char* path, int width, int height);
int P6EngineFrame(void);
int P6EngineFrames(void);
void P6EngineReport(void);
int P6EngineCapture(const char* path);
void P6EngineResize(void);
void P6EngineClose(void);
#ifdef __cplusplus
}
#endif
#endif
