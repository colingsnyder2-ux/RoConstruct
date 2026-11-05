// from server: 100% by nuck16
// roc 2009-12 005196e1  unit: boost::X::V?$function0::?$thread_data  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005196e1
//
// 005196e1  6a00                 push 0
// 005196e3  6a00                 push 0
// 005196e5  e88eb12d00           call 0x7f4878

// roc-flags: /O2 /GS- /EHsc /MD

void f()
{
    throw;
}
