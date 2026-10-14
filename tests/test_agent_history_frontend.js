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
  context.restartedWorkers=new Set();context.workerRun="run";
  vm.runInContext(source.slice(source.indexOf("async function restartWorker(job)"),source.indexOf("function toast(message)")),context);
  const calls=[];
  context.api=async(path,data)=>{calls.push([path,data]);if(path==="control")throw new Error("Job is not running");return {id:"new-run"};};
  await context.restartWorker(context.jobs[0]);
  assert.equal(calls[1][0],"start");
  assert.equal(calls[1][1].kind,"agent_worker");
  assert.equal(calls[1][1].model,"chosen");
  assert.equal(context.workerRun,"new-run");
  assert.ok(context.restartedWorkers.has("run"));
  context.api=async()=>{throw new Error("Worker already active");};
  await assert.rejects(()=>context.restartWorker(context.jobs[0]),/already active/);
  console.log("Agent history and restart compatibility checks passed");
})().catch(error=>{console.error(error);process.exitCode=1;});
