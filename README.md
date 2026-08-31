# muffin status demo

A tiny Wii U homebrew title — not a game — built to boot on real Cemu,
64Touch, or hardware and print [cemu-ios-muffin](https://github.com/bward-dev1/cemu-ios-muffin)'s
actual current build status on screen.

The text is pulled from muffin's own `STATUS.md` at build time, so this can
never claim more than that repo currently verifies. It exists as a real,
loadable `.rpx` payload for testing muffin's boot path and for comparing
render output against 64Touch on the same simple workload.

## Build

Needs [devkitPro](https://devkitpro.org) with the `wut` package, or just use
the CI workflow, which builds it in the `devkitpro/devkitppc` container.

```
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=$DEVKITPRO/cmake/WiiU.cmake
cmake --build build
```

Output: `build/muffin_status_demo.rpx`.

## Run

Drop `muffin_status_demo.rpx` into muffin's `Documents/Roms/` (that's the
folder its `GameManager` scans), or load it directly in desktop Cemu / 64Touch
/ Aroma homebrew like any other `.rpx`.
