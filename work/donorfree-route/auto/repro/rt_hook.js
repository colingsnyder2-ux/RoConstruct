['0x486950','0x451d10','0x511b20','0x511c40','0x52ddc0','0x522f40','0x461be0'].forEach(function(a){
 var bad=0;
 Interceptor.attach(ptr(a),{onEnter:function(){ this.e=this.context.esp; },
   onLeave:function(){ var d=this.context.esp.sub(this.e).toInt32(); if(d!==4 && bad<2){ bad++; send({hook:1,fn:a,delta:d}); } }});
});
