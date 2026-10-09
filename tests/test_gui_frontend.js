"use strict";
const assert=require("node:assert/strict"),fs=require("node:fs"),vm=require("node:vm");
const source=fs.readFileSync("roc/web/app.js","utf8");
const selection=source.slice(source.indexOf("async function selectWorker(id)"));
const context={workerRun:"",chatSignature:"",page:"workers",logs:[],token:"session",renders:[],messages:[],control:{value:""},AbortSignal,
  $(){return this.control;},renderWorkerChat(){context.renders.push(context.workerRun);},toast(message){context.messages.push(message);}};
context.$=()=>context.control;
vm.createContext(context);
vm.runInContext(selection,context);
const formContext={editing:null,jobs:[],meta:{initial:{}},
  $:()=>({querySelectorAll:()=>[
    {name:"workers",value:"auto",type:"text"},{name:"rounds",value:"auto",type:"text"},
    {name:"max_tokens",value:"auto",type:"text"},{name:"cloud_concurrency",value:"auto",type:"text"},
    {name:"max_size",value:"512",type:"number"},{name:"min_score",value:"",type:"number"},
    {name:"order",value:"auto",type:"select-one"},{name:"cloud_allowed",checked:true,type:"checkbox"}],
    elements:{addresses:{value:"00401000"}}})};
vm.createContext(formContext);
vm.runInContext(source.slice(source.indexOf("const nullable"),source.indexOf("async function api")),formContext);
vm.runInContext(source.slice(source.indexOf("function readWorker()"),source.indexOf("function logText(")),formContext);
const automaticForm=formContext.readWorker();
assert.equal(automaticForm.workers,"auto");assert.equal(automaticForm.rounds,"auto");
assert.equal(automaticForm.max_tokens,"auto");assert.equal(automaticForm.cloud_concurrency,"auto");
assert.equal(automaticForm.max_size,512);assert.equal(automaticForm.min_score,null);
assert.equal(automaticForm.cloud_allowed,true);assert.equal(automaticForm.targets[0].addr,"00401000");
vm.runInContext(source.slice(source.indexOf("function field("),source.indexOf("let controlsOpen=")),formContext);
formContext.meta={providers:[],clients:[],preferences:{presets:{}}};formContext.localModels=[];
formContext.esc=String;formContext.liveKeys=new Set();formContext.button=()=>"";
const formHTML=formContext.workerForm({...automaticForm,targets:[]});
assert.ok(formHTML.indexOf('name="workers"')<formHTML.indexOf("Advanced controls"));
assert.equal((formHTML.match(/name="workers"/g)||[]).length,1);
for(const key of ["rounds","max_tokens","max_size","order","strategy"])
  assert.ok(formHTML.indexOf(`name="${key}"`)>formHTML.indexOf("Advanced controls"));
assert.match(formHTML,/data-preset="automatic" class="active"/);
for(const count of [1,8,100,"auto"]) {
  formContext.target={dataset:{preset:"automatic"}};
  formContext.document={querySelectorAll:()=>[]};
  formContext.readWorker=()=>({...automaticForm,workers:count});
  formContext.render=config=>formContext.rendered=config;
  vm.runInContext(source.slice(source.indexOf("  if(target.dataset.preset)"),source.indexOf("  if(target.dataset.action)")),formContext);
  const config=formContext.rendered;
  assert.equal(config.workers,count);
  assert.equal(config.rounds,"auto");
  assert.match(formContext.workerForm({...automaticForm,...config,targets:[]}),new RegExp(`name="workers" value="${count}"`));
}
const feedNodes={};
for(const id of ["worker-chat","worker-tabs","worker-status","chat-compact","chat-follow","jump-live","worker-chat-rows"])
  feedNodes["#"+id]={dataset:{},innerHTML:"",children:[],classList:{toggle() {}}};
const feedContext={jobs:[],logs:[],workerRun:"",workerLoop:"",chatCompact:false,chatFollow:true,chatSignature:"",
  $:selector=>feedNodes[selector],active:job=>job.status==="running",esc:String,workerCards:()=>"",empty:()=>"empty",
  setChatFollow:()=>{},updateFeed:(_node,items)=>feedContext.items=items};
vm.createContext(feedContext);
vm.runInContext(source.slice(source.indexOf("function terminalMessage("),source.indexOf("function setChatFollow(")),feedContext);
vm.runInContext(source.slice(source.indexOf("function logText("),source.indexOf("function filteredLogs(")),feedContext);
vm.runInContext(source.slice(source.indexOf("function renderWorkerChat("),source.indexOf("function workerCards(")),feedContext);
for(const loops of [3,4,100]) {
  feedContext.jobs=[{id:"run",kind:"worker",status:"running",config:{client:"C"},slots:Object.fromEntries(Array.from({length:loops},(_,i)=>[i,{}]))}];
  feedContext.logs=[{job:"run",seq:1,time:1,event:"log",message:"compile chatter"},
    {job:"run",seq:4,time:1,event:"log",startup:true,message:"Worker started"},
    {job:"run",seq:5,time:1,event:"log",startup:true,message:"Privacy: bounded prompts"},
    {job:"run",seq:2,time:2,event:"job_finished",slot:0,client:"C",addr:"00401000",unit:"LongUnit",previous:50,score:60,seconds:3},
    {job:"run",seq:3,time:3,event:"benchmark",workers:loops,completed:1,per_minute:2,matched:0,improved:1,errors:0}];
  feedContext.chatSignature="";feedContext.renderWorkerChat();
  assert.equal(feedContext.items.length,loops>3 ? 4 : 5);
  assert.ok(feedContext.items.some(([,html])=>html.includes("Worker started")));
  assert.ok(feedContext.items.some(([,html])=>html.includes("Privacy: bounded prompts")));
  assert.match(feedNodes["#worker-tabs"].innerHTML,/dot running/);
  assert.doesNotMatch(feedNodes["#worker-tabs"].innerHTML,/data-remove-run/);
  const result=feedContext.items.find(([key])=>key.startsWith("run:2"))[1];
  assert.match(result,/C 00401000/);assert.match(result,/50% → 60%/);
  assert.equal(result.includes("LongUnit"),loops===3);
  assert.match(feedContext.items.at(-1)[1],/2 fn\/min/);
}
feedContext.jobs[0].slots={0:{}};feedContext.chatCompact=true;feedContext.chatSignature="";
feedContext.renderWorkerChat();assert.equal(feedContext.items.length,4);
feedContext.jobs[0].status="completed";feedContext.renderWorkerChat();
assert.match(feedNodes["#worker-tabs"].innerHTML,/dot completed/);
assert.match(feedNodes["#worker-tabs"].innerHTML,/data-remove-run="run"/);
console.log("Compact: one result per function, benchmarks, 3/4/100-loop boundary passed");
(async()=>{
  context.fetch=async()=>{throw new TypeError("Failed to fetch");};
  await context.selectWorker("saved");
  assert.equal(context.workerRun,"saved");
  assert.equal(context.control.value,"saved");
  assert.equal(context.renders[0],"saved");
  assert.match(context.messages[0],/Dashboard disconnected/);
  context.fetch=async()=>({ok:true,text:async()=>JSON.stringify({job:"other",seq:1,time:2,event:"log",message:"recorded"})+"\n"});
  await context.selectWorker("other");
  assert.equal(context.logs[0].message,"recorded");
  await context.selectWorker("");
  assert.equal(context.workerRun,"");
  const labels={"#chat-follow":{},"#jump-live":{}};
  context.$=selector=>labels[selector];context.chatFollow=true;
  context.requestAnimationFrame=callback=>callback();context.setTimeout=()=>0;
  context.matchMedia=()=>({matches:false});
  vm.runInContext(source.slice(source.indexOf("function setChatFollow("),source.indexOf("function updateFeed(")),context);
  vm.runInContext(source.slice(source.indexOf("function pauseFollow("),source.indexOf('for(const type of ["wheel","touchstart","keydown","pointerdown"]')),context);
  const viewport={id:"worker-chat",isConnected:true,dataset:{},scrollHeight:1200,scrollTo(options){this.last=options;}};
  const child={closest:()=>viewport};
  context.pauseFollow({type:"pointerdown",target:child});assert.equal(context.chatFollow,true);
  context.pauseFollow({type:"wheel",deltaY:100,target:child});assert.equal(context.chatFollow,true);
  context.pauseFollow({type:"wheel",deltaY:-100,target:child});assert.equal(context.chatFollow,false);assert.equal(labels["#jump-live"].hidden,false);
  context.setChatFollow(true);context.scrollToLatest(viewport,true);
  assert.equal(viewport.last.top,1200);assert.equal(viewport.last.behavior,"smooth");assert.equal(labels["#jump-live"].hidden,true);
  context.setChatFollow(false);viewport.last=null;context.scrollToLatest(viewport,true);assert.equal(viewport.last,null);
  console.log("Tabs and scrolling: offline selection, manual pause, smooth jump, cancelled follow passed");
})().catch(error=>{console.error(error);process.exitCode=1;});
