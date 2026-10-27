# GMMK3 100% ISO VIA and OpenRGB

Build this keymap with:

    qmk compile -kb gmmk/gmmk3/p100/iso -km viahybrid

In VIA, enable the Design tab and load `design_layout.json` from this directory
if the keyboard is not automatically recognized. On Linux, standard VIA
messages and OpenRGB can use the keyboard together without pressing Fn+O.
VIA settings are stored in the keyboard.

On Linux, a browser error such as `NotAllowedError: Failed to open the device`
can mean the Raw HID interface needs user access. For this keyboard, add the
following rule to `/etc/udev/rules.d/70-gmmk3-via.rules`:

```udev
SUBSYSTEM=="hidraw", ATTRS{idVendor}=="504b", ATTRS{idProduct}=="320f", ENV{ID_USB_INTERFACE_NUM}=="01", TAG+="uaccess"
```

Run `sudo udevadm control --reload-rules`, reconnect the keyboard, then authorize
it again in VIA. This rule grants the active local user access to the
configuration interface.

The hybrid transport accepts 32-byte VIA messages and 64-byte OpenRGB messages,
and replies at the corresponding size. Fn+O retains the original mode switch
for 64-byte messages, for hosts that pad VIA messages to that size. The default
mode routes 64-byte messages to OpenRGB.

The board masks unused matrix positions so they cannot trigger USB wakeup.
Physical keys still wake the computer when keyboard wake is enabled by the host.

Back up VIA settings before flashing: this firmware's VIA implementation resets
its stored keymap and macros when the firmware build date changes.
