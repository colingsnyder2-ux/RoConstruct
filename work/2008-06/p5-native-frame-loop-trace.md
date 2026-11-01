# P5 original frame-loop trace

The source server reports these recovered 2008-06 functions as exact matches.
They are evidence about the executable, not yet linked into this player.

- 00556520 starts the RunService thread and binds 00555190, the run procedure.
- 00555190 tracks a deadline and accumulated remaining time, calls 00554880,
  waits for views through 00554ed0, updates scheduler items through 005550a0,
  and uses the interruptible timed wait 00554e10. Stopwatch bookkeeping follows.
- 00554880 locks the DataModel and calls 00578e50 with the fixed frame period.
- 00578e50 gates the DataModel step and then updates camera and backpack.
- 00578ca0 chooses simulation versus idle based on run mode and run state. In
  simulation it runs Workspace::step and then Stepped; it raises Heartbeat
  afterward even on the idle branch. Rendering settings and profiling also
  participate in the original implementation.

Current glue_runtime.cpp runProc is a reconstruction: it steps, emits both
notifications, invalidates views and sleeps on a simpler loop. The player test
harness StepEngine separately accumulates two 60 Hz physics steps per 30 Hz
event pair. Passing cadence or character comparisons does not prove either
loop has original scheduling, view synchronization, run-mode behavior, or
camera/backpack heartbeat behavior. The original uses different class layouts;
source must be adapted with explicit behavior and lifetime tests before use.

Next identify Workspace::step timing and DataModel run-mode inputs, then test
idle/play transitions and view synchronization against the original before
replacing the harness. P5 remains open.

Original Workspace::step at 005a2580 passes elapsed interval and settings to
World::step 005e9fd0. The latter derives the number of fixed world substeps,
processes clumps and UI once per call, prepares primitives, then updates active
primitives, broadphase and joint stages for each substep. The donor World::step
instead performs UI on world-step boundaries and lacks several 2008 stages;
matching the outer tick does not resolve these world implementation differences.
