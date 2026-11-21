# BatteryHub Community

Battery levels for wireless mice, keyboards, headsets and controllers on the Windows taskbar.
A community-maintained fork by [Hassani0x](https://github.com/Hassani0x), based on
[BatteryHub by krisgfx9 and contributors](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor).
This is an independent fork, not an official upstream release.

## Download and install

[Download the latest Windows installer](https://github.com/Hassani0x/BatteryHub-Community/releases/latest)

1. Download **BatteryHub-Setup-1.1.1.exe** from the release assets.
2. Double-click the file and follow the setup wizard. The default per-user install needs no administrator rights.
3. Start **BatteryHub** from the Start menu. Click its taskbar display to choose devices and display settings.

No Git, GitHub account, command line, or separate runtime is needed to use the installer.
Windows 10/11 on x64 is supported. This is a Windows application, not an Android APK.
The portable ZIP is available if you prefer to run without installing.
The application and installer are unsigned; Windows may show an unknown-publisher warning.
Uninstall through **Settings > Apps > Installed apps > BatteryHub**.

This fork uses the same application identity and settings as upstream BatteryHub. Installing it upgrades/replaces that copy;
it is not intended to run side by side. Fork builds use the `dev` update channel, so updates must be downloaded from this repository.

## Changes in 1.1.1

- Keep the primary widget within taskbar bounds when a customized tray reports an off-screen anchor.
- Support vertical secondary taskbars and calculate each monitor's layout independently.
- Add **Space from notification area** to the menu (0–256 DPI-independent pixels) to help avoid other taskbar utilities.
- Bound registry offsets before scaling so invalid settings cannot wrap coordinates.
- Include an open-issue inventory with explicit implemented, partial and unresolved statuses.

The repository does **not** claim to resolve every upstream issue. Most are device-support requests requiring protocol captures
and hardware validation. See [issue review and validation](docs/ISSUE_REVIEW.md) and the
[complete open-issue inventory](docs/UPSTREAM_ISSUES.csv).

## Device support and troubleshooting

See the [upstream feature and device reference](UPSTREAM_README.md) for device IDs, protocols, limitations and diagnostic commands.
Device support inherited from upstream is not newly hardware-validated by this fork.
If another taskbar utility overlaps the widget, increase **Space from notification area**, or select **Show as tray icons**.
The spacing option moves the widget left on horizontal taskbars and up on vertical taskbars.

## Build from source

Use MinGW-w64 (C++17) and GNU Make in an MSYS2 MINGW64 shell:

```sh
make VERSION=1.1.1 CHANNEL=dev
make test VERSION=1.1.1 CHANNEL=dev
```

Alternatively use `build.bat 1.1.1 dev` with MinGW-w64 on PATH.
With Inno Setup installed, run `powershell -File installer/build-installer.ps1 -Version 1.1.1`.
GitHub Actions builds, tests and packages Windows releases when a version tag is pushed.

## Contributing and license

Read [CONTRIBUTING.md](CONTRIBUTING.md). Include reproduction steps and test evidence; do not claim a device is verified without testing it.
Retain upstream attribution and protocol-source notices. Licensed under [GPL-3.0](LICENSE);
third-party notices are included in the installer and portable package. Original authorship and Git history are preserved.
