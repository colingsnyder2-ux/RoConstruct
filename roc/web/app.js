"use strict";
const $ = (selector) => document.querySelector(selector);
const esc = (value) => String(value ?? "").replace(/[&<>"']/g, char => ({"&":"&amp;","<":"&lt;",">":"&gt;",'"':"&quot;","'":"&#39;"}[char]));
const token = location.hash.slice(1) || sessionStorage.getItem("roc-session");
if (token) sessionStorage.setItem("roc-session", token);
const initialPage = new URLSearchParams(location.search).get("page") === "cpu" ? "cpu" : "overview";
history.replaceState(null, "", location.pathname + (initialPage === "cpu" ? "?page=cpu" : ""));
let meta, jobs = [], page = initialPage, selectedCommand = "mass", editing = null;
let cursor = 0, logs = [], follow = true, online = false, toastTimer, localModels = [];
let workerMemory = null;
let agentHistoryLog = null;
const restartedWorkers = new Set();
let agentAutoConfig = {cli:"claude",model:"",goal:"",workers:2,jobs:24,minutes:120,batch_size:4,batch_minutes:30,max_size:512,individual:false};
let cpu = null, cpuCluster = "", cpuLoaded = 0, cpuLoading = false, serverSetupOpen = initialPage === "cpu";
const isWorker = job => ["worker","agent_worker"].includes(job.kind) || !!job.args?.includes("--automatic");
const active = job => ["running", "paused", "stopping"].includes(job.status);
const liveKeys = new Set(["workers","model","rounds","max_size","max_tokens","strategy","order","thinking","reasoning_effort","use_revng","min_score","max_score","diverse_candidates","guided_mutations","near_repair","max_cloud_requests","max_cloud_tokens","max_cloud_cost"]);
const nullable = new Set(["min_score","max_score","max_cloud_requests","max_cloud_tokens","max_cloud_cost","reasoning_effort","unit_name","family_id"]);
const numeric = new Set(["workers","rounds","max_size","max_tokens","min_score","max_score","diverse_candidates","cloud_concurrency","max_cloud_requests","max_cloud_tokens","max_cloud_cost"]);
const automatic = {rounds:"auto",max_size:512,max_tokens:"auto",order:"random",strategy:"direct",thinking:"auto",reasoning_effort:"auto",use_revng:false,cloud_concurrency:"auto",near_repair:false,diverse_candidates:1};

async function api(path, data) {
  const response = await fetch("/api/" + path, {method:data === undefined ? "GET" : "POST", headers:{"X-ROC-Token":token || "", "Content-Type":"application/json"}, ...(data === undefined ? {} : {body:JSON.stringify(data)})});
  const result = await response.json();
  if (!response.ok) throw new Error(result.error || "Request failed");
  return result;
}
async function restartWorker(job) {
  try {
    await api("control",{id:job.id,action:"restart"});
    job.status="queued";
  } catch(error) {
    if(error.message!=="Job is not running")throw error;
    // Older dashboard backends have start support but no restart control.
    if(!job.config || !["worker","agent_worker"].includes(job.kind))throw error;
    const result=await api("start",job.kind==="worker" ? {kind:"worker",config:{...job.config}} : {kind:"agent_worker",...job.config});
    if(workerRun===job.id)workerRun=result.id;
    jobs.push({...job,id:result.id,status:"queued",started:null,ended:null,slots:{}});
    restartedWorkers.add(job.id);
  }
}
function toast(message) { $("#toast").textContent = message; $("#toast").classList.add("visible"); clearTimeout(toastTimer); toastTimer = setTimeout(() => $("#toast").classList.remove("visible"), 6000); }
async function act(fn) { try { await fn(); } catch(error) { toast(error.message); } }
function badge(status) { return `<span class="badge ${esc(status)}">${esc(status)}</span>`; }
function icon(name) { return `<svg class="icon" aria-hidden="true"><use href="#i-${name}"/></svg>`; }
function heading(label, title, description, buttons="") { return `<div class="page-heading"><div><h1>${title}</h1><p>${description}</p></div><div class="button-row">${buttons}</div></div>`; }
function duration(job) { if (!job.started) return "—"; const seconds = Math.max(0, Math.floor((job.ended || Date.now()/1000)-job.started)); return seconds < 60 ? `${seconds}s` : seconds < 3600 ? `${Math.floor(seconds/60)}m ${seconds%60}s` : `${Math.floor(seconds/3600)}h ${Math.floor(seconds%3600/60)}m`; }
function button(label, attrs="", secondary=false) { const symbol=/start|run|resume/i.test(label) ? "play" : /pause/i.test(label) ? "pause" : /stop|cancel/i.test(label) ? "stop" : /apply|tune|controls/i.test(label) ? "sliders" : /fetch/i.test(label) ? "download" : /save/i.test(label) ? "check" : ""; return `<button class="button ${secondary ? "secondary" : ""}" ${attrs}>${symbol ? icon(symbol) : ""}${label}</button>`; }
function empty(title, description) { return `<div class="empty"><div class="empty-symbol">◇</div><h3>${title}</h3><p>${description}</p></div>`; }
function endRun(job) {
  return `<button class="button end-run" data-action="${["worker","cpu"].includes(job.kind) ? "stop" : "kill"}" data-id="${job.id}" title="${["worker","cpu"].includes(job.kind) ? "Stop new leases; finish active functions" : "Stop this command"}" ${job.status==="stopping" ? "disabled" : ""}>${icon("stop")}${job.status==="stopping" ? "Ending…" : "End run"}</button>`;
}
async function loadCpu(force=false) {
  if(cpuLoading || (!force && Date.now()-cpuLoaded<3000)) return;
  cpuLoading=true;
  try {cpu=await api("cpu"+(cpuCluster ? "?cluster="+encodeURIComponent(cpuCluster) : ""));cpuCluster=cpu.selected || "";cpuLoaded=Date.now();if(page==="cpu")render();if(page==="commands")renderCommandProgress();}
  finally {cpuLoading=false;}
}
function cpuProgress(job) {
  const node=cpu.remote?.nodes.find(n=>n.id===job.worker && n.metadata.job===job.id), state=node?.metadata;
  if(!state || job.state!=="leased")return job.state==="leased" ? "Compiling / comparing; progress pending" : "";
  const progress=state.checked==null ? "Compiling; target progress pending" : `${state.checked}/${job.total} compared (${Math.floor(100*state.checked/job.total)}%)`;
  return `${progress} · ${state.current_addr || ""} ${state.unit || ""}`;
}
function cpuBar(label, done, total, working=true) {
  const known=typeof done==="number" && Number.isFinite(done) && total>0, value=known ? Math.min(total,Math.max(0,done)) : 0;
  return `<div class="cpu-progress"><div><span>${esc(label)}</span><b>${known ? `${value}/${total} · ${Math.floor(100*value/total)}%` : working ? "Working… · total unknown" : "Unavailable"}</b></div><progress aria-label="${esc(label)}" max="${Math.max(1,total)}" ${known || !working ? `value="${value}"` : ""}></progress></div>`;
}
function cpuJobBars(job) {
  const state=cpu.remote?.nodes.find(n=>n.id===job.worker && n.metadata.job===job.id)?.metadata;
  const compared=job.compared ?? (job.completed>0 ? job.completed : state?.checked ?? (["queued","paused"].includes(job.state) ? 0 : null));
  return cpuBar("Compared · worker reported",compared,job.total,job.state==="leased")+cpuBar("Trusted verification",job.completed,job.total);
}
function cpuSummary(remote) {
  return `<div class="server-stats"><span><b>${remote.jobs.filter(j=>["queued","leased","reported","paused"].includes(j.state)).length}</b> pending batches</span><span><b>${remote.jobs.reduce((n,j)=>n+j.completed,0)}</b> targets verified</span><span><b>+${remote.jobs.reduce((n,j)=>n+j.exact_gains,0)}</b> exact matches</span><span><b>+${remote.jobs.reduce((n,j)=>n+j.partial_gains,0)}</b> improved</span></div>`;
}
function serverSetup() {
  if(!serverSetupOpen)return "";
  return `<section class="panel panel-pad"><div class="section-heading"><div><h2>Host a server on this PC</h2><p>Share jobs over your private network.</p></div>${button("Close", 'data-host-server aria-label="Close hosting setup"', true)}</div><h3>1. Create your server</h3><p>Run in your RoConstruct folder. Replace <code>YOUR_PRIVATE_IP</code> with this PC’s LAN or VPN address.</p><pre><code>py -3.12 roc.py cluster setup --nodes YOUR_PRIVATE_IP</code></pre><p class="help-note">Requires Python 3.12. Setup downloads server tools. Already have a server database? Add <code>--db "PATH_TO_OFFLINE_BACKUP.db"</code> to preserve its scores.</p><h3>2. Start hosting</h3><pre><code>py -3.12 roc.py cluster start --config work/cluster/node-1/node.json</code></pre><p>Keep that terminal open, then Refresh this page.</p><p class="help-note">Use a private LAN or VPN. Keep server ports off the public Internet; never share admin configs.</p><details data-cpu-detail="server-advanced"><summary>Advanced hosting options</summary><p>For this PC only, use <code>127.0.0.1</code> as the address. Another standalone server has its own data; it does not sync automatically.</p><p>Automatic failover needs three approved PCs configured together:</p><pre><code>py -3.12 roc.py cluster setup --nodes IP1,IP2,IP3 --db "PATH_TO_OFFLINE_BACKUP.db"</code></pre><p>Copy each PC’s own node folder to it and run its start launcher. Never reuse a node identity. Private network ports: HTTP 8766, NATS 4222/6222; transport TLS is not included.</p>${button("Copy setup link for another PC", 'data-server-uri', true)}<p class="help-note">Requires RoConstruct installed with <code>roc link install</code>. The link opens this guide.</p></details></section>`;
}
function cpuPage() {
  let html=heading("","Servers","Share work across your PCs.",button("Host Server",'data-host-server aria-expanded="'+serverSetupOpen+'"')+button("Refresh",'data-cpu-refresh',true));
  html+=serverSetup();
  if(!cpu)return html+empty("Loading servers","Checking connections…");
  const remote=cpu.remote;
  if(cpu.clusters.length)html+=`<section class="panel panel-pad server-connection"><div class="server-connection-row"><label class="field"><span>Server</span><select id="cpu-cluster">${cpu.clusters.map(n=>`<option value="${n.id}" ${n.id===cpuCluster ? "selected" : ""}>${esc(n.label)}</option>`).join("")}</select></label>${badge(remote ? "Online" : "Offline")}</div><details data-cpu-detail="server-connection"><summary>Connection details</summary><p><code>${esc((cpu.servers || []).join(", "))}</code></p><p>Config: <code>${esc(cpu.clusters.find(n=>n.id===cpuCluster)?.path || "")}</code></p>${remote ? `<p>${remote.replicas} server replica(s)</p>` : ""}${cpu.error ? `<p>${esc(cpu.error)}</p>` : ""}</details>${!remote ? '<p>Start the server or check your private network.</p>' : ""}</section>`;
  else html+=empty("No server connected","Select Host Server to get started.");
  return html;
}
function commandProgress() {
  if(!cpu)return "";
  const remote=cpu.remote;
  let html="";
  if(remote?.jobs.length)html+=cpuSummary(remote);
  if(remote) {
    html+='<div class="section-heading"><h2>Function batches</h2></div>';
    html+=remote.jobs.length ? `<div class="panel cpu-jobs">${remote.jobs.map(j=>`<div class="cpu-job"><div class="cpu-job-heading"><h3>${esc(j.command)}</h3>${j.state==="rejected" && j.scores.length ? '<span class="badge completed">No gain</span>' : badge(({leased:"Running",reported:"Verifying",queued:"Waiting",paused:"Paused"})[j.state] || j.state)}</div><p>${esc(j.client)} · ${esc(j.owner)} · ${j.completed}/${j.total} verified · +${j.exact_gains} exact · +${j.partial_gains} improved</p>${j.state==="leased" ? `<p>${esc(cpuProgress(j))}</p>` : ""}<details data-cpu-detail="${j.id}"><summary>Job details</summary><p>Worker: ${esc(j.worker || "Waiting for a PC")} · ${j.attempts} attempt(s)</p>${cpuJobBars(j)}<p><code>${esc(j.compiler)}</code> <code>${esc(j.flags)}</code></p><div class="cpu-addresses">${(j.targets || j.addrs.map(addr=>({addr}))).map(t=>`<p><code>${esc(t.addr)}</code> ${esc(t.unit || "")}</p>`).join("")}</div>${j.scores.map(s=>`<p><code>${esc(s.addr)}</code> · ${s.score}% · ${s.improved ? "improved" : "no gain"} · verified</p>`).join("")}</details></div>`).join("")}</div>` : '<div class="panel panel-pad"><p>No function batches yet.</p></div>';
  }
  const commands=(cpu.tasks || []).filter(j=>["running","paused","stale"].includes(j.status));
  if(commands.length)html+='<div class="section-heading"><h2>Commands on this PC</h2></div>'+`<div class="panel">${commands.map(j=>`<div class="client-row"><div><h3>${esc(j.command)}</h3><p>${esc(j.stage)} · ${j.inspected} functions inspected · ${esc(j.status)}</p><details data-cpu-detail="command-${esc(j.id)}"><summary>Details</summary><p>${esc(j.owner)} · ${esc(j.pc)} · PID ${esc(j.pid)}</p><p>${esc(j.client)} · ${esc(j.addr)} · ${esc(j.unit)}</p><p><code>${esc(j.flags)}</code></p></details></div><div class="button-row">${j.status!=="stale" ? button(j.status==="paused" ? "Resume" : "Pause",`data-roc-id="${j.id}" data-roc-action="${j.status==="paused" ? "resume" : "pause"}"`,true)+button("Stop",`data-roc-id="${j.id}" data-roc-action="stop"`,true) : ""}</div></div>`).join("")}</div>`;
  return html;
}
function runTable(rows, emptyTitle="No saved runs") {
  if (!rows.length) return `<div class="panel">${empty(emptyTitle, "Start a worker or choose a command.")}</div>`;
  return `<div class="panel"><table class="run-list"><thead><tr><th>RUN</th><th>STATUS</th><th class="optional">DURATION</th><th>RESULT</th><th></th></tr></thead><tbody>${rows.map(job => `<tr><td class="run-name" data-log="${job.id}">${esc(job.title)}<small>${job.id}</small></td><td>${badge(job.status)}</td><td class="optional">${duration(job)}</td><td>${isWorker(job) ? `${job.matched} exact / ${job.attempted} tried` : esc(job.stage || (job.exit_code === undefined ? "—" : "exit " + job.exit_code))}</td><td><div class="run-actions">${active(job) ? (job.kind==="worker" ? `<button class="text-button" data-action="edit" data-id="${job.id}">Controls</button>` : "")+endRun(job) : `<button class="text-button" data-rerun="${job.id}">Rerun</button>`}</div></td></tr>`).join("")}</tbody></table></div>`;
}
function overview() {
  const total = key => jobs.reduce((sum, job) => sum + (job[key] || 0), 0);
  const running = jobs.filter(active), workers = running.filter(job => isWorker(job));
  return heading("", "Overview", "Worker results and current activity.", button("Start worker", 'data-new-worker') + button("Run mass", 'data-open-command="mass"', true)) +
    `<div class="workflow"><span class="workflow-step">${icon("file")}Lease</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("code")}Draft C++</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("cpu")}Compile</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("branch")}Compare bytes</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("check")}Submit match</span></div>` +
    `<div class="stat-grid"><div class="stat"><div class="stat-icon">${icon("code")}</div><div class="stat-label">Exact matches</div><div class="stat-value">${total("matched")}</div><div class="stat-note">Recorded worker runs</div></div><div class="stat"><div class="stat-icon">${icon("file")}</div><div class="stat-label">Functions attempted</div><div class="stat-value">${total("attempted")}</div><div class="stat-note">${total("improved")} improved · ${total("failed")} failed</div></div><div class="stat"><div class="stat-icon">${icon("cpu")}</div><div class="stat-label">Worker loops</div><div class="stat-value">${workers.reduce((sum,job)=>sum+Object.keys(job.slots).length,0)}</div><div class="stat-note">${workers.reduce((sum,job)=>sum+(Number(job.config.workers)||Object.keys(job.slots).length),0)} requested · ${running.length} active runs</div></div><div class="stat"><div class="stat-icon">${icon("chart")}</div><div class="stat-label">Cloud requests</div><div class="stat-value">${jobs.reduce((sum,job)=>sum+(job.usage.requests||0),0)}</div><div class="stat-note">Usage appears after each function</div></div></div>` +
    `<div class="section-heading"><h2>Current activity</h2><button class="text-button" data-page="history">View history →</button></div>` + runTable([...jobs].reverse().filter(active).slice(0,10), "No active runs") +
    `<p class="help-note">Runs execute one at a time to protect shared source and work files. Parallel worker loops run within a worker session.</p>`;
}
function field(label, key, value, options={}) {
  const disabled = editing && !liveKeys.has(key) ? "disabled" : "";
  let input;
  if (options.choices) input = `<select name="${key}" ${disabled}>${options.choices.map(choice => { const [v,l] = Array.isArray(choice) ? choice : [choice,choice]; return `<option value="${esc(v)}" ${String(value ?? "") === String(v) ? "selected" : ""}>${esc(l)}</option>`; }).join("")}</select>`;
  else input = `<input name="${key}" value="${esc(value)}" type="${options.type || "text"}" ${options.min !== undefined ? `min="${options.min}"` : ""} ${options.max !== undefined ? `max="${options.max}"` : ""} ${options.type === "number" ? 'step="'+(key === "max_cloud_cost" ? "0.01" : "1")+'"' : ""} ${options.list ? `list="${options.list}"` : ""} ${options.placeholder ? `placeholder="${esc(options.placeholder)}"` : ""} ${disabled}>`;
  if (options.stepper) input = `<div class="stepper"><button type="button" data-step="-1" data-field="${key}" ${disabled} aria-label="Decrease ${label}">−</button>${input}<button type="button" data-step="1" data-field="${key}" ${disabled} aria-label="Increase ${label}">＋</button></div>`;
  return `<label class="field ${options.full ? "full" : ""}"><span>${label}</span>${input}</label>`;
}
function check(label, key, value) { return `<label class="inline-check"><input type="checkbox" name="${key}" ${value ? "checked" : ""} ${editing && !liveKeys.has(key) ? "disabled" : ""}>${label}</label>`; }
const VARIANTS = [["","Default"],["none","none · no reasoning"],["minimal","minimal · lightest"],["low","low"],["medium","medium"],["high","high"],["xhigh","xhigh"],["max","max"]];
const modelBase = model => String(model || "").split("#")[0];
const variantOf = model => { const parts = String(model || "").split("#"); return parts.length > 1 ? parts.slice(1).join("#") : ""; };
const usesOpenCode = model => { const base = modelBase(model); return base.startsWith("opencode:") || base.startsWith("hosted:opencode/"); };
const CLI_CHOICES = [["claude","Anthropic (Claude Code)"],["codex","OpenAI (Codex)"],["opencode","OpenCode"],["custom","Custom"]];
const cliFor = cli => cli === "custom" ? "opencode" : cli;
const PROVIDER_CLI = {openai:"openai", anthropic:"anthropic", opencode:"opencode", custom:"custom"};
function customProviders() { return meta.providers.filter(provider => !["openai","anthropic","opencode","chatgpt"].includes(provider.name)); }
function providerChoices(choice) {
  if(choice==="opencode") return (meta.agent_models || []).map(model=>["opencode:"+model,(model.startsWith("opencode-go/") ? "Go plan · " : "")+model]);
  const name = {claude:"anthropic", codex:"openai"}[choice] || choice;
  const providers = choice==="custom" ? customProviders() : meta.providers.filter(provider=>provider.name===name);
  return providers.flatMap(provider=>provider.models.map(model=>[provider.name+":"+model, provider.name+":"+model+(provider.ready ? "" : " · key missing")]));
}
function modelChoices(config, choice="openai") {
  const choices = [["","Choose model…"]], seen = new Set([""]);
  const add = (value,label) => { if(!seen.has(value)) { seen.add(value); choices.push([value,label]); } };
  if(choice==="custom") for(const model of localModels) add(model, model+" · local Ollama");
  for(const [value,label] of providerChoices(choice)) add(value,label);
  if(modelBase(config.model) && !seen.has(modelBase(config.model))) choices.push([modelBase(config.model), modelBase(config.model)+" · custom"]);
  return choices;
}
function workerForm(config) {
  const preset = config.rounds==="auto" && config.max_tokens==="auto" ? "automatic" : config.rounds===2 && config.max_size===96 ? "fast" : config.rounds===6 && config.max_size===0 ? "deep" : config.rounds===4 && config.max_size===256 ? "balanced" : "";
  return `<form id="worker-form" class="panel panel-pad"><div class="section-heading"><h2>${editing ? "Tune active session" : "Configure Match"}</h2>${editing ? `<button type="button" class="text-button" data-new-worker>New session →</button>` : ""}</div><div class="preset-row">${["automatic","fast","balanced","deep"].map(mode=>`<button type="button" data-preset="${mode}" class="${preset===mode ? "active" : ""}">${mode[0].toUpperCase()+mode.slice(1)}</button>`).join("")}</div><div class="field-grid">` +
    field("Client", "client", config.client, {choices:[["","All available clients"],...meta.clients.map(client=>[client.name,client.name])]}) +
    field("Library", "library", config.library, {choices:[["","Auto (all libraries)"],...(meta.libraries||[]).map(name=>[name,name])]}) +
    field("Username", "user", config.user) + field("Server", "server", config.server, {full:true,placeholder:"host:8765 or https://server"}) +
    field("Model provider (Match)", "model_provider", matchProvider, {choices:CLI_CHOICES}) +
     `<p class="help-note">Match can use an API key (NVIDIA/OpenAI/etc.), a local Ollama model, or OpenCode. Agent mode is separate and runs a CLI tool.</p>` +
    field("Model", "model", modelBase(config.model), {choices:modelChoices(config, matchProvider),full:true}) +
    field("Or type a model (optional, overrides the list)", "model_custom", "", {placeholder:"provider:model, e.g. nvidia:qwen/qwen2.5-coder-32b-instruct", full:true}) +
    (usesOpenCode(config.model) ? field("Variant (reasoning)", "model_variant", variantOf(config.model), {choices:VARIANTS}) : "") +
    (usesOpenCode(config.model) ? `<p class="help-note">Runs through the signed-in OpenCode CLI — no API key, no key entry here. opencode-go models use your Go plan allowance automatically ($80/mo DeepSeek V4.1 Flash); spend caps do not apply, usage shows in the OpenCode console.</p>` : "") +
    field("Worker loops", "workers", config.workers, {placeholder:"auto or 1–256"}) +
    `</div><p class="help-note">Set worker count above, or use auto to choose per model. Automatic preserves your worker count, chooses rounds and output per function, prioritizes best evidence, and limits targets to 512 bytes. Advanced values override its defaults.</p><details class="form-section"><summary>Advanced controls</summary><div class="field-grid">` +
    field("Rounds per function", "rounds", config.rounds, {placeholder:"auto or 1–100"}) +
    field("Output tokens", "max_tokens", config.max_tokens, {placeholder:"auto or 128–32768"}) + field("Maximum function bytes (0 = unlimited)", "max_size", config.max_size, {type:"number",min:0}) +
    field("Function order", "order", config.order, {choices:["random","auto","best","matched","unmatched","easiest"]}) + field("Strategy", "strategy", config.strategy, {choices:["auto","direct","structured","reference"]}) +
    field("Thinking", "thinking", config.thinking, {choices:["auto","enabled","disabled"]}) + field("Reasoning effort", "reasoning_effort", config.reasoning_effort, {choices:[["","Provider default"],"auto","low","medium","high","max"]}) +
    field("Minimum score", "min_score", config.min_score, {type:"number",min:0,max:100,placeholder:"Any"}) + field("Maximum score", "max_score", config.max_score, {type:"number",min:0,max:100,placeholder:"Any"}) +
    field("Diverse candidates", "diverse_candidates", config.diverse_candidates, {type:"number",min:1,max:16}) + field("Cloud concurrency", "cloud_concurrency", config.cloud_concurrency, {placeholder:"auto or 1–256"}) +
    field("Lease mode", "lease_mode", config.lease_mode, {choices:["function","family","unit"]}) + field("Unit name", "unit_name", config.unit_name) + field("Family fingerprint", "family_id", config.family_id, {full:true}) +
    field("Target addresses (comma separated)", "addresses", (config.targets || []).map(row=>row.addr).join(", "), {full:true,placeholder:"00401000, 00401200"}) +
    `<div class="field full button-row">${check("Rev.ng hints", "use_revng", config.use_revng)}${check("Guided mutations", "guided_mutations", config.guided_mutations)}${check("Near-match repair", "near_repair", config.near_repair)}${check("Source-only (no AI)", "source_only", config.source_only)}</div></div><h3 class="form-section">Cloud budgets</h3><div class="field-grid">` +
    field("Request cap", "max_cloud_requests", config.max_cloud_requests, {type:"number",min:1,placeholder:"Unlimited"}) + field("Token cap", "max_cloud_tokens", config.max_cloud_tokens, {type:"number",min:1,placeholder:"Unlimited"}) + field("Estimated spend cap ($)", "max_cloud_cost", config.max_cloud_cost, {type:"number",min:0.01,placeholder:"Requires configured pricing",full:true}) +
    `</div><p class="help-note">Budget edits preserve usage already spent. In-flight requests continue. Unknown prices cannot establish actual spend.</p></details><div class="consent">${check("Allow cloud prompts for this session", "cloud_allowed", config.cloud_allowed)}<p>Bounded assembly, symbols and source hints leave this PC. Provider keys and executable files stay local.</p></div><div class="form-footer"><span class="tiny muted">${editing ? "Edits apply before each loop's next function." : "Compilation and byte comparison stay local."}</span>${button(editing ? "Apply changes" : "Start Match", 'type="submit"')}</div><div class="button-row form-section">${button("Install / sign in",'type="button" data-agent-setup="current"',true)}<button type="button" class="text-button" id="save-preset">Save preset</button><select id="saved-presets" aria-label="Load a saved preset"><option value="">Load saved preset…</option>${Object.keys(meta.preferences.presets).map(name=>`<option>${esc(name)}</option>`).join("")}</select><button type="button" class="text-button" id="refresh-models">Refresh models</button></div></form>`;
}
let matchProvider="codex";
let workerMode="function", controlsOpen=true, workerRun="", chatFollow=true, chatSignature="", chatCompact=false, workerLoop="";
function workers(config) {
  if(meta.agent_models===undefined)act(loadOpenCodeModels);
  const current=jobs.find(job=>job.id===editing);
  if(!current || !active(current))editing=null;
  return `<div id="worker-chat" class="worker-chat" tabindex="0" role="log" aria-label="Live worker activity"><div id="worker-chat-rows"></div></div><button id="jump-live" class="jump-live" hidden>↓ Jump back to live</button><footer class="worker-footer"><div id="worker-tabs" class="worker-tabs" role="tablist" aria-label="Worker sessions"></div><div class="worker-footer-controls"><div id="worker-status" class="worker-live-bar"></div><div class="chat-toolbar"><select id="worker-run" aria-label="Worker session"><option value="">All sessions</option>${jobs.filter(j=>isWorker(j)).map(j=>`<option value="${j.id}" ${workerRun===j.id ? "selected" : ""}>${esc(j.config.client)} · ${j.id.slice(0,6)}</option>`).join("")}</select><select id="worker-loop" aria-label="Worker loop"><option value="">All loops</option>${Array.from({length:Math.max(1,...jobs.filter(j=>isWorker(j)).map(j=>Math.max(Object.keys(j.slots).length,Number(j.config.workers)||1)))},(_,i)=>`<option value="${i}" ${workerLoop===String(i) ? "selected" : ""}>Worker ${i+1}</option>`).join("")}</select><button class="text-button" id="chat-compact">${chatCompact ? "Regular" : "Compact"}</button><button class="text-button" id="chat-follow">${chatFollow ? "Live ↓" : "Latest ↓"}</button><button class="text-button" data-restart-workers>Restart offline / failed</button><button class="text-button" data-configure>Configure</button><button class="text-button" data-new-session>+ New</button></div></div></footer><aside class="worker-drawer ${controlsOpen ? "open" : ""}" aria-label="Worker configuration"><div class="drawer-heading"><h2>${editing ? "Session controls" : "New session"}</h2><button class="text-button" data-close-controls>Close ×</button></div>${editing ? workerForm(current.config) : `<div class="button-row form-section"><button class="text-button ${workerMode==='function' ? 'active' : ''}" data-worker-mode="function">Match</button><button class="text-button ${workerMode==='agent' ? 'active' : ''}" data-worker-mode="agent">Agent</button></div>`+(workerMode==="agent" ? agentAutomatic() : workerForm(config || meta.initial))}</aside>`;
}
function highlightCode(code) {
  return String(code).split(/(\/\/[^\n]*|"(?:\\.|[^"\\])*"|\b(?:void|int|float|double|char|bool|class|struct|return|if|else|for|while|const|static|unsigned|signed|auto|nullptr|true|false|sizeof)\b|\b\d+\b)/g).map(part=>{const cls=part.startsWith("//") ? "comment" : part.startsWith('"') ? "string" : /^\d+$/.test(part) ? "number" : /^(void|int|float|double|char|bool|class|struct|return|if|else|for|while|const|static|unsigned|signed|auto|nullptr|true|false|sizeof)$/.test(part) ? "keyword" : "";return cls ? `<span class="syntax-${cls}">${esc(part)}</span>` : esc(part);}).join("");
}
function codeBlock(code,label="C++") { return `<div class="chat-code"><div>${esc(label)}<button class="text-button" data-copy-code>Copy</button></div><pre><code>${label==="C++" ? highlightCode(code) : esc(code)}</code></pre></div>`; }
function terminalMessage(row, functions, compact=false) {
  const stamp=new Date(row.time*1000).toLocaleTimeString("en-GB"), worker=row.slot===undefined ? "roc" : "w"+(row.slot+1);
  const fn=functions.get(row.job+":"+row.slot);
  let marker="·", text=logText(row), extra="", kind=row.event;
  if(row.event==="job_finished" && row.score===100 && (row.new_exact===false || row.previous===100)) {
    kind="job_finished no-gain";text=`${row.client} ${row.addr} · already exact`;
  }
  else if(row.event==="tool_run") {
    kind="tool-call";marker="";
    const messages=row.tool_rows.map(logText), starts=messages.filter(t=>/^\s*> /.test(t)).length;
    const ends=messages.filter(t=>/^\s*< \d/.test(t)), returns=messages.filter(t=>/^Command finished /.test(t));
    const count=Math.max(starts,ends.length,returns.length);
    const seconds=ends.reduce((total,t)=>total+Number(t.match(/< ([\d.]+)s/)?.[1] || 0),0);
    text=count ? `${Math.max(ends.length,returns.length)>=count ? "Ran" : "Running"} ${count} command${count===1 ? "" : "s"}${seconds ? " · "+Math.round(seconds)+"s" : ""}` : "Thinking";
    extra=messages.map(t=>/^Thinking · /.test(t) ? `<p class="thought-text">${esc(t.slice(11))}</p>` : codeBlock(t.trim().replace(/^> /,""),/^\s*> /.test(t) ? "Command" : "Output")).join("");
    if(returns.some(t=>/^Command finished .*exit (?!0\b)-?\d+/.test(t)))text+=" · error";
  }
  else if(/^Thinking · /.test(text)){kind="thinking";marker="";extra=`<p class="thought-text">${esc(text.slice(11))}</p>`;text="Thinking";}
  else if(row.event==="job_started") {marker="›";text=`${row.client} ${row.addr} ${row.size ?? "?"} B ${row.unit || ""} · best ${row.previous ?? row.score ?? "?"}%${row.area ? " · "+row.area : ""}`;}
  else if(row.event==="job_finished") {kind+=" "+(row.score===100 ? "exact" : row.score>row.previous ? "improved" : "no-gain");marker=row.score===100 ? "✓" : row.score>row.previous ? "↑" : "·";text=`${row.client} ${row.addr}${row.supercompact ? " · "+(row.size ?? "?")+" B" : " "+(row.unit || fn?.unit || "")+" · "+(row.size ?? "?")+" B"} · ${row.previous}% → ${row.score}%${row.score===100 ? " EXACT" : row.score<=row.previous ? " no gain" : " improved"}${row.seconds===undefined ? "" : " · "+row.seconds+"s"}`;if(row.score===100)extra=`<div class="match-success">✓ Exact match</div>`;else if(row.score>row.previous)extra=`<div class="match-success improvement">↑ Improved ${row.previous}% → ${row.score}%</div>`;}
  else if(row.event==="benchmark") {marker="≡";text=`${row.matched} exact · ${row.improved} improved${row.errors ? " · "+row.errors+" errors" : ""}`;if(row.matched>0)kind+=" matched-note";}
  else if(row.event==="compile") {
    marker="$";const runs=row.compile_runs || [row],failed=runs.filter(r=>r.exit_code!==0).length;
    text=`compile${runs.length>1 ? " ×"+runs.length : ""} · ${failed ? failed+" failed" : "ok"}`;
    extra=runs.map((r,i)=>(runs.length>1 ? `<div class="compile-attempt">Attempt ${i+1} · exit ${r.exit_code}</div>` : "")+codeBlock(r.argv.map(a=>/\s/.test(a) ? JSON.stringify(a) : a).join(" "),"Command")+(r.output ? codeBlock(r.output,"Output") : "")).join("");
  }
  else if(["draft","candidate"].includes(row.event)) {marker=row.event==="draft" ? "◇" : "↑";text=row.event==="draft" ? `draft · round ${row.round}` : `verified candidate · ${row.score}%`;extra=codeBlock(row.code);}
  else if(/^\s*> /.test(text)) {marker="$";kind="tool-call";extra=codeBlock(text.trim().slice(2),"Command");text=text.trim().slice(2);}
  else if(/^\s*< \d/.test(text)) {kind="tool-call";text=text.trim().slice(2);}
  else if(/^Command finished /.test(text)) {kind="tool-call";const newline=text.indexOf("\n");if(newline>=0){extra=codeBlock(text.slice(newline+1),"Output");text=text.slice(0,newline);}if(/exit (?!0\b)-?\d+/.test(text)){marker="!";kind="error";}}
  else if(text.includes("```")) {let end=0;const blocks=[];for(const match of text.matchAll(/```([^\n]*)\n([\s\S]*?)```/g)){blocks.push(`<p>${esc(text.slice(end,match.index))}</p>`,codeBlock(match[2],match[1].trim()||"Code"));end=match.index+match[0].length;}blocks.push(`<p>${esc(text.slice(end))}</p>`);extra=blocks.join("");text=text.split("```")[0].trim().split("\n")[0]||"Agent code";}
  else if(/generated source[^\n]*:\n/.test(text)) {extra=codeBlock(text.slice(text.indexOf("\n")+1));text=text.slice(0,text.indexOf("\n")).replace(/generated source \(final (\d+)%\):/,"source · $1%");}
  else if(/\bserver verified exact\b/i.test(text) && !/\b(?:no|already|not)\b/i.test(text)) {marker="✓";kind="matched-note";}
  else if(row.event==="error"||/^(Agent error:|Error:|Traceback|Blocked:|Command finished .*exit (?!0\b)-?\d+)|\bERROR\s+\w/i.test(text.split("\n")[0])) {marker="!";kind="error";}
  if(row.event==="job_finished" && row.server_gains && row.new_exact!==false){text=`${row.client} ${row.addr} · ${row.previous}% → ${row.score}%${row.score===100 ? " EXACT" : ""}`;extra="";}
  const limit=kind==="tool-call" ? 90 : 140;
  if(text.length>limit || text.includes("\n")) {if(!extra)extra=codeBlock(text,"Output");text=text.split("\n")[0].slice(0,limit)+(text.split("\n")[0].length>limit ? "…" : "");}
  const content=`<span class="terminal-marker">${marker}</span><span class="terminal-text">${esc(text.trim())}</span>`;
  return `<article class="terminal-row ${esc(kind)}" data-key="${esc(row.job+":"+row.seq)}"><time>${stamp}</time><span class="terminal-worker">${worker}</span>${extra ? `<details ${!compact && ["draft","candidate"].includes(row.event) ? "open" : ""}><summary>${content}</summary>${extra}</details>` : `<div>${content}</div>`}</article>`;
}
function groupToolRows(rows) {
  const grouped=[];
  for(const row of rows) {
    const text=logText(row), last=grouped.at(-1);
    const tool=row.event==="log" && /^\s*> |^\s*< \d|^Command finished |^Thinking · |^Let me (?:check|try|read|look|understand|analyze|think|use|fix)\b/.test(text);
    if(tool && last?.event==="tool_run" && row.job===last.job && row.slot===last.slot)last.tool_rows.push(row);
    else grouped.push(tool ? {...row,event:"tool_run",tool_rows:[row]} : row);
  }
  return grouped;
}
function setChatFollow(enabled) {
  chatFollow=enabled;
  const button=$("#chat-follow"),jump=$("#jump-live");
  if(button)button.textContent=enabled ? "Live ↓" : "Latest ↓";
  if(jump)jump.hidden=enabled;
}
function scrollToLatest(node, smooth=false) {
  requestAnimationFrame(()=>{
    if(!node.isConnected || (node.id==="worker-chat"&&!chatFollow) || (node.id==="log-scroll"&&!follow))return;
    node.dataset.liveScrolling="1";
    node.scrollTo({top:node.scrollHeight,behavior:smooth && !matchMedia("(prefers-reduced-motion: reduce)").matches ? "smooth" : "instant"});
    setTimeout(()=>delete node.dataset.liveScrolling,500);
  });
}
function updateFeed(node, items, following, smooth) {
  const viewport=node.id==="worker-chat-rows"||node.id==="log-rows" ? node.parentElement : node;
  const top=viewport.scrollTop,edge=viewport.getBoundingClientRect().top,anchor=[...node.children].find(child=>child.getBoundingClientRect().bottom>edge),offset=anchor ? anchor.getBoundingClientRect().top-edge : 0;
  const existing=new Map([...node.children].map(child=>[child.dataset.key,child]));
  let next=node.firstElementChild;
  for(const [key,html] of items) {
    let child=existing.get(key);
    if(!child) {const template=document.createElement("template");template.innerHTML=html;child=template.content.firstElementChild;child.dataset.key=key;node.append(child);}
    else if(child.dataset.html!==html) {const opened=[...child.querySelectorAll("details")].map(d=>d.open);const template=document.createElement("template");template.innerHTML=html;const replacement=template.content.firstElementChild;replacement.dataset.key=key;replacement.querySelectorAll("details").forEach((d,i)=>d.open=opened[i]||false);if(child===next)next=replacement;child.replaceWith(replacement);child=replacement;}
    if(child!==next)node.insertBefore(child,next);
    next=child.nextElementSibling;child.dataset.html=html;existing.delete(key);
  }
  for(const child of existing.values())child.remove();
  if(following)scrollToLatest(viewport,smooth);
  else {
    const retained=anchor && [...node.children].find(child=>child.dataset.key===anchor.dataset.key);
    if(retained)viewport.scrollTop+=retained.getBoundingClientRect().top-viewport.getBoundingClientRect().top-offset;
    else viewport.scrollTop=top;
  }
}
// Tab label: the model (or CLI when it uses its default), not the random run id.
function tabModel(job) {
  const args=job.args||[],i=args.indexOf("--model"),c=job.config||{};
  const model=String(c.model||(i<0 ? "" : args[i+1])||"").split("#")[0];
  return model.split("/").pop()||c.cli||(args[0]==="agent" ? args[1] : "")||job.id.slice(0,5);
}
function renderWorkerChat() {
  const node=$("#worker-chat");if(!node)return;
  const workerJobs=jobs.filter(j=>isWorker(j));
  const tabs=$("#worker-tabs"),tabSignature=workerJobs.map(j=>j.id+j.status).join()+workerRun;
  if(tabs.dataset.signature!==tabSignature) {tabs.innerHTML=`<button role="tab" aria-selected="${!workerRun}" class="worker-tab ${!workerRun ? "selected" : ""}" data-worker-tab="all">All workers</button>`+workerJobs.slice(-12).map(j=>`<div class="worker-tab-group"><button role="tab" aria-selected="${workerRun===j.id}" class="worker-tab ${workerRun===j.id ? "selected" : ""}" data-worker-tab="${j.id}"><span class="dot ${esc(j.status)}"></span>${esc(j.config.client)} <span title="${esc(j.id)}">${esc(tabModel(j))}</span><small>${esc(j.status)}</small></button>${!active(j) ? `<button class="worker-tab-close" data-remove-run="${j.id}" aria-label="Remove finished run ${j.id}" title="Remove from run history">×</button>` : ""}</div>`).join("");tabs.dataset.signature=tabSignature;}
  const status=$("#worker-status"),statusHTML=workerCards();if(status.innerHTML!==statusHTML)status.innerHTML=statusHTML;
  const loopCount=workerJobs.filter(j=>active(j)&&(!workerRun||j.id===workerRun)).reduce((sum,j)=>sum+Object.keys(j.slots).length,0);
  const supercompact=loopCount>3, compact=chatCompact || supercompact;
  node.classList.toggle("compact",compact);node.classList.toggle("supercompact",supercompact);
  $("#chat-compact").textContent=supercompact ? "Supercompact · auto" : chatCompact ? "Regular" : "Compact";
  const foldSource=compact;
  const ids=new Set(workerJobs.map(job=>job.id));
  const rows=logs.filter(r=>ids.has(r.job)&&(!workerRun||r.job===workerRun)&&(workerLoop===""||String(r.slot)===workerLoop||r.event==="benchmark")&&(compact ? (jobs.find(j=>j.id===r.job)?.kind==="agent_worker" || r.startup || ["job_finished","benchmark","error","rejected"].includes(r.event)) : !["control","applied","usage"].includes(r.event))).slice(-180);
  const signature=compact+":"+supercompact+":"+rows.map(r=>r.job+":"+r.seq).join();
  setChatFollow(chatFollow);
  const viewFilter=workerRun+":"+workerLoop+":"+compact+":"+supercompact;
  if(chatSignature===signature && $("#worker-chat-rows").children.length)return;
  const functions=new Map(),items=[];
  const grouped=[];
  for(const row of groupToolRows(rows)) {
    const last=grouped[grouped.length-1];
    if(row.event==="compile" && last?.event==="compile" && row.slot===last.slot && row.job===last.job)last.compile_runs.push(row);
    else grouped.push(row.event==="compile" ? {...row,compile_runs:[row]} : row);
  }
  for(const row of grouped) {
    if(row.event==="job_started")functions.set(row.job+":"+row.slot,row);
    if(row.event==="log" && !row.startup && /auto-think:|^\[.*best so far|Privacy:|Cloud model:|^thinking disabled for remaining rounds|^no improvement/.test(row.message.trim()))continue;
    items.push([row.job+":"+row.seq+":"+foldSource,terminalMessage(supercompact ? {...row,supercompact:true} : row,functions,foldSource)]);
  }
  if(!items.length)items.push(["empty",empty(loopCount ? "Working…" : "Ready for work", compact ? "One line per completed function. Benchmarks every 30 seconds while functions finish." : "Configure a session. Function activity and verified source appear here.")]);
  updateFeed($("#worker-chat-rows"),items,chatFollow,!!chatSignature);
  chatSignature=signature;node.dataset.viewFilter=viewFilter;
}
function workerCards() {
  const selected=jobs.find(j=>j.id===workerRun), current=selected || jobs.find(j=>isWorker(j)&&active(j));
  if(!current)return '<span class="muted">Idle</span>';
  return `<div class="live-session"><span class="session-summary">${badge(current.status)} <b>${Object.keys(current.slots).length}</b> loops · <b>${current.matched}</b> exact · <b>${current.improved}</b> improved · ${current.attempted} ${current.kind==="agent_worker" ? "server gains" : "tried"}</span>${active(current) ? (current.kind==="worker" ? `<button class="text-button" data-action="${current.status==="paused" ? "resume" : "pause"}" data-id="${current.id}" ${current.status==="stopping" ? "disabled" : ""}>${current.status==="paused" ? "Resume" : "Pause"}</button>` : "")+`${endRun(current)}<button class="text-button" data-action="kill" data-id="${current.id}" aria-label="Stop immediately">×</button>` : ""}</div>`;
}
function commands() {
  const command = meta.commands.find(command=>command.name===selectedCommand), names = meta.clients.map(client=>client.name);
  return heading("", "Commands", "") + `<div id="command-progress">${commandProgress()}</div>${["Start here","Match and submit","Advanced"].map(group=>`<details class="form-section" ${group==="Advanced" && command.group!==group ? "" : "open"}><summary>${group}</summary><div class="card-grid">${meta.commands.filter(item=>(item.group||"Advanced")===group).map(item=>`<button class="command-card ${item.name===selectedCommand ? "active" : ""}" data-command="${item.name}"><div class="cmd">roc ${item.name}</div><h3>${esc(item.title)}</h3></button>`).join("")}</div></details>`).join("")}<form id="command-form" class="panel panel-pad command-settings"><h2>${command.title}</h2><div class="field-grid form-section">` +
    (command.target !== "none" ? field("Client", "client", meta.initial.client || (command.target==="one" ? names[0] : "all"), {choices:[...(command.target==="one" ? [] : [["all","All clients"]]),...names.map(name=>[name,name])]}) : "") +
    (["repair","check"].includes(command.name) ? field("Function address (optional)", "addr", "", {placeholder:"00401000"}) : "") +
    (command.name==="libs" ? field("Recipes", "recipes", "all", {placeholder:"all or comma-separated recipe names"}) : "") +
    (command.name==="research" ? field("Action","research_action","list",{choices:[["list","List recipes"],["plan","Plan"],["run","Run"],["log","Findings log"]]}) + field("Recipe","recipe","",{choices:[["","Choose recipe"],...(meta.recipes||[]).map(name=>[name,name])]}) : "") +
    (command.name==="repair" ? field("Source limit", "limit", 20, {type:"number",min:1})+field("Minimum score", "min_score", 80, {type:"number",min:0,max:100})+check("Try permutations", "permute", false) : "") +
    (command.name==="install" ? check("Accept compiler downloads", "accept_downloads", false) : "") +
    (command.name==="agent" ? field("Agent CLI", "cli", "claude", {choices:[["claude","Claude Code"],["codex","Codex"],["opencode","OpenCode"]]})+field("Goal", "goal", "Match as many open 2008-06 RakNet functions as you can", {placeholder:"What should the agent do?",full:true})+field("Time limit (minutes)", "minutes", 120, {type:"number",min:1,max:600}) : "") + `</div><div id="command-preview" class="command-preview">roc ${command.name}</div><div class="form-footer"><span class="tiny muted">${command.name==="mass" ? "Static libs → STL → recipes → analyze → auto" : "Output appears in the console below."}</span>${button("Run command",'type="submit"')}</div></form>`;
}
function experimentMemory(s) {
  if(!s)return `<p class="muted">Loading experiments…</p>`;
  const rows=[...(s.shared_recent||[]),...(s.recent||[]),...(s.tools||[]).slice(-200)], seen=new Set();
  const attempts=rows.sort((a,b)=>String(b.date||"").localeCompare(String(a.date||""))).filter(r=>{const key=JSON.stringify(r);if(seen.has(key))return false;seen.add(key);return true;});
  return `<div class="panel panel-pad"><div class="section-heading"><h2>Experiments / agent lessons</h2>${button("Refresh",'data-worker-memory-refresh',true)}</div>${attempts.length ? `<table class="run-list"><thead><tr><th>Experiment / agent report</th><th>Result</th><th>Score</th></tr></thead><tbody>${attempts.map(r=>`<tr><td>${esc(r.hypothesis||r.change||r.library||r.area||r.kind||"Attempt")}<br><small>${esc(r.date||"")} · ${esc(r.cli||r.model||r.kind||"")}</small><details class="experiment-details"><summary>Full text / all fields</summary>${Object.entries(r).map(([key,value])=>`<div><strong>${esc(key.replaceAll("_"," "))}</strong><pre class="history-full-text">${esc(typeof value==="string" ? value : JSON.stringify(value,null,2))}</pre></div>`).join("")}</details></td><td>${esc(r.outcome||"Recorded")}${r.server_confirmed ? " · verified" : ""}</td><td>${esc(r.before??"—")} → ${esc(r.after??"—")}%${r.candidate!=null ? `<br><small>candidate ${esc(r.candidate)}%</small>` : ""}</td></tr>`).join("")}</tbody></table>` : `<p class="muted">No experiments yet.</p>`}</div>`;
}
function agentHistory() {
  const runs=jobs.filter(j=>j.kind==="agent_worker"||j.args?.[0]==="agent").slice().reverse();
  return `<div class="panel panel-pad"><h2>Agent runs / full logs</h2>${runs.length ? runs.map(j=>`<div class="agent-history-run"><span>${esc(j.title)} · ${esc(j.config?.model||"CLI default")} · ${esc(j.id)}</span> ${badge(j.status)} ${button("Full log",`data-agent-history-log="${esc(j.id)}"`,true)}</div>`).join("") : `<p class="muted">No agent runs yet.</p>`}${agentHistoryLog ? `<div class="form-section"><div class="section-heading"><h3>${esc(agentHistoryLog.title)}</h3>${button("Refresh log",`data-agent-history-log="${esc(agentHistoryLog.id)}"`,true)}</div><pre class="history-full-text">${esc(agentHistoryLog.text)}</pre></div>` : ""}</div>`;
}
async function loadAgentHistoryLog(id) {
  const response=await fetch("/api/log?id="+encodeURIComponent(id),{headers:{"X-ROC-Token":token||""}});
  if(!response.ok)throw new Error("Could not load agent log");
  const raw=await response.text();
  const text=raw.split(/\r?\n/).filter(Boolean).map(line=>{
    try {
      const row=JSON.parse(line), time=row.time ? new Date(row.time*1000).toLocaleString() : "";
      return `[${time}${row.slot!=null ? ` · agent ${Number(row.slot)+1}` : ""} · ${row.event||"log"}]\n`+(row.message??JSON.stringify(row,null,2));
    } catch {return line;}
  }).join("\n\n");
  agentHistoryLog={id,title:jobs.find(j=>j.id===id)?.title||id,text:text||"No saved output yet."};
  if(page==="history")render();
}
async function loadWorkerMemory(sync=false) {workerMemory=await api(sync ? "agent-memory-sync" : "agent-memory",sync ? {} : undefined);if(page==="history")render();}
function readAgentAuto() {
  const form=$("#agent-auto-form"), mode=form.dataset.mode;
  const presets={
    automatic:{workers:2,jobs:24,minutes:120,batch_size:4,batch_minutes:30,max_size:512},
    fast:{workers:2,jobs:12,minutes:30,batch_size:4,batch_minutes:10,max_size:256},
    balanced:{workers:2,jobs:24,minutes:120,batch_size:4,batch_minutes:30,max_size:512},
    deep:{workers:2,jobs:48,minutes:240,batch_size:4,batch_minutes:80,max_size:0}
  };
  agentAutoConfig={...agentAutoConfig,...presets[mode],mode,individual:false};
  for(const key of ["client","user","server","cli","model","goal"])agentAutoConfig[key]=form.elements[key].value.trim();
  const typed=form.elements.model_custom?.value.trim();
  if(typed)agentAutoConfig.model=typed;
  agentAutoConfig.workers=Number(form.elements.workers.value);
  if(cliFor(agentAutoConfig.cli)==="opencode" && form.elements.model && form.elements.variant) {
    const base=String(agentAutoConfig.model||"").split("#")[0];
    agentAutoConfig.model=form.elements.variant.value ? base+"#"+form.elements.variant.value : base;
  }
  return agentAutoConfig;
}
function agentAutomatic() {
  const c={client:meta.initial.client||"",user:meta.initial.user,server:meta.initial.server,...agentAutoConfig};
  const mode=c.mode || (c.minutes===30 ? "fast" : c.minutes===240 ? "deep" : "automatic");
  const agentModels={
    opencode:[["","CLI default"],...(meta.agent_models || []).map(model=>[model,(model.startsWith("opencode-go/") ? "Go plan · " : "")+model])],
    codex:[["","CLI default"],["gpt-6.1-sol","GPT-6.1 Sol"],["gpt-6-astra","GPT-6 Astra"],["gpt-6-sol","GPT-6 Sol"],["gpt-6-luna","GPT-6 Luna"],["gpt-5.6-sol","GPT-5.6 Sol"],["gpt-5.6-terra","GPT-5.6 Terra"],["gpt-5.6-luna","GPT-5.6 Luna"]],
    claude:[["","CLI default"],["claude-opus-4-6","Claude Opus 4.6"],["claude-sonnet-4-6","Claude Sonnet 4.6"],["claude-haiku-4-5","Claude Haiku 4.5"]],
    custom:[["","Choose provider model"],...customProviders().flatMap(provider=>provider.models.map(model=>[provider.name+"/"+model,provider.name+"/"+model+(provider.ready ? "" : " · key missing")]))]
  };
  const agentModelChoices=[...(agentModels[c.cli]||agentModels.claude)];
  if(modelBase(c.model)&&!agentModelChoices.some(([value])=>value===modelBase(c.model)))agentModelChoices.push([modelBase(c.model),modelBase(c.model)+" · custom"]);
  return `<form id="agent-auto-form" data-mode="${esc(mode)}" class="panel panel-pad"><div class="section-heading"><h2>Configure Agent</h2></div><div class="preset-row">${["automatic","fast","balanced","deep"].map(value=>`<button type="button" data-agent-mode="${value}" class="${mode===value ? "active" : ""}">${value[0].toUpperCase()+value.slice(1)}</button>`).join("")}</div><div class="field-grid">` +
    field("Client","client",c.client,{choices:[["","All clients"],...meta.clients.map(client=>[client.name,client.name])]}) +
    field("Username","user",c.user) + field("Server","server",c.server,{full:true,placeholder:"host:8765 or https://server"}) +
    field("Agent CLI","cli",c.cli,{choices:CLI_CHOICES}) +
    field("Model","model",modelBase(c.model),{choices:agentModelChoices}) +
    field("Or type a model (optional, overrides the list)","model_custom","",{placeholder:"provider/model, e.g. opencode-go/deepseek-v4.1-flash",full:true}) +
    (cliFor(c.cli)==="opencode" ? field("Variant (reasoning)","variant",variantOf(c.model),{choices:VARIANTS}) : "") +
    (cliFor(c.cli)==="opencode" ? `<p class="help-note">log in at settings to use CLI or see models or click install/sign in</p>` : "") +
    field("Goal","goal",c.goal||"",{full:true,placeholder:"Optional; blank runs automatic matching"}) +
    field("Worker loops","workers",c.workers,{type:"number",min:1,max:8}) +
    `</div><div class="button-row form-section">${button("Install / sign in",'type="button" data-agent-setup="current"',true)}${button("Refresh models",'type="button" data-agent-refresh',true)}<button type="button" class="text-button" id="save-agent-preset">Save preset</button><select id="saved-agent-presets" aria-label="Load a saved agent preset"><option value="">Load saved preset…</option>${Object.keys(meta.preferences.agent_presets||{}).map(name=>`<option>${esc(name)}</option>`).join("")}</select></div><div class="form-footer">${button("Start Agent",'type="submit"')}</div></form>`;
}
function settings() {
  return heading("", "Settings", "Interface, theme, provider credentials, and dashboard lifecycle.") + `<div class="settings-stack"><form id="preferences-form" class="panel panel-pad"><h2>When a roconstruct:// link opens</h2><p class="help-note">Choose how website work links launch. “Ask every time” offers terminal or webpage before setup.</p><div class="field-grid">${field("URI interface", "uri_mode", meta.uri_mode, {choices:[["ask","Ask every time"],["terminal","Terminal"],["web","Webpage"]]})}${field("Appearance", "theme", meta.preferences.theme, {choices:["dark","light"]})}</div><div class="form-footer">${button("Save preferences", 'type="submit"')}</div></form><div class="panel panel-pad"><h2>ChatGPT plan</h2><p class="help-note">${meta.providers.find(p=>p.name==="chatgpt")?.ready ? "Signed in. Choose a chatgpt: model in your worker settings." : "Sign in from a terminal in this fork: roc chatgpt login"}</p><p class="help-note">Uses your existing subscription limits. <a href="https://chatgpt.com/settings/usage" target="_blank" rel="noopener noreferrer">Manage usage and credit permission</a></p></div><div class="panel panel-pad"><h2>OpenCode CLI</h2><p class="help-note">${meta.providers.find(p=>p.name==="opencode")?.ready ? "Installed. Match and Agent modes list its signed-in models — no API key, no key stored here." : "Not installed. Run npm i -g opencode-ai, then opencode auth login; Match and Agent modes then list its models."}</p><p class="help-note">Go plan subscribers: opencode-go models (DeepSeek V4.1 Flash, GLM, Kimi…) draw on the plan's monthly allowance automatically ($80/mo DeepSeek V4.1 Flash on Go). Pick them from any model dropdown; a USD spend cap does not apply to them.</p></div><form id="provider-form" class="panel panel-pad"><h2>Provider credentials</h2><p class="help-note">Stored in ROC's user-local secrets file. Keys never enter run history or frontend storage.</p><div class="field-grid">${field("Provider", "provider", "", {choices:meta.providers.filter(provider=>provider.auth==="api-key").map(provider=>[provider.name,provider.name+(provider.ready ? " · ready" : " · key missing")])})}${field("API key", "key", "", {type:"password"})}</div><div class="form-footer">${button("Save key", 'type="submit"')}</div></form><div class="panel panel-pad"><h2>Session & lifecycle</h2><p class="help-note">Browser tabs may close freely. Dashboard process owns jobs. Exit stops active process trees. Provider requests already sent may still bill.</p><button class="button secondary" id="exit-dashboard">Exit ROC dashboard</button></div></div>`;
}
async function loadOpenCodeModels(force=false) {
  if(!force && meta.agent_models!==undefined)return;
  try{meta.agent_models=await api("agent-models");}
  catch{meta.agent_models=[];}
  if(page!=="workers")return;
  if($("#agent-auto-form"))readAgentAuto();
  render($("#worker-form") ? readWorker() : undefined);
}
function render(config) {
  if (!meta) return;
  document.title=page==="cpu" ? "Servers" : "RoConstruct Dashboard";
  const historyOpen=new Set([...document.querySelectorAll("[data-history-section][open]")].map(node=>node.dataset.historySection));
  const expanded=new Set([...document.querySelectorAll("[data-cpu-detail][open]")].map(n=>n.dataset.cpuDetail)), cpuScroll=$("#main").scrollTop;
  document.querySelectorAll(".sidebar [data-page]").forEach(button=>button.classList.toggle("active",button.dataset.page===page));
  $("#page-name").textContent = {overview:"Overview",workers:"Workers",cpu:"Servers",commands:"Commands",history:"History",settings:"Settings"}[page];
  $("#main").innerHTML = page==="cpu" ? cpuPage() : page==="overview" ? overview() : page==="workers" ? workers(config) : page==="commands" ? commands() : page==="history" ?
    heading("", "History", "")+`<details class="form-section" data-history-section="runs" ${historyOpen.has("runs") ? "open" : ""}><summary>Runs</summary><div id="history-runs">${runTable([...jobs].reverse())}</div></details>`+
    `<details class="form-section" data-history-section="agents" ${historyOpen.has("agents") ? "open" : ""}><summary>Agents / full logs</summary>${agentHistory()}</details>`+functionsPage()+`<details class="form-section" data-history-section="experiments" ${historyOpen.has("experiments") ? "open" : ""}><summary>Experiments</summary>${experimentMemory(workerMemory)}</details>` : settings();
  if(page==="history") $("#main").scrollTop=cpuScroll;
  if(page==="cpu") {document.querySelectorAll("[data-cpu-detail]").forEach(n=>{n.open=expanded.has(n.dataset.cpuDetail);});$("#main").scrollTop=cpuScroll;}
  document.body.classList.toggle("servers-page",page==="cpu");
  document.body.classList.toggle("workers-page",page==="workers");
  if (page==="workers") { $("#worker-status").innerHTML=workerCards();renderWorkerChat(); }
  if (page==="commands") {act(previewCommand);act(()=>loadCpu(true));}
  if(page==="history") {renderFunctionList();renderFunctionDetail();}
}
function navigate(next, config) { page=next; if(next!=="workers") editing=null; render(config); if(next==="cpu")act(()=>loadCpu(true)); if(next==="history") {act(loadWorkerMemory);act(loadFunctions);} $("#main").scrollTop=0; }
function readWorker() {
  const form=$("#worker-form"), config={...(editing ? jobs.find(job=>job.id===editing).config : meta.initial)};
  for(const input of form.querySelectorAll("[name]")) {
    const key=input.name;
    if(key==="model_custom") { if(!input.disabled && input.value.trim()) config.model=input.value.trim(); continue; }
    if(input.disabled || key==="addresses" || key==="model_variant" || key==="model_provider") continue;
    config[key]=input.type==="checkbox" ? input.checked : ["workers","rounds","max_tokens","cloud_concurrency"].includes(key) && input.value==="auto" ? "auto" : numeric.has(key) ? (input.value==="" && nullable.has(key) ? null : Number(input.value)) : (input.value==="" && nullable.has(key) ? null : input.value);
  }
  const modelParts=String(config.model||"").split("#");
  if((modelParts[0].startsWith("opencode:")||modelParts[0].startsWith("hosted:opencode/")) && form.elements.model && form.elements.model_variant)
    config.model=form.elements.model_variant.value ? modelParts[0]+"#"+form.elements.model_variant.value : modelParts[0];
  if(!editing) { const addresses=form.elements.addresses.value.split(/[,\s]+/).filter(Boolean).map(value=>value.toLowerCase().replace(/^0x/,"")); config.targets=addresses.length ? addresses.map(addr=>({client:config.client,addr})) : null; }
  return config;
}
function readCommand() { const form=$("#command-form"), data={command:selectedCommand}; for(const input of form.querySelectorAll("[name]")) data[input.name]=input.type==="checkbox" ? input.checked : input.type==="number" ? Number(input.value) : input.value; return data; }
async function previewCommand() { const data=readCommand(); if(data.command==="research" && ["plan","run"].includes(data.research_action) && !data.recipe) {$("#command-preview").textContent="roc research "+data.research_action+" <recipe>";return;} if(data.command==="install"&&!data.accept_downloads) { $("#command-preview").textContent="roc install --yes"+(data.client&&data.client!=="all" ? " --client "+data.client : "")+"  (download consent required)"; return; } const result=await api("preview",data); if($("#command-preview")) $("#command-preview").textContent="roc "+result.args.join(" "); }
function logText(row) {
  if(row.message!==undefined) return row.message;
  if(row.event==="job_started") return `${row.client}:${row.addr} · ${row.unit || "function"} · ${row.size ?? "?"} B · baseline ${row.previous ?? 0}% → started`;
  if(row.event==="job_finished") return `${row.client}:${row.addr} → ${row.score}%${row.score===100 ? " EXACT MATCH" : ""} (previous ${row.previous}%)`;
  if(row.event==="applied") return `Configuration v${row.revision} applied before next lease`;
  if(row.event==="control") return `${row.stopping ? "Stopping after active functions" : row.paused ? "Paused; active functions continue" : "Configuration acknowledged"} · v${row.revision}`;
  if(row.event==="usage") return `${row.requests} cloud requests · ${row.tokens} reserved/settled tokens`;
  if(row.event==="slot_stopped") return "Worker loop retired";
  return row.event;
}
function filteredLogs() {
  const job=$("#log-job").value, level=$("#log-level").value, query=$("#log-search").value.toLowerCase();
  return logs.filter(row=>(!job || row.job===job)&&(!query || logText(row).toLowerCase().includes(query))&&(!level || (level==="error" ? ["error","rejected"].includes(row.event)||/error:|failed|traceback/i.test(logText(row)) : level==="match" ? row.event==="job_finished"&&row.score===100 : level==="control" ? ["control","applied","rejected"].includes(row.event) : row.event===level)));
}
function renderLogs() {
  const selected=$("#log-job").value, current=selected ? jobs.find(job=>job.id===selected&&active(job)) : jobs.find(active);
  const control=$("#console-end-run"),controlHTML=current ? endRun(current) : "";
  if(control.innerHTML!==controlHTML)control.innerHTML=controlHTML;
  const rows=filteredLogs().slice(-120),scroll=$("#log-scroll"),signature=rows.map(r=>r.job+":"+r.seq).join();
  if(scroll.dataset.signature!==signature) {const functions=new Map();updateFeed($("#log-rows"),rows.map(row=>{if(row.event==="job_started")functions.set(row.job+":"+row.slot,row);return [row.job+":"+row.seq,terminalMessage(row,functions,true)];}),false,false);if(follow)scrollToLatest(scroll);scroll.dataset.signature=signature;}
  $("#console-count").textContent=filteredLogs().length+" events";
}
async function poll() {
  let more=false;
  try {
    const state=await api("state?after="+cursor+"&wait=1");
    if(!online) { online=true; $("#connection").classList.remove("offline"); $("#connection").innerHTML='<span class="dot"></span>Local · connected'; }
    const previous = new Map(jobs.map(job=>[job.id,job.status]));
    jobs=state.jobs;
    if(jobs.some(job=>job.status==="completed"&&previous.get(job.id)!=="completed"&&["client-fetch","analyze","install"].includes(job.args?.[0]))) {
      meta=await api("meta");
      if(page==="commands")render();
    }
    if(state.events.length) { if(cursor && state.events[0].seq>cursor+1) $("#console-hint").textContent="Older events omitted from live view. Export run logs for retained output."; logs.push(...state.events); logs=logs.slice(-3000); }
    cursor=state.sequence;more=state.more;
    const selected=$("#log-job").value, signature=jobs.map(job=>job.id).join();
    if($("#log-job").dataset.signature!==signature) { $("#log-job").innerHTML='<option value="">All runs</option>'+jobs.map(job=>`<option value="${job.id}">${esc(job.title)} · ${job.id.slice(0,5)}</option>`).join("");$("#log-job").value=selected;$("#log-job").dataset.signature=signature; }
    $("#worker-count").textContent=jobs.filter(job=>isWorker(job)&&active(job)).length;
    if(page==="overview") render();
    else if(page==="history" && $("#history-runs")) $("#history-runs").innerHTML=runTable([...jobs].reverse());
    else if(page==="cpu"||page==="commands") act(()=>loadCpu());
    else if(page==="workers") { if(editing&&!jobs.some(job=>job.id===editing&&active(job))) { editing=null;render(); }  }
    renderWorkerChat();
    renderLogs();
  } catch(error) { online=false;$("#connection").classList.add("offline");$("#connection").innerHTML='<span class="dot"></span>Disconnected';$("#console-hint").textContent=error.message+". Reconnecting…"; }
  setTimeout(poll,online ? 0 : 2000);
}
document.addEventListener("click", event=>act(async()=>{
  if(event.target.closest(".brand")) { event.preventDefault();navigate("overview");return; }
  const target=event.target.closest("button,[data-log]");if(!target)return;
  if(target.dataset.agentHistoryLog) {await loadAgentHistoryLog(target.dataset.agentHistoryLog);return;}
  if(target.hasAttribute("data-restart-workers")) {
    target.disabled=true;
    try {
      const stopped=jobs.filter(isWorker).slice(-12).filter(j=>!restartedWorkers.has(j.id)&&!["running","paused","stopping","queued"].includes(j.status));
      let count=0;
      for(const job of stopped) {
        await restartWorker(job);
        count++;
      }
      toast(count ? `Restarted ${count} workers with saved parameters` : "No offline workers");
      renderWorkerChat();
    } finally {target.disabled=false;}
    return;
  }
  if(target.hasAttribute("data-cpu-refresh")) {await loadCpu(true);return;}
  if(target.dataset.rocAction) {await api("roc-control",{id:target.dataset.rocId,action:target.dataset.rocAction});toast("Control applies at next target / compiler boundary");await loadCpu(true);return;}
  if(target.dataset.removeRun) {
    const id=target.dataset.removeRun;
    await api("control",{id,action:"remove"});
    jobs=jobs.filter(job=>job.id!==id);logs=logs.filter(row=>row.job!==id);
    if(workerRun===id)workerRun="";
    $("#worker-run").querySelector(`option[value="${id}"]`)?.remove();
    $("#worker-run").value=workerRun;
    chatSignature="";renderWorkerChat();renderLogs();return;
  }
  if(target.dataset.workerTab) {await selectWorker(target.dataset.workerTab==="all" ? "" : target.dataset.workerTab);return;}
  if(target.id==="chat-compact") {chatCompact=!chatCompact;target.textContent=chatCompact ? "Regular" : "Compact";renderWorkerChat();}
  if(target.hasAttribute("data-host-server")) {serverSetupOpen=!serverSetupOpen;render();return;}
  if(target.hasAttribute("data-server-uri")) {await navigator.clipboard.writeText("roconstruct://server");toast("Server setup URI copied");}
  if(target.dataset.page) navigate(target.dataset.page);
  if(target.dataset.function) { functionDetail=await api("functions?id="+target.dataset.function); detailTab="source";renderFunctionDetail(); }
  if(target.dataset.detailTab) { detailTab=target.dataset.detailTab;renderFunctionDetail(); }
  if(target.dataset.workerMode) {workerMode=target.dataset.workerMode;editing=null;controlsOpen=true;render();return;}
  if(target.hasAttribute("data-worker-memory-refresh")) {await loadWorkerMemory(true);return;}
  if(target.hasAttribute("data-new-agent-worker")) {workerMode="agent";editing=null;controlsOpen=true;navigate("workers");return;}
  if(target.hasAttribute("data-new-worker") || target.hasAttribute("data-new-session")) { workerMode="function";editing=null;controlsOpen=true;navigate("workers"); }
  if(target.hasAttribute("data-configure")) {const current=jobs.find(j=>isWorker(j)&&active(j)&&(!workerRun||j.id===workerRun));editing=current?.kind==="worker" ? current.id : null;workerMode=current?.kind==="agent_worker" ? "agent" : "function";controlsOpen=true;render();}
  if(target.hasAttribute("data-close-controls")) {controlsOpen=false;$(".worker-drawer").classList.remove("open");}
  if(target.hasAttribute("data-copy-code")) {await navigator.clipboard.writeText(target.closest(".chat-code").querySelector("code").textContent);toast("Code copied");}
  if(target.id==="chat-follow"||target.id==="jump-live") {setChatFollow(true);chatSignature="";renderWorkerChat();scrollToLatest($("#worker-chat"),true);}
  if(target.dataset.agentSetup) { const setupForm=$("#agent-auto-form")||$("#worker-form");const result=await api("agent-setup",{cli:cliFor(setupForm?.elements.cli?.value||setupForm?.elements.model_provider?.value||target.dataset.agentSetup)});toast(result.manual ? "Run in a terminal: "+result.manual : "Opened a terminal window. Sign in there, then press Refresh."); }
  if(target.hasAttribute("data-agent-run")) { const data=Object.fromEntries(new FormData($("#agent-form")));const result=await api("start",{kind:"command",command:"agent",cli:data.cli,model:data.model,goal:data.goal,minutes:120});toast("Agent started");$("#console-hint").textContent="Agent run "+result.id; }
  if(target.dataset.openCommand) { selectedCommand=target.dataset.openCommand;navigate("commands"); }
  if(target.dataset.command) { selectedCommand=target.dataset.command;render(); }
  if(target.dataset.clientTask) { const result=await api("start",{kind:"command",command:target.dataset.clientTask,client:target.dataset.client});$("#console-hint").textContent="Started "+result.id;toast("Task started"); }
  if(target.dataset.clientWorker) { workerMode="function";controlsOpen=true;editing=null;navigate("workers",{...meta.initial,client:target.dataset.clientWorker}); }
  if(target.dataset.log) { $("#log-job").value=target.dataset.log;renderLogs(); }
  if(target.dataset.step) { const input=$("#worker-form").elements[target.dataset.field];input.value=Math.max(Number(input.min||1),Math.min(Number(input.max||1000000),Number(input.value)+Number(target.dataset.step))); }
  if(target.dataset.preset) { const config=readWorker(),presets={automatic,fast:{rounds:2,max_size:96,max_tokens:1024,use_revng:false},balanced:{rounds:4,max_size:256,max_tokens:2048},deep:{rounds:6,max_size:0,max_tokens:4096}};render({...config,...presets[target.dataset.preset]});document.querySelectorAll("[data-preset]").forEach(button=>button.classList.toggle("active",button.dataset.preset===target.dataset.preset)); }
  if(target.dataset.agentMode) {readAgentAuto();agentAutoConfig.mode=target.dataset.agentMode;render();}
  if(target.dataset.action) {
    const action=target.dataset.action,id=target.dataset.id;
    if(action==="edit") { controlsOpen=true;editing=id;navigate("workers");return; }
    if(action==="kill") { $("#confirm-dialog").dataset.id=id;$("#confirm-dialog").showModal();return; }
    await api("control",{id,action});toast(action==="stop" ? "Stopping after active functions" : "Control sent");
  }
  if(target.dataset.rerun) {
    const job=jobs.find(job=>job.id===target.dataset.rerun);
    if(isWorker(job)&&job.kind!=="worker") {const flag=name=>{const i=job.args.indexOf(name);return i<0 ? undefined : job.args[i+1];};agentAutoConfig={...agentAutoConfig,...job.config,goal:flag("--goal")||"",mode:job.config?.mode||"",cli:job.config?.cli||job.args[1],model:flag("--model")||"",individual:job.args.includes("--individual")};for(const key of ["workers","jobs","minutes","batch_size","batch_minutes","max_size"])if(flag("--"+key.replaceAll("_","-")))agentAutoConfig[key]=Number(flag("--"+key.replaceAll("_","-")));workerMode="agent";controlsOpen=true;editing=null;navigate("workers");return;}
    if(job.kind==="worker") { workerMode="function";controlsOpen=true;editing=null;navigate("workers",job.config); }
    else {
      selectedCommand=job.args[0];navigate("commands");
      const fields=$("#command-form").elements, flag=name=>{const index=job.args.indexOf(name);return index>=0 ? job.args[index+1] : undefined;};
      if(fields.client) fields.client.value=flag("--client")||job.args[1]||"all";
      if(fields.addr) fields.addr.value=selectedCommand==="check" ? job.args[2]||"" : flag("--addr")||"";
      for(const key of ["limit","min_score"]) if(fields[key]&&flag("--"+key.replace("_","-")))fields[key].value=flag("--"+key.replace("_","-"));
      if(fields.permute)fields.permute.checked=job.args.includes("--permute");
      if(fields.research_action)fields.research_action.value=job.args[1];
      if(fields.recipe)fields.recipe.value=job.args[2]||"";
      if(fields.recipes)fields.recipes.value=job.args.slice(1,job.args.indexOf("--client")).join(", ");
      if(selectedCommand==="agent"&&job.args.includes("--automatic")) {agentAutoConfig={cli:job.args[1],model:flag("--model")||"",individual:job.args.includes("--individual")};for(const key of ["workers","jobs","minutes","batch_size","batch_minutes","max_size"])agentAutoConfig[key]=Number(flag("--"+key.replaceAll("_","-")));workerMode="agent";controlsOpen=true;editing=null;navigate("workers");return;}
      if(selectedCommand==="agent"){fields.cli.value=job.args[1];fields.goal.value=flag("--goal")||"";fields.minutes.value=flag("--minutes")||120;}
      await previewCommand();
    }
  }
  if(target.id==="confirm-cancel") $("#confirm-dialog").close();
  if(target.id==="confirm-stop") { await api("control",{id:$("#confirm-dialog").dataset.id,action:"kill"});$("#confirm-dialog").close(); }
  if(target.hasAttribute("data-agent-refresh")) { toast("Refreshing models…");readAgentAuto();meta=await api("meta");await loadOpenCodeModels(true);toast(cliFor(agentAutoConfig.cli)!=="opencode"||meta.agent_models?.length ? "Models refreshed" : "No OpenCode models yet: log in at settings to use CLI or see models"); }
  if(target.id==="refresh-models") { const config=readWorker();toast("Checking installed models…");localModels=(await api("models")).models;meta=await api("meta");await loadOpenCodeModels(true);render(config);toast("Models refreshed"); }
  if(target.id==="save-agent-preset") { const name=prompt("Preset name");if(name) { const config=readAgentAuto();await api("preferences",{agent_preset:name,config});meta=await api("meta");render();toast("Preset saved"); } }
  if(target.id==="save-preset") { const name=prompt("Preset name");if(name) { const config=readWorker();await api("preferences",{preset:name,config});meta=await api("meta");render(config);toast("Preset saved"); } }
  if(target.id==="theme-button") { const theme=document.documentElement.dataset.theme==="light" ? "dark" : "light";document.documentElement.dataset.theme=theme;await api("preferences",{theme});meta.preferences.theme=theme; }
  if(target.id==="exit-dashboard"&&confirm("Exit ROC and stop all active jobs? Cloud requests already sent may still bill.")) { await api("shutdown",{});toast("Dashboard stopped. You can close this tab."); }
}));
document.addEventListener("submit",event=>{
  event.preventDefault();act(async()=>{
    if(event.target.id==="worker-form") { const config=readWorker();if(editing) await api("control",{id:editing,action:"update",config:Object.fromEntries(Object.entries(config).filter(([key])=>liveKeys.has(key)))});else { const result=await api("start",{kind:"worker",config});toast("Match started");$("#console-hint").textContent="Match session "+result.id; } }
    if(event.target.id==="worker-form") {controlsOpen=false;$(".worker-drawer")?.classList.remove("open");}
    if(event.target.id==="agent-auto-form") {const agent=readAgentAuto();const result=await api("start",{kind:"agent_worker",...agent,cli:cliFor(agent.cli)});workerRun=result.id;controlsOpen=false;$(".worker-drawer")?.classList.remove("open");toast("Agent started");$("#console-hint").textContent="Agent "+result.id;}
    if(event.target.id==="agent-form") { const result=await api("agent-session",Object.fromEntries(new FormData(event.target)));toast(result.manual ? "Run in a terminal: "+result.manual : "Opened the agent in a new terminal window"); }
    if(event.target.id==="command-form") { const result=await api("start",{kind:"command",...readCommand()});toast("Command started");$("#console-hint").textContent="Command run "+result.id; }
    if(event.target.id==="preferences-form") { const data=Object.fromEntries(new FormData(event.target));await api("preferences",data);meta=await api("meta");document.documentElement.dataset.theme=data.theme;toast("Preferences saved"); }
    if(event.target.id==="provider-form") { await api("provider",Object.fromEntries(new FormData(event.target)));event.target.elements.key.value="";meta=await api("meta");render();toast("Key saved locally"); }
  });
});
document.addEventListener("change",event=>act(async()=>{
  if(event.target.id==="cpu-cluster") {cpuCluster=event.target.value;await loadCpu(true);}
  if(event.target.id==="worker-loop") {workerLoop=event.target.value;chatSignature="";renderWorkerChat();}
  if(event.target.id==="worker-run") await selectWorker(event.target.value);
  if(event.target.id==="saved-agent-presets"&&event.target.value) {agentAutoConfig={...agentAutoConfig,...meta.preferences.agent_presets[event.target.value],mode:"saved"};render();}
  if(event.target.id==="saved-presets"&&event.target.value) render(meta.preferences.presets[event.target.value]);
  if(event.target.matches("#agent-auto-form [name=cli]")) {readAgentAuto();agentAutoConfig.model="";render();if(cliFor(agentAutoConfig.cli)==="opencode")await loadOpenCodeModels(true);}
  if(event.target.matches("#worker-form [name=model]")&&!editing)render(readWorker());
  if(event.target.matches("#worker-form [name=model_provider]")) {matchProvider=event.target.value;render(readWorker());}
  if(event.target.closest("#command-form")) await previewCommand();
}));
for(const id of ["log-job","log-level","log-search","log-wrap"]) $("#"+id).addEventListener("input",()=>{renderLogs();});
$("#follow-console").addEventListener("click",()=>{follow=!follow;$("#follow-console").textContent=follow ? "↓ Following" : "↓ Follow";$("#follow-console").classList.toggle("selected",follow);renderLogs();});

$("#clear-console").addEventListener("click",()=>{logs=[];renderLogs();});
$("#collapse-console").addEventListener("click",()=>{$(".console").classList.toggle("collapsed");renderLogs();});
$("#export-console").addEventListener("click",()=>act(async()=>{
  const id=$("#log-job").value;let text;
  if(id) { const response=await fetch("/api/log?id="+id,{headers:{"X-ROC-Token":token}});if(!response.ok)throw Error("Could not export log");text=await response.text(); } else text=filteredLogs().map(row=>JSON.stringify(row)).join("\n");
  const url=URL.createObjectURL(new Blob([text],{type:"text/plain"}));const link=document.createElement("a");link.href=url;link.download="roc-"+(id||"console")+".jsonl";link.click();setTimeout(()=>URL.revokeObjectURL(url),1000);
}));
new ResizeObserver(()=>renderLogs()).observe($("#log-scroll"));
act(async()=>{meta=await api("meta");document.documentElement.dataset.theme=meta.preferences.theme;render();if(page==="cpu")await loadCpu(true);poll();});

let functionRows=[], functionDetail=null, detailTab="source", functionLoading=false;
let functionFilters={query:"",status:"",sort:"recent",limit:100};
function functionsPage() {
  return `<div class="section-heading"><h2>Functions</h2>${button("Refresh", 'id="refresh-functions"',true)}</div><div class="function-tools"><input id="function-search" value="${esc(functionFilters.query)}" placeholder="Search function, address, client, user…" aria-label="Search functions"><select id="function-status" aria-label="Filter status"><option value="">All results</option>${["working","matched","improved","unchanged","failed"].map(value=>`<option ${value===functionFilters.status ? "selected" : ""}>${value}</option>`).join("")}</select><select id="function-sort" aria-label="Sort functions">${[["recent","Latest first"],["score","Highest score"],["gain","Largest gain"],["unit","Function name"],["addr","Address"]].map(([value,label])=>`<option value="${value}" ${value===functionFilters.sort ? "selected" : ""}>${label}</option>`).join("")}</select></div><div class="panel" id="function-list"></div><button class="text-button" id="more-functions">More functions</button><div id="function-detail"></div>`;
}
async function loadFunctions() {
  if(functionLoading)return;
  functionLoading=true;
  const filters={...functionFilters};
  try {
    const rows=await api("functions?"+new URLSearchParams(filters));
    if(page!=="history"||JSON.stringify(filters)!==JSON.stringify(functionFilters))return;
    functionRows=rows;renderFunctionList();renderFunctionDetail();
    $("#more-functions").hidden=rows.length<functionFilters.limit||functionFilters.limit>=10000;
  } finally {functionLoading=false;if(page==="history"&&JSON.stringify(filters)!==JSON.stringify(functionFilters))act(loadFunctions);}
}
function renderCommandProgress() {
  const node=$("#command-progress");if(!node)return;
  const expanded=new Set([...node.querySelectorAll("[data-cpu-detail][open]")].map(n=>n.dataset.cpuDetail));
  node.innerHTML=commandProgress();
  node.querySelectorAll("[data-cpu-detail]").forEach(n=>{n.open=expanded.has(n.dataset.cpuDetail);});
}
function renderFunctionList() {
  if(!$("#function-list"))return;
  const query=functionFilters.query.toLowerCase(), status=functionFilters.status, sort=functionFilters.sort;
  const rows=functionRows.filter(r=>(!status||r.status===status)&&`${r.unit} ${r.client} ${r.addr} ${r.model}`.toLowerCase().includes(query)).sort((a,b)=>sort==="score" ? b.score-a.score : sort==="gain" ? (b.base_score==null ? 0 : b.score-b.base_score)-(a.base_score==null ? 0 : a.score-a.base_score) : ["unit","addr"].includes(sort) ? String(a[sort]).localeCompare(String(b[sort])) : b.started-a.started);
  $("#function-list").innerHTML=rows.length ? `<div class="function-table"><table class="run-list"><thead><tr><th>FUNCTION</th><th>RESULT</th><th>SCORE</th><th>MODEL</th><th>TIME</th></tr></thead><tbody>${rows.map(r=>`<tr><td><button class="text-button function-name" data-function="${r.id}">${esc(r.unit || r.addr)}</button><small>${esc(r.client)} · ${esc(r.addr)}</small></td><td>${badge(r.status)}</td><td>${r.base_score==null ? "Stored" : r.base_score+"% →"} <b>${r.score}%</b></td><td>${esc(r.model)}</td><td>${r.ended ? Math.round(r.ended-r.started)+"s" : "Active"}</td></tr>`).join("")}</tbody></table></div>` : empty("No function attempts", "No results for this filter.");
}
function renderFunctionDetail() {
  if(!functionDetail || !$("#function-detail"))return;
  const r=functionDetail;
  let body;
  if(detailTab==="source")body=`<p class="help-note">${r.origin==="server" ? "Current server source. Original source unavailable." : "Leased source → best local candidate"}</p><div class="source-pair"><div><h3>Before · ${r.base_score==null ? "Unknown" : r.base_score+"%"}</h3><pre>${esc(r.before || "// No source supplied")}</pre></div><div><h3>${r.origin==="server" ? "Stored source" : "Best candidate"} · ${r.best_score ?? r.score}%</h3><pre>${esc(r.after || "// No verified source")}</pre></div></div>`;
  else if(detailTab==="timeline")body=`<ol class="function-timeline">${r.timeline.map(e=>`<li><time>${e.seconds}s</time><span>${esc(e.message)}</span></li>`).join("")}</ol>`;
  else if(detailTab==="commands")body=r.commands.length ? r.commands.map(c=>`<div class="command-record"><div>${badge(c.exit_code===0 ? "completed" : "failed")} <span class="muted">${esc(c.cwd)}</span></div><pre>${esc(c.argv.map(v=>/\s/.test(v) ? JSON.stringify(v) : v).join(" "))}</pre>${c.output ? `<details><summary>Compiler output</summary><pre>${esc(c.output)}</pre></details>` : ""}</div>`).join("") : empty("No compiler commands", "Cached results and skipped compilation do not execute commands.");
  else body=(r.rounds||[]).map((round,i)=>`<details class="round-record"><summary>Attempt ${i+1} · ${esc(round.score ?? round.kind ?? "Details")}</summary><pre>${esc(JSON.stringify(round,null,2))}</pre></details>`).join("") || empty("No generation rounds", "Deterministic paths may finish without generation.");
  $("#function-detail").innerHTML=`<section class="panel panel-pad function-detail"><div class="section-heading"><div><h2>${esc(r.unit || r.addr)}</h2><p class="muted">${esc(r.client)} · ${esc(r.addr)} · ${esc(r.model)}</p></div>${badge(r.status)}</div><div class="detail-tabs">${["source","timeline","commands","attempts"].map(t=>`<button class="text-button ${t===detailTab ? "selected" : ""}" data-detail-tab="${t}">${t[0].toUpperCase()+t.slice(1)}</button>`).join("")}</div>${r.failure ? `<p class="failure-note">${esc(r.failure)}</p>` : ""}${body}</section>`;
}
let functionSearchTimer;
document.addEventListener("input", event=>{
  if(event.target.id!=="function-search")return;
  functionFilters.query=event.target.value;functionFilters.limit=100;
  clearTimeout(functionSearchTimer);functionSearchTimer=setTimeout(()=>act(loadFunctions),250);
});
document.addEventListener("change", event=>{
  if(!["function-status","function-sort"].includes(event.target.id))return;
  functionFilters.status=$("#function-status").value;functionFilters.sort=$("#function-sort").value;functionFilters.limit=100;act(loadFunctions);
});
document.addEventListener("click",event=>{
  if(event.target.closest("#refresh-functions"))act(loadFunctions);
  if(event.target.closest("#more-functions")) {functionFilters.limit+=100;act(loadFunctions);}
});
setInterval(()=>{if(page==="history")act(loadFunctions);},5000);

function pauseFollow(event) {
  const node=event.target.closest("#worker-chat,#log-scroll");if(!node)return;
  if(event.type==="wheel" && event.deltaY>=0)return;
  if(event.type==="keydown" && !["ArrowUp","PageUp","Home"].includes(event.key))return;
  if(event.type==="pointerdown" && event.target!==node)return;
  delete node.dataset.liveScrolling;
  if(node.id==="worker-chat")setChatFollow(false);
  else {follow=false;$("#follow-console").textContent="↓ Follow";$("#follow-console").classList.remove("selected");}
}
for(const type of ["wheel","touchstart","keydown","pointerdown"])document.addEventListener(type,pauseFollow,{passive:true});
document.addEventListener("scroll",event=>{
  const node=event.target;if(node.id!=="worker-chat"&&node.id!=="log-scroll")return;
  const previous=Number(node.dataset.scrollTop ?? node.scrollTop),bottom=node.scrollHeight-node.clientHeight-node.scrollTop;
  if(node.id==="worker-chat") {
    if(!node.dataset.liveScrolling && node.scrollTop<previous-2 && bottom>40)setChatFollow(false);
    else if(bottom<12)setChatFollow(true);
  }
  node.dataset.scrollTop=node.scrollTop;
},true);
const feedResize=new ResizeObserver(()=>{const node=$("#worker-chat");if(node&&chatFollow)scrollToLatest(node,true);});
const observeFeed=new MutationObserver(()=>{const rows=$("#worker-chat-rows");if(rows&&rows!==observeFeed.rows){feedResize.disconnect();feedResize.observe(rows);feedResize.observe(rows.parentElement);observeFeed.rows=rows;}});
observeFeed.observe($("#main"),{childList:true});

async function selectWorker(id) {
  workerRun=id;chatSignature="";$("#worker-run").value=id;renderWorkerChat();
  if(!id)return;
  try {await loadSessionLog(id);}
  catch(error) {console.warn("Session history unavailable", error);}
  if(page==="workers" && workerRun===id) {chatSignature="";renderWorkerChat();}
}
async function loadSessionLog(id) {
  let response, lastError;
  for(let attempt=0;attempt<3;attempt++) {
    try {response=await fetch("/api/log?id="+encodeURIComponent(id),{headers:{"X-ROC-Token":token},signal:AbortSignal.timeout(10000)});break;}
    catch(error) {lastError=error;if(attempt<2 && typeof setTimeout==="function") await new Promise(resolve=>setTimeout(resolve,Math.min(1000*(attempt+1),2000)));}
  }
  if(!response) throw new Error(lastError?.name==="TimeoutError" ? "Session history request timed out" : "Session history temporarily unavailable");
  if(!response.ok)throw new Error(response.status===403 ? "Dashboard session expired" : "Session history unavailable");
  const rows=(await response.text()).split("\n").filter(Boolean).map(line=>JSON.parse(line));
  const keys=new Set(logs.map(r=>r.job+":"+r.seq));
  logs.push(...rows.filter(r=>!keys.has(r.job+":"+r.seq)));
  logs.sort((a,b)=>a.time-b.time);logs=logs.slice(-3000);
}

