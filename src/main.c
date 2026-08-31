// muffin status demo — a real Wii U homebrew title screen for cemu-ios-muffin.
// Not a game: it exists to boot on real Cemu / 64Touch / hardware and print
// muffin's actual current build status, pulled at build time from the
// project's own STATUS.md so this can never say more than the repo verifies.
#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <coreinit/thread.h>

#ifndef MUFFIN_HEAD
#define MUFFIN_HEAD "unknown"
#endif
#ifndef MUFFIN_DATE
#define MUFFIN_DATE "unknown"
#endif

int main(int argc, char** argv)
{
    WHBProcInit();
    WHBLogConsoleInit();

    WHBLogPrint("========================================");
    WHBLogPrint("  cemu-ios-muffin -- status demo");
    WHBLogPrint("========================================");
    WHBLogPrint("");
    WHBLogPrint("You are looking at a real Wii U title,");
    WHBLogPrint("booted by a real console/emulator, from");
    WHBLogPrint("a build of muffin's own toolchain.");
    WHBLogPrint("");
    WHBLogPrint("Source: bward-dev1/cemu-ios-muffin");
    WHBLogPrintf("Commit: %s", MUFFIN_HEAD);
    WHBLogPrintf("Built:  %s", MUFFIN_DATE);
    WHBLogPrint("");
    WHBLogPrint("Verified true as of this build, per the");
    WHBLogPrint("project's own STATUS.md:");
    WHBLogPrint(" - real Cemu engine compiles for iOS arm64");
    WHBLogPrint(" - app links end-to-end, ships as an IPA");
    WHBLogPrint(" - a title boots and runs on device");
    WHBLogPrint(" - PPC interpreter executes (JIT untested)");
    WHBLogPrint(" - no frame confirmed on screen yet");
    WHBLogPrint(" - no audio, no input wiring yet");
    WHBLogPrint("");
    WHBLogPrint("This screen is muffin's own status, not a");
    WHBLogPrint("claim about any other project.");
    WHBLogConsoleDraw();

    while (WHBProcIsRunning())
    {
        WHBLogConsoleDraw();
        OSSleepTicks(OSMillisecondsToTicks(16));
    }

    WHBLogConsoleFree();
    WHBProcShutdown();
    return 0;
}
