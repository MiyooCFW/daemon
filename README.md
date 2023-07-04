# miyoo_daemon

## Battery Low Warning
Will flash screen or vibrate when battery reports lower than 3550 by default.  
battery low config  
`/mnt/.batterylow.conf`  
default: 3550  

## Default Button Mappings

Remember: all hotkeys will work only in combination with RESET/HOME button (see kernel's miyoo_kbd.c code)

| BUTTON | ACTION |
|  --- | --- |
| Right | Brightness Up |
| Left | Brightness Down |
| Down | Volume Down |
| Up | Volume Up |
| Start | Screenshot |
| Select | Force-close app |

## Config
- custom hotkeys config location  
`/mnt/.buttons.conf`  
- hotkeys config format  
`x:a:y:b:up:down:left:right:select:start:l2:r2:hold-x:hold-a:hold-y:hold-b:hold-up:hold-down:hold-left:hold-right:hold-select:hold-start:hold-l2:hold-r2`  
- default hotkeys config values and format (the string must match exactly)
`0:0:0:0:3:4:2:1:22:13:0:0:0:0:0:0:0:0:0:0:0:0:0:0`  
**NOTE**: 
- when enabling custom hotkeys an existing ones will be disabled&overwritten by above defaults or any passed by user. However that doesn't apply to hardcoded ones like emulating L1/R1 or other additional buttons.
- you can disable/enable custom hotkey bindings in `/mnt/options.cfg` with  HOTKEY_CUSTOM=0 or 1 entry
- when there's no custom hotkeys config file and HOTKEY_CUSTOM=1 then above default hotkeys apply across device

## Actions
1 = backlight up  
2 = backlight down  
3 = volume up  
4 = volume down  
5 = mute  
6 = volume rotate up  
7 = volume rotate down  
8 = backlight rotate up  
9 = backlight rotate down  
10 = backlight min max  
11 = remount /mnt as rw  
12 = remount /mnt as ro  
13 = screenshot using fbgrab  
20 = kill, sync and shutdown  
21 = kill gui. Does not work on most apps. do not use  
22 = kill force app. Work on most apps.
23 = kill soft app. Work on a few apps, guaranties proper closing.
