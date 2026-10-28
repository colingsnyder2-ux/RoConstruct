"use strict";
const assert=require("node:assert/strict"),fs=require("node:fs"),vm=require("node:vm");
const source=fs.readFileSync("roc/web/app.js","utf8");
const agentContext={agentState:{clis:{},client:{},memory:{lessons:[{
  library:"XTP",id:"prelude",change:"Vendor header",next:"Inspect prelude",evidence:"report.md",
  exacts_gained:321,outcome:"server_verified"}],recent:[{
  client:"2008-06",kind:"session",before:40,candidate:10,after:40,outcome:"rolled_back"}]}},
  agentPlan:null,jobs:[],agentAutoConfig:{},check:()=>"",heading:()=>"",button:()=>"",field:()=>"",esc:value=>String(value).replaceAll("<","&lt;")};
vm.createContext(agentContext);
vm.runInContext(source.slice(source.indexOf("const VARIANTS"),source.indexOf("function workerForm")),agentContext);
vm.runInContext(source.slice(source.indexOf("function experimentMemory(s)"),source.indexOf("function settings()")),agentContext);
const memoryHTML=agentContext.experimentMemory(agentContext.agentState.memory);
assert.match(memoryHTML,/candidate 10%/);
assert.match(memoryHTML,/rolled_back/);
agentContext.meta={initial:{user:"tester",server:"localhost:8765"},providers:[],preferences:{},clients:[{name:"2008-06"},{name:"2009-12"}]};
agentContext.field=(label,name,value,options={})=>options.choices ? `<select name="${name}">${options.choices.map(([key,text])=>`<option value="${key}">${text}</option>`).join("")}</select>` : `<input name="${name}" value="${value}">`;
agentContext.button=label=>`<button>${label}</button>`;
const simpleAgentHTML=agentContext.agentAutomatic();
assert.match(simpleAgentHTML,/value="opencode">OpenCode/);
agentContext.meta.agent_models=["opencode/big-pickle"];
agentContext.agentAutoConfig.cli="opencode";
const openCodeHTML=agentContext.agentAutomatic();
assert.match(openCodeHTML,/value="opencode\/big-pickle"/);
assert.doesNotMatch(openCodeHTML,/value="claude-opus/);
agentContext.meta.agent_models=["opencode-go/deepseek-v4.1-flash","opencode/glm-5.3"];
const goPlanHTML=agentContext.agentAutomatic();
assert.match(goPlanHTML,/value="opencode-go\/deepseek-v4.1-flash"/);
assert.match(goPlanHTML,/Go plan/);
assert.match(goPlanHTML,/log in at settings/);
assert.match(goPlanHTML,/name="variant"/);
agentContext.agentAutoConfig={cli:"claude",model:"claude-opus-4-6"};
const claudeFormHTML=agentContext.agentAutomatic();
assert.doesNotMatch(claudeFormHTML,/name="variant"/);
assert.doesNotMatch(claudeFormHTML,/no API key/);
assert.match(simpleAgentHTML,/<input name="goal" value="">/);
assert.match(simpleAgentHTML,/Automatic/);
assert.match(simpleAgentHTML,/Fast/);
assert.match(simpleAgentHTML,/Balanced/);
assert.match(simpleAgentHTML,/Deep/);
assert.match(simpleAgentHTML,/Start Agent/);
assert.doesNotMatch(simpleAgentHTML,/Preview|Total target cap|Max function bytes|Individual mining/);
for(const name of ["client","user","server","cli","model","workers"])
  assert.match(simpleAgentHTML,new RegExp(`name="${name}"`));
assert.match(simpleAgentHTML,/All clients/);
assert.match(simpleAgentHTML,/2009-12/);
assert.match(simpleAgentHTML,/class="preset-row"/);
assert.match(simpleAgentHTML,/data-agent-mode="automatic" class="active"/);
assert.doesNotMatch(simpleAgentHTML,/<select name="mode">/);
assert.match(source,/if\(target.dataset.agentMode\) \{readAgentAuto\(\);agentAutoConfig.mode=target.dataset.agentMode;render\(\);\}/);
assert.doesNotMatch(simpleAgentHTML,/data-agent-preset/);
assert.match(source,/data-worker-mode="native">Integrator/);
assert.match(source,/data-worker-mode="function">Worker/);
for(const [mode,minutes] of [["automatic",120],["fast",30],["balanced",120],["deep",240]]) {
  agentContext.$=()=>({dataset:{mode},elements:Object.fromEntries(Object.entries({
    mode,client:"2008-06",user:"other-user",server:"other-host:8765",cli:"codex",model:"chosen-model",goal:"Match Ogre",workers:"3"
  }).map(([key,value])=>[key,{value}]))});
  agentContext.agentAutoConfig={cli:"codex",model:"chosen-model",individual:true};
  const config=agentContext.readAgentAuto();
  assert.equal(config.cli,"codex");assert.equal(config.model,"chosen-model");
  assert.equal(config.goal,"Match Ogre");
  assert.equal(config.minutes,minutes);assert.equal(config.individual,false);
  assert.equal(config.max_size,mode==="deep" ? 0 : mode==="fast" ? 256 : 512);
  assert.equal(config.workers,3);assert.ok(config.jobs>0);
  assert.equal(config.user,"other-user");assert.equal(config.server,"other-host:8765");
  assert.equal(config.client,"2008-06");
}
agentContext.$=()=>({dataset:{mode:"automatic"},elements:Object.fromEntries(Object.entries({
  client:"",user:"tester",server:"localhost:8765",cli:"opencode",
  model:"opencode-go/deepseek-v4.1-flash",goal:"",workers:"2",variant:"high"
}).map(([key,value])=>[key,{value}]))});
agentContext.agentAutoConfig={cli:"opencode",model:"opencode-go/deepseek-v4.1-flash"};
const variantConfig=agentContext.readAgentAuto();
assert.equal(variantConfig.model,"opencode-go/deepseek-v4.1-flash#high");
agentContext.$=()=>({dataset:{mode:"automatic"},elements:Object.fromEntries(Object.entries({
  client:"",user:"tester",server:"localhost:8765",cli:"opencode",
  model:"opencode-go/deepseek-v4.1-flash#low",goal:"",workers:"2",variant:"high"
}).map(([key,value])=>[key,{value}]))});
assert.equal(agentContext.readAgentAuto().model,"opencode-go/deepseek-v4.1-flash#high");
agentContext.$=()=>({dataset:{mode:"automatic"},elements:Object.fromEntries(Object.entries({
  client:"",user:"tester",server:"localhost:8765",cli:"codex",
  model:"chosen-model",goal:"",workers:"2",variant:"high"
}).map(([key,value])=>[key,{value}]))});
assert.equal(agentContext.readAgentAuto().model,"chosen-model");
assert.doesNotMatch(source,/data-worker-mode="memory"|data-agent-plan|agent-auto-plan/);
assert.match(source,/summary>Experiments/);
assert.match(source,/summary>Runs/);
assert.match(simpleAgentHTML,/Install \/ sign in/);
agentContext.agentState.memory=null;
assert.match(agentContext.experimentMemory(null),/Loading experiments/);
const selection=source.slice(source.indexOf("async function selectWorker(id)"));
const context={workerRun:"",chatSignature:"",page:"workers",logs:[],token:"session",renders:[],messages:[],control:{value:""},AbortSignal,
  $(){return this.control;},renderWorkerChat(){context.renders.push(context.workerRun);},toast(message){context.messages.push(message);}};
context.$=()=>context.control;
vm.createContext(context);
vm.runInContext(selection,context);
const formContext={workerMode:"function",editing:null,jobs:[],meta:{initial:{}},
  $:()=>({querySelectorAll:()=>[
    {name:"workers",value:"auto",type:"text"},{name:"rounds",value:"auto",type:"text"},
    {name:"max_tokens",value:"auto",type:"text"},{name:"cloud_concurrency",value:"auto",type:"text"},
    {name:"max_size",value:"512",type:"number"},{name:"min_score",value:"",type:"number"},
    {name:"order",value:"random",type:"select-one"},{name:"cloud_allowed",checked:true,type:"checkbox"}],
    elements:{addresses:{value:"00401000"}}})};
vm.createContext(formContext);
vm.runInContext(source.slice(source.indexOf("const nullable"),source.indexOf("async function api")),formContext);
vm.runInContext(source.slice(source.indexOf("function readWorker()"),source.indexOf("function logText(")),formContext);
const automaticForm=formContext.readWorker();
assert.equal(automaticForm.workers,"auto");assert.equal(automaticForm.rounds,"auto");
assert.equal(automaticForm.max_tokens,"auto");assert.equal(automaticForm.cloud_concurrency,"auto");
assert.equal(automaticForm.max_size,512);assert.equal(automaticForm.min_score,null);
assert.equal(automaticForm.cloud_allowed,true);assert.equal(automaticForm.targets[0].addr,"00401000");
vm.runInContext(source.slice(source.indexOf("function field("),source.indexOf("let workerMode=")),formContext);
formContext.meta={providers:[],clients:[],preferences:{presets:{}}};formContext.localModels=[];
formContext.esc=String;formContext.liveKeys=new Set();formContext.button=()=>"";
const formHTML=formContext.workerForm({...automaticForm,targets:[]});
assert.ok(formHTML.indexOf('name="workers"')<formHTML.indexOf("Advanced controls"));
assert.equal((formHTML.match(/name="workers"/g)||[]).length,1);
for(const key of ["rounds","max_tokens","max_size","order","strategy"])
  assert.ok(formHTML.indexOf(`name="${key}"`)>formHTML.indexOf("Advanced controls"));
assert.match(formHTML,/data-preset="automatic" class="active"/);
formContext.meta={providers:[{name:"opencode",ready:true,auth:"cli",models:[]},
  {name:"deepseek",ready:false,auth:"api-key",models:["deepseek-flash"]},
  {name:"chatgpt",ready:false,auth:"chatgpt",models:["gpt-5.2"]}],
  clients:[],preferences:{presets:{}},agent_models:["opencode-go/deepseek-v4.1-flash","opencode/glm-5.3"]};
formContext.localModels=["qwen2.5-coder:7b"];
vm.runInContext('matchProvider="custom"',formContext);
const dropHTML=formContext.workerForm({...automaticForm,targets:[],model:""});
assert.match(dropHTML,/<select name="model"/);
assert.match(dropHTML,/value="qwen2.5-coder:7b"/);
assert.match(dropHTML,/value="deepseek:deepseek-flash"/);
assert.match(dropHTML,/value="deepseek"[^>]*>DeepSeek API/);
assert.match(dropHTML,/key missing/);
assert.doesNotMatch(dropHTML,/value="chatgpt:gpt-5.2"/);
assert.doesNotMatch(dropHTML,/value="opencode:opencode-go\/deepseek-v4.1-flash"/);
assert.doesNotMatch(dropHTML,/name="model_variant"/);
vm.runInContext('matchProvider="opencode"',formContext);
const openCodeDropHTML=formContext.workerForm({...automaticForm,targets:[],model:""});
assert.match(openCodeDropHTML,/value="opencode:opencode-go\/deepseek-v4.1-flash"/);
assert.match(openCodeDropHTML,/Go plan/);
const ocModelHTML=formContext.workerForm({...automaticForm,targets:[],model:"opencode:opencode-go/deepseek-v4.1-flash"});
assert.match(ocModelHTML,/name="model_variant"/);
assert.match(ocModelHTML,/value="high"/);
formContext.$=()=>({querySelectorAll:()=>[
  {name:"model",value:"opencode:opencode-go/deepseek-v4.1-flash",type:"select-one"},
  {name:"model_variant",value:"high",type:"select-one"},
  {name:"workers",value:"2",type:"text"}],
  elements:{addresses:{value:""},model:{value:"opencode:opencode-go/deepseek-v4.1-flash"},model_variant:{value:"high"}}});
const ocConfig=formContext.readWorker();
assert.equal(ocConfig.model,"opencode:opencode-go/deepseek-v4.1-flash#high");
formContext.$=()=>({querySelectorAll:()=>[
  {name:"model",value:"opencode:opencode-go/deepseek-v4.1-flash",type:"select-one"},
  {name:"model_variant",value:"",type:"select-one"},
  {name:"workers",value:"2",type:"text"}],
  elements:{addresses:{value:""},model:{value:"opencode:opencode-go/deepseek-v4.1-flash"},model_variant:{value:""}}});
assert.equal(formContext.readWorker().model,"opencode:opencode-go/deepseek-v4.1-flash");
for(const count of [1,8,100,"auto"]) {
  formContext.target={dataset:{preset:"automatic"}};
  formContext.document={querySelectorAll:()=>[]};
  formContext.readWorker=()=>({...automaticForm,workers:count,near_repair:true,diverse_candidates:4,max_cloud_cost:3});
  formContext.render=config=>formContext.rendered=config;
  vm.runInContext(source.slice(source.indexOf("  if(target.dataset.preset)"),source.indexOf("  if(target.dataset.action)")),formContext);
  const config=formContext.rendered;
  assert.equal(config.workers,count);
  assert.equal(config.rounds,"auto");
  assert.equal(config.near_repair,false);assert.equal(config.diverse_candidates,1);
  assert.equal(config.max_cloud_cost,3);assert.equal(config.cloud_allowed,true);
  assert.match(formContext.workerForm({...automaticForm,...config,targets:[]}),new RegExp(`name="workers" value="${count}"`));
}
const feedNodes={};
for(const id of ["worker-chat","worker-tabs","worker-status","chat-compact","chat-follow","jump-live","worker-chat-rows"])
  feedNodes["#"+id]={dataset:{},innerHTML:"",children:[],classList:{toggle() {}}};
const feedContext={jobs:[],logs:[],workerRun:"",workerLoop:"",chatCompact:false,chatFollow:true,chatSignature:"",
  isWorker:job=>["worker","agent_worker"].includes(job.kind),
  $:selector=>feedNodes[selector],active:job=>job.status==="running",esc:String,workerCards:()=>"",empty:()=>"empty",
  setChatFollow:()=>{},updateFeed:(_node,items)=>feedContext.items=items};
vm.createContext(feedContext);
vm.runInContext(source.slice(source.indexOf("function tabModel("),source.indexOf("function renderWorkerChat(")),feedContext);
vm.runInContext(source.slice(source.indexOf("function terminalMessage("),source.indexOf("function setChatFollow(")),feedContext);
vm.runInContext(source.slice(source.indexOf("function logText("),source.indexOf("function filteredLogs(")),feedContext);
feedContext.codeBlock=(text)=>`<pre>${text}</pre>`;
const nativeResult=feedContext.terminalMessage({job:"native",seq:1,time:1,event:"native_result",slot:2,file:"App/Block.cpp",local_exact:3,seconds:19.8},new Map(),true);
assert.match(nativeResult,/native_result exact/);
assert.match(nativeResult,/w3/);
assert.match(nativeResult,/3 local exact/);
assert.match(nativeResult,/awaiting verification/);
const longAgentRow={job:"agent",seq:1,time:1,event:"log",message:"Command finished · exit 0\n"+"large output ".repeat(500)};
const quotedFailure={...longAgentRow,message:"Command finished · exit 0\nDocs: compiler failed; Error: example only"};
assert.doesNotMatch(feedContext.terminalMessage(quotedFailure,new Map(),true),/terminal-row error/);
assert.match(feedContext.terminalMessage({...longAgentRow,message:"Command finished · exit 1\nCompiler failed"},new Map(),true),/terminal-row error/);
assert.match(feedContext.terminalMessage({...longAgentRow,message:"Agent error: startup failed"},new Map(),true),/terminal-row error/);
const compactAgentRow=feedContext.terminalMessage(longAgentRow,new Map(),true);
assert.match(compactAgentRow,/<summary>.*Command finished · exit 0.*<\/summary>/);
assert.match(compactAgentRow,/<pre>large output/);
assert.doesNotMatch(compactAgentRow,/<details open/);
assert.match(feedContext.terminalMessage(longAgentRow,new Map(),false),/<pre>large output/);
assert.match(feedContext.terminalMessage({...longAgentRow,message:'  > py roc.py check'},new Map(),false),/terminal-row tool-call.*<summary>.*py roc.py check.*<\/summary><pre>py roc.py check/);
assert.match(feedContext.terminalMessage({...longAgentRow,message:'  < 38.9s Bash check'},new Map(),false),/terminal-row tool-call/);
assert.match(feedContext.terminalMessage({...longAgentRow,message:'00401000 → 100 · server verified exact'},new Map(),false),/terminal-row matched-note/);
assert.doesNotMatch(feedContext.terminalMessage({...longAgentRow,message:'3 local exacts; server already done'},new Map(),false),/terminal-row matched-note/);
assert.doesNotMatch(feedContext.terminalMessage({...longAgentRow,message:'code-exact; data mismatch'},new Map(),false),/terminal-row matched-note/);
assert.match(feedContext.terminalMessage({...longAgentRow,event:'job_finished',client:'C',addr:'00401000',previous:99,score:100,new_exact:false},new Map(),false),/job_finished no-gain.*already exact/);
const toolRows=[];
for(let i=0;i<3;i++)toolRows.push({...longAgentRow,seq:i*3,message:'  > roc check C 00401000'},
  {...longAgentRow,seq:i*3+1,message:'Command finished · exit 0\nreturn output '+i},
  {...longAgentRow,seq:i*3+2,message:'  < '+[10,12,16][i]+'.0s roc check C 00401000'});
const toolGroup=feedContext.groupToolRows(toolRows);
assert.equal(toolGroup.length,1);
const toolHTML=feedContext.terminalMessage(toolGroup[0],new Map(),true);
assert.match(toolHTML,/Ran 3 commands · 38s/);
assert.match(toolHTML,/return output 2/);
assert.doesNotMatch(toolHTML,/<details open/);
const spamRows=[...toolRows.slice(0,3),{...longAgentRow,seq:20,message:"Thinking · Repeated setup narration"},
  {...longAgentRow,seq:21,message:"Let me check the current state."},...toolRows.slice(3)];
const spamGroup=feedContext.groupToolRows(spamRows);
assert.equal(spamGroup.length,1);
const spamHTML=feedContext.terminalMessage(spamGroup[0],new Map(),true);
assert.match(spamHTML,/Ran 3 commands · 38s/);
assert.match(spamHTML,/Repeated setup narration/);
const fencedAgentRow=feedContext.terminalMessage({...longAgentRow,message:'Change:\n```cpp\nint f() { return 1; }\n```'},new Map(),false);
assert.match(fencedAgentRow,/<pre>int f\(\) \{ return 1; \}/);
assert.doesNotMatch(fencedAgentRow,/```cpp/);
vm.runInContext(source.slice(source.indexOf("function renderWorkerChat("),source.indexOf("function workerCards(")),feedContext);
for(const loops of [3,4,100]) {
  feedContext.jobs=[{id:"run",kind:"worker",status:"running",config:{client:"C"},slots:Object.fromEntries(Array.from({length:loops},(_,i)=>[i,{}]))}];
  feedContext.logs=[{job:"run",seq:1,time:1,event:"log",message:"compile chatter"},
    {job:"run",seq:4,time:1,event:"log",startup:true,message:"Worker started"},
    {job:"run",seq:5,time:1,event:"log",startup:true,message:"Privacy: bounded prompts"},
    {job:"run",seq:2,time:2,event:"job_finished",slot:0,client:"C",addr:"00401000",unit:"LongUnit",size:30,previous:50,score:60,seconds:3},
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
  assert.match(feedContext.items.at(-1)[1],/0 exact · 1 improved/);
}
feedContext.jobs[0].slots={0:{}};feedContext.chatCompact=true;feedContext.chatSignature="";
feedContext.renderWorkerChat();assert.equal(feedContext.items.length,4);
feedContext.jobs[0].status="completed";feedContext.renderWorkerChat();
assert.match(feedNodes["#worker-tabs"].innerHTML,/dot completed/);
assert.match(feedNodes["#worker-tabs"].innerHTML,/data-remove-run="run"/);
feedContext.jobs[0]={...feedContext.jobs[0],kind:"agent_worker",status:"running"};
feedContext.chatSignature="";feedContext.renderWorkerChat();
assert.ok(feedContext.items.some(([,html])=>html.includes("compile chatter")));
feedContext.chatFollow=false;
feedNodes["#worker-chat-rows"].children=[{}];
feedContext.logs.push({job:"run",seq:99,time:4,event:"log",message:"New activity while scroll is paused"});
feedContext.renderWorkerChat();
assert.ok(feedContext.items.some(([,html])=>html.includes("New activity while scroll is paused")));
feedContext.chatFollow=true;
assert.doesNotMatch(fs.readFileSync("roc/web/style.css","utf8"),/\.workers-page \.worker-chat\{max-width:960px/);
assert.match(feedNodes["#worker-tabs"].innerHTML,/dot running/);
console.log("Compact: one result per function, benchmarks, 3/4/100-loop boundary passed");
(async()=>{
  context.fetch=async()=>{throw new TypeError("Failed to fetch");};
  await context.selectWorker("saved");
  assert.equal(context.workerRun,"saved");
  assert.equal(context.control.value,"saved");
  assert.equal(context.renders[0],"saved");
  assert.equal(context.messages.length,0);
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

assert.match(source,/deep:\{rounds:6,max_size:0,max_tokens:4096\}/);
