// from server: 100% by auto
// roc 2007-03 0062c960  unit: seg_00620000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062c960
//
// 0062c960  e89bf3ffff           call 0x62bd00
// 0062c965  85c0                 test eax, eax
// 0062c967  7407                 je 0x62c970
// 0062c969  8bc8                 mov ecx, eax
// 0062c96b  e9c09c0600           jmp 0x696630
// 0062c970  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewhtml.cpp (function ?OnStatusTextChange@CHtmlView@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewhtml.cpp
