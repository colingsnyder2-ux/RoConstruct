"use strict";
const assert=require("node:assert/strict"),fs=require("node:fs"),vm=require("node:vm");
const source=fs.readFileSync("roc/web/app.js","utf8");
const context={jobs:[{id:"run",kind:"agent_worker",title:"Agent <test>",status:"failed",config:{model:"chosen"}}],
  agentHistoryLog:null,page:"history",token:"secret",render:()=>{},
  esc:value=>String(value??"").replaceAll("&","&amp;").replaceAll("<","&lt;").replaceAll(">","&gt;"),
  button:(label,attrs)=>`<button ${attrs}>${label}</button>`,badge:status=>status};
vm.createContext(context);
vm.runInContext(source.slice(source.indexOf("function experimentMemory(s)"),source.indexOf("async function loadWorkerMemory")),context);
const full="LONG_AGENT_REPORT "+"x".repeat(12000)+" END_REPORT <script>";
const rows=Array.from({length:200},(_,i)=>({kind:"workflow",date:String(i),worked_well:["saved best source"],
  improvements:["API suggestion"],mistakes:["repeat trial"],avoid_next_time:["check memory"],output_tail:[full]}));
const html=context.experimentMemory({recent:rows});
assert.equal((html.match(/Full text \/ all fields/g)||[]).length,200);
assert.ok(html.includes("END_REPORT &lt;script&gt;"));
for(const text of ["worked well","improvements","mistakes","avoid next time","API suggestion"])assert.ok(html.includes(text));
assert.ok(context.agentHistory().includes('data-agent-history-log="run"'));
context.fetch=async(url,options)=>{
  assert.equal(url,"/api/log?id=run");assert.equal(options.headers["X-ROC-Token"],"secret");
  return {ok:true,text:async()=>JSON.stringify({time:1,event:"log",slot:0,message:full})+"\n"+JSON.stringify({event:"state",message:"Failed"})};
};
(async()=>{
  await context.loadAgentHistoryLog("run");
  assert.ok(context.agentHistoryLog.text.includes(full));
  assert.ok(context.agentHistoryLog.text.includes("agent 1"));
  assert.ok(context.agentHistoryLog.text.includes("Failed"));
  assert.ok(context.agentHistory().includes("END_REPORT &lt;script&gt;"));
  console.log("Agent history frontend checks passed");
})().catch(error=>{console.error(error);process.exitCode=1;});
