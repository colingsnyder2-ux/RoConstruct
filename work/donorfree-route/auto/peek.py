import frida,time,sys
pid=frida.spawn([r'run\RobloxQT.exe'],cwd='run'); s=frida.attach(pid)
sc=s.create_script("rpc.exports={r:function(a,n){return Array.from(new Uint32Array(ptr(a).readByteArray(n)))}}"); sc.load(); frida.resume(pid); time.sleep(8)
for a in sys.argv[1:]: print(a,[hex(x) for x in sc.exports_sync.r(int(a,16),16)])
frida.kill(pid)
