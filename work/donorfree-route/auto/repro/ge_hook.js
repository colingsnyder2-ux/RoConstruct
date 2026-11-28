Interceptor.attach(ptr('0x73d9bc'), function(){ var c=this.context; var vt=c.edi.readPointer(); var t=c.edx; var m=Process.findModuleByAddress(t);
  var vm=Process.findModuleByAddress(vt);
  send({hook:1, edi:c.edi.toString(), vt:vt.toString(), vtmod: vm?vm.name+'+'+vt.sub(vm.base):null, target:t.toString(), tmod: m? m.name+'+'+t.sub(m.base):null, item:c.esi.toString(), itemvt:c.esi.readPointer().toString()}); });
