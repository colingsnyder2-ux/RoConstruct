# Inactive Boost exception provider

Scoped alternate derived from Crouton Alpha Free draft packets 302/305. The
base destructor is allowed to inline while derived destructors are not. Five
original bodies match code/data in one independently built object: 00568430,
00568450, 00568420, 00406be0, 00568410. Two leaf direct-call checks pass.

The RunService ctor/dtor EH graphs advance from 79 to 88 events and stop at
boost::thread_exception scalar deleting destructor. This is inactive candidate
work; no linked ownership, full call identity, ABI, runtime or server credit.
Do not select alongside existing Boost providers. Original packet remains in
durable draft storage.
