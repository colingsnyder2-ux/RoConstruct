import { Plugin } from "@opencode/plugin"
import { spawn } from "node:child_process"
import { existsSync } from "node:fs"
import { join } from "node:path"

/**
 * RoConstruct plugin: exposes the matching-decompilation workflow as native
 * OpenCode tools and a /crack command, so any session can score, batch-test,
 * submit and research functions without shelling out by hand.
 *
 * Tools (namespace "roc"): check, check_batch, submit, rtti, immediates,
 * versions, similar, failures.
 * Command: /crack — starts a goal-directed cracking prompt with the
 * project's proven patterns (hoist, RTTI type-swap, dllimport-inline).
 */

const MAX_OUTPUT = 60_000

function roc(ctx: { location: { directory: string } }, args: string[], signal?: AbortSignal): Promise<string> {
  const root = ctx.location.directory
  const rocPath = join(root, "roc.py")
  const python = existsSync(rocPath)
    ? process.execPath.includes("bun") || process.platform === "win32"
      ? "python"
      : "python3"
    : "python"
  if (!existsSync(rocPath)) {
    return Promise.reject(new Error(`roc.py not found at ${rocPath}; run this plugin inside the RoConstruct checkout.`))
  }
  return new Promise((resolve, reject) => {
    const child = spawn(python, [rocPath, ...args], {
      cwd: root,
      env: { ...process.env, PYTHONIOENCODING: "utf-8", ROC_AGENT: "1" },
      stdio: ["ignore", "pipe", "pipe"],
      windowsHide: true,
      ...(process.platform === "win32" ? { creationFlags: 0x08000000 } : {}),
    })
    let out = ""
    let err = ""
    child.stdout.on("data", (chunk) => {
      if (out.length < MAX_OUTPUT) out += chunk.toString("utf-8")
    })
    child.stderr.on("data", (chunk) => {
      if (err.length < MAX_OUTPUT) err += chunk.toString("utf-8")
    })
    child.on("error", reject)
    child.on("close", (code) => {
      const text = (out || err).trim()
      if (code === 0 || text) {
        resolve(text || `(exit ${code}, no output)`)
      } else {
        reject(new Error(`roc ${args.join(" ")} exited with code ${code}`))
      }
    })
    signal?.addEventListener("abort", () => child.kill())
  })
}

const addr = (value: string) => value.toLowerCase().replace(/^0x/, "").padStart(8, "0")

export default Plugin.define({
  id: "roconstruct",
  async setup(ctx) {
    await ctx.tool.transform((editor) => {
      editor.namespace({
        name: "roc",
        description:
          "RoConstruct matching-decompilation workflow: score candidate C++ against the client binary byte for byte, " +
          "test variants in parallel, submit server-verified gains, and research function types from RTTI evidence.",
      })

      editor.add({
        name: "check",
        description:
          "Score one function's C++ against the client binary. Prints the score and an assembly diff " +
          "('-' = target, '+' = yours). Without a file, scores src/<client>/<addr>.cpp.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", description: "Client name, e.g. 2008-06", default: "2008-06" },
            address: { type: "string", description: "Function address, e.g. 004acd50" },
            file: { type: "string", description: "Optional scratch source file to score instead of the stored source" },
            context: { type: "integer", description: "Unchanged diff lines around each hunk (3 = residue only)", default: 99 },
          },
          required: ["address"],
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address, file, context: diffContext = 99 } = input as Record<string, never>
          const args = ["check", String(client), String(address), "--context", String(diffContext)]
          if (file) args.push("--file", String(file))
          const result = await roc(ctx, args, context.signal)
          return { content: result }
        },
      })

      editor.add({
        name: "check_batch",
        description:
          "Score several candidate variants of one function IN PARALLEL and rank them best-first. " +
          "Generate 3-5 hypotheses up front as files, then call this once instead of serial edit->check loops. " +
          "Prints the winner's residue to continue from.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            address: { type: "string" },
            files: {
              type: "array",
              items: { type: "string" },
              description: "Candidate source files (2 or more recommended)",
              minItems: 1,
            },
          },
          required: ["address", "files"],
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address, files } = input as Record<string, never>
          const result = await roc(
            ctx,
            ["check-batch", String(client), String(address), ...(files as string[]).map(String)],
            context.signal,
          )
          return { content: result }
        },
      })

      editor.add({
        name: "submit",
        description:
          "Submit a scoring improvement to the group server for re-verification. Only server-verified receipts count as gains.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            address: { type: "string" },
            file: { type: "string", description: "Optional scratch file to submit instead of the stored source" },
          },
          required: ["address"],
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address, file } = input as Record<string, never>
          const args = ["submit", String(client), String(address)]
          if (file) args.push("--file", String(file))
          const result = await roc(ctx, args, context.signal)
          return { content: result }
        },
      })

      editor.add({
        name: "rtti",
        description:
          "RTTI reverse-index: print the binary-proven RTTI type descriptors a function references " +
          "(never guess a template type parameter — read it here). With open=true, annotate every open " +
          "function with its proven types instead.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            address: { type: "string", description: "Omit with open=true to list all open functions" },
            open: { type: "boolean", description: "List every open function's RTTI type refs, best scores first" },
          },
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address, open } = input as Record<string, never>
          const args = ["rtti", String(client)]
          if (open) args.push("--open")
          if (address) args.push(String(address))
          const result = await roc(ctx, args, context.signal)
          return { content: result }
        },
      })

      editor.add({
        name: "immediates",
        description:
          "List near-miss functions whose ONLY residue is one wrong constant, with the target value read from " +
          "the binary. Each is a potential one-line fix.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            min_score: { type: "integer", default: 95 },
            max_score: { type: "integer", default: 99 },
          },
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", min_score = 95, max_score = 99 } = input as Record<string, never>
          const result = await roc(
            ctx,
            ["immediates", String(client), "--min-score", String(min_score), "--max-score", String(max_score)],
            context.signal,
          )
          return { content: result }
        },
      })

      editor.add({
        name: "versions",
        description:
          "Compile one function's vendor source under every installed vendor-version recipe and rank the scores. " +
          "Use when a big library function plateaus: the wrong source version is a permanent ceiling.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            address: { type: "string" },
          },
          required: ["address"],
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address } = input as Record<string, never>
          const result = await roc(ctx, ["versions", String(client), String(address)], context.signal)
          return { content: result }
        },
      })

      editor.add({
        name: "similar",
        description:
          "List exact-matched functions with a similar instruction shape to a given address — the siblings a " +
          "winning fix should propagate to.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            address: { type: "string" },
            limit: { type: "integer", default: 10 },
          },
          required: ["address"],
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address, limit = 10 } = input as Record<string, never>
          const result = await roc(
            ctx,
            ["similar", String(client), String(address), "--limit", String(limit)],
            context.signal,
          )
          return { content: result }
        },
      })

      editor.add({
        name: "failures",
        description:
          "Show already-rejected variants recorded for one function. ALWAYS call this before editing a " +
          "near-miss: never replay a recorded rejection.",
        input: {
          type: "object",
          properties: {
            client: { type: "string", default: "2008-06" },
            address: { type: "string" },
          },
          required: ["address"],
          additionalProperties: false,
        },
        options: { namespace: "roc" },
        execute: async (input, context) => {
          const { client = "2008-06", address } = input as Record<string, never>
          const result = await roc(
            ctx,
            ["failures", "--addr", addr(String(address)), "--client", String(client)],
            context.signal,
          )
          return { content: result }
        },
      })
    })

    await ctx.command.transform((editor) => {
      editor.add({
        name: "crack",
        description: "Start goal-directed function cracking with the project's proven patterns",
        execute: async ({ sessionID, prompt, delivery }) => {
          const goal = `Continue cracking RoConstruct functions until told to stop.

Workflow per function (read docs/AGENT_GUIDE.md and CLAUDE.md first):
1. roc_failures on the address first — never replay a recorded rejection.
2. roc_check once, read the residue diff.
3. Classify with the DIFF TABLE below; pick the cheapest falsifiable change; write 3+ variants as files.
4. roc_check_batch to test them all in parallel; continue from the winner's residue.
5. On a gain: roc_submit, then roc_similar and propagate to siblings.
6. STOP after 3 failed hypotheses on one function; record the evidence and move to the next target.

DIFF TABLE (residue -> first thing to try):
- mov eax,X vs mov ecx/edx,X (same operands, different register) -> HOIST the chained member load
  into a named local first (const T* t = obj->field;) — this forced MSVC eax chaining and produced
  9 exacts. Note: the class is now exhausted by systematic scan; still try it, it is one cheap edit.
- RTTI push sym vs push 0 in a template family -> wrong template type parameter; read the binary-proven
  type with roc_rtti and swap it in.
- Target inlines float math but ours IAT-calls a dllimport class method (Ogre Vector3 etc.) ->
  replace with a free static inline helper in the unit; MSVC never inlines dllimport members.
- IAT call pre-loads the pointer into a register -> declare the callee as an extern function-pointer
  variable, never (*(T*)addr) casts.
- Wrong immediate / allocation size / stack offset -> read the target value (roc_immediates lists these).
- push sym vs push 0 alone -> masked relocation, never a blocker; the residue is elsewhere.
- Big library function plateau -> roc_versions to test every installed vendor version.

Start with roc_immediates and roc_rtti(open=true) to pick targets, then work the highest-score near-misses
first. Record every trial (including failures) in work/agent-memory/attempts.jsonl.

${prompt.text}`
          await ctx.session.prompt({ ...prompt, sessionID, text: goal, delivery })
        },
      })
    })
  },
})
