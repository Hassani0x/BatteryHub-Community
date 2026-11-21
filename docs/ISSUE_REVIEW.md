# Upstream issue review

Snapshot reviewed for this fork on November 20, 2026 (America/Los_Angeles).
Base commit: `fd2267d770c9dafc46047f715e79da525e3fecf4`.

The GitHub API inventory contains **3,474 open issues**, excluding pull requests.
**3,259** titles begin with `Device request:`; the remaining **215** include additional
device requests, software bugs, feature requests and reports already addressed in upstream code.
Inventorying an issue is not equivalent to reproducing or resolving it.

## Changes in this fork

| Upstream issue | Change | Validation and limits |
| --- | --- | --- |
| [#2993](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/2993) | Clamp the primary widget position after conversion to taskbar-local coordinates; bound offsets before signed conversion and DPI scaling. | Geometry regression tests cover negative positions, right overflow, negative monitor origins and invalid offsets. Windhawk integration still needs live testing. |
| [#3982](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/3982) | Enumerate vertical secondary taskbars; derive rendering orientation from each bar; place vertical mirrors above their clock using the correct coordinate axis. Repaint when either bar dimension changes. | Actual GDI layout test covers horizontal-primary/vertical-secondary, the reverse combination, and empty vertical placeholders. Physical multi-monitor UI Automation placement remains unverified. |
| [#63](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/63), [#614](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/614) | Expose the existing registry spacing setting in a persistent menu with DPI-independent presets. | Application build verifies integration. Manual Networx/TrafficMonitor interaction remains unverified; spacing is user controlled. |
| [#1681](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/1681) | Same spacing control provides a manual placement option. | Partial only. It does not automatically reserve space among Windows 11 app buttons. |

## Existing upstream work

The cloned source already has a background UI Automation worker for the Explorer hang in
[#234](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/234), monitor selection
(#851), device ordering (#3099), portable packaging (#2881), Hungarian translation (#3797),
and a signed Windows updater (#29/#3755). These are inherited features, not fixes authored here.
The fork deliberately keeps the `dev` channel so its binaries do not install official upstream updates.

## Unresolved work

The [CSV inventory](UPSTREAM_ISSUES.csv) records every open issue number, title, source URL and review status.
It is a snapshot, not a claim of exhaustive individual investigation. Unreviewed items remain explicitly unresolved.
No upstream issues were closed, and no comments or messages were posted to upstream reporters.

- Unknown-device requests require documented protocols or read-only captures from vendor software plus hardware tests.
  A VID/PID or report size alone is insufficient to infer a safe battery query.
- Startup invisibility (#4004/#3407), duplicate tray entries (#3974), device-specific inaccurate readings,
  other display reports and the remaining feature requests have not been resolved by this patch.
- Vertical RTL secondary taskbars retain the existing conservative hide behavior.
- The primary widget can still overlap app buttons when no free taskbar space exists. Tray-icon mode remains available.
- Code signatures, SmartScreen reputation and third-party antivirus classifications are not provided by this fork.

## Release checks

The release workflow compiles the Windows application, runs the complete `make test` suite (including
the new geometry and real-layout regression tests), verifies version resources, and packages the
Inno Setup installer and portable ZIP with checksums and HeadsetControl notices/corresponding source.
See the repository's Actions run for the result attached to the release commit.

Manual release gates still outstanding: physical mixed-orientation multi-monitor placement, Windows
10/11 variants and scaling combinations, custom taskbar utilities, installer/UAC paths in a disposable
account, and every claimed device's real battery/charging transitions. Automated tests do not establish those results.
