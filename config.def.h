#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* Appearance */
    static const int sloppyfocus               = 1;  /* focus follows mouse */
    static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
    static const int smartgaps                 = 1;  /* 1 means no outer gap when there is only one window */
    static int gaps                            = 1;  /* 1 means gaps between windows are added */
    static const unsigned int gappx            = 8; /* gap pixel between windows */
    static const unsigned int borderpx         = 2;  /* border pixel of windows */
    static const int user_bh		           = 24; /* 0 means that dwl will calculate barheight, >= 1 means dwl will use user_bh as the bar height. */
    static const int showbar                   = 1; /* 0 means no bar */
    static const int topbar                    = 1; /* 0 means bottom bar */
    static const char *fonts[]                 = {"JetbrainsMono Nerd Font:size=11:antialias=true:hinting=true",
                                                    "JoyPixels Regular:size=10:antialias=true:autohint=true"};
    static const float rootcolor[]             = COLOR(0x000000ff);

    /* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
    static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f}; /* You can also use glsl colors */
    static uint32_t colors[][3]                = {
    	/*               fg          bg          border    */
    	[SchemeNorm] = { 0x93a1a1ff, 0x000000ff, 0x444444ff },
    	[SchemeSel]  = { 0xeeeeeeff, 0x000000ff, 0x93a1a1ff },
    	[SchemeUrg]  = { 0,          0,          0x770000ff },
    };

    /* Tagging - TAGCOUNT must be no greater than 31 */
    static char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* Logging */
    static int log_level = WLR_ERROR;

/* Rules */
    static const Rule rules[] = {
    	/* app_id             title           tags mask     isfloating   monitor */
        { NULL,              "Open File",     0,            1,           -1 },
        { NULL,              "Open Folder",   0,            1,           -1 },
        { "qalculate-gtk",              NULL,   0,            1,           -1 },
        { "mpv",               NULL,           0,            1,           -1 },
        { "imv",               NULL,           0,            1,           -1 },
    };

/* layout(s) */
    static const Layout layouts[] = {
    	{ "[]=",      tile },
    	{ "><>",      NULL },    /* no layout function means floating behavior */
    	{ "[M]",      monocle },
    };

/* monitors */
    static const MonitorRule monrules[] = {
    	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
    	{ NULL,       0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
    };

/* keyboard */
    static const struct xkb_rule_names xkb_rules = {
        .options = NULL,
        .layout = "es",
    };

    static const int repeat_rate = 25;
    static const int repeat_delay = 600;

/* Trackpad */
    static const int tap_to_click = 1;
    static const int tap_and_drag = 1;
    static const int drag_lock = 1;
    static const int natural_scrolling = 1;
    static const int disable_while_typing = 1;
    static const int left_handed = 0;
    static const int middle_button_emulation = 0;
    static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
    static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;
    static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;
    static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
    static const double accel_speed = 0.0;
    static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* Keybindings */
    #define MODKEY WLR_MODIFIER_LOGO

    void movetagandview(const Arg *arg) { tag(arg); view(arg); }

    #define TAGKEYS(KEY,SKEY,TAG) \
    	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
    	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
    	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           movetagandview,  {.ui = 1 << TAG} }, \
    	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

    #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

    /* commands */
    static const char *termcmd[]  = { "foot", NULL };
    static const char *browsercmd[]  = { "google-chrome-stable", " --enable-features=AcceleratedVideoEncoder,AcceleratedVideoDecodeLinuxGL,AcceleratedVideoDecodeLinuxZeroCopyGL,VaapiIgnoreDriverChecks,TouchpadOverscrollHistoryNavigation,FluentOverlayScrollbar", "--ozone-platform-hint=auto", "--password-store=basic", NULL };
    static const char *pavucontrolcmd[] = { "foot","-e", "pulsemixer", NULL };
    static const char *filescmd[]  = { "pcmanfm", NULL };
    static const char *screenshotcmd[]  = { "/home/daniel/scripts/screenshot_river.sh", NULL };
    static const char *bluetoothcmd[]  = { "foot", "-e", "bluetuith", NULL };
    static const char *calculatorcmd[]  = { "qalculate-gtk", NULL };


    /* Keys */
    static const Key keys[] = {
        /* Apps and Scripts */
        { MODKEY, XKB_KEY_Return, spawn, {.v = termcmd } },
        { MODKEY, XKB_KEY_b, spawn, {.v = browsercmd } },
        { MODKEY, XKB_KEY_a, spawn, {.v = bluetoothcmd} },
        { MODKEY, XKB_KEY_h, spawn, SHCMD("foot -c ~/.config/foot/foot_no_pad.ini -e btop") },
        { MODKEY, XKB_KEY_y, spawn, SHCMD("foot -e yazi") },
        { MODKEY, XKB_KEY_n, spawn, SHCMD("foot -c ~/.config/foot/foot_no_pad.ini -e nvim") },
        { MODKEY, XKB_KEY_p, spawn, {.v = pavucontrolcmd } },
        { MODKEY, XKB_KEY_w, spawn, SHCMD("killall bemenu || networkmanager_dmenu") },
        { MODKEY, XKB_KEY_e, spawn, {.v = filescmd } },
        { MODKEY, XKB_KEY_d, spawn, SHCMD("killall bemenu || j4-dmenu-desktop --no-generic --skip-i3-exec-check -b --dmenu bemenu -t foot") },
        { MODKEY, XKB_KEY_l, spawn, SHCMD("killall bemenu || ~/scripts/dmenu_logout_dwl.sh") },
        { MODKEY, XKB_KEY_u, spawn, SHCMD("killall bemenu || ~/scripts/prompt.sh && kill -64 $(pidof someblocks)") },
        { MODKEY, XKB_KEY_v, spawn, SHCMD("killall bemenu || ~/scripts/cliphist-rofi") },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_F, togglefullscreen, {0} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_S, spawn, {.v = screenshotcmd } },
        { 0, XKB_KEY_XF86Calculator, spawn, {.v = calculatorcmd } },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_W, spawn, SHCMD("~/scripts/background.sh") },
        { MODKEY, XKB_KEY_q, killclient, {0} },

        /* Volume, Brightness and Media Controls */
        { 0, XKB_KEY_XF86AudioMute, spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle && kill -44 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioMicMute, spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle && kill -49 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioLowerVolume, spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%- && kill -44 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioRaiseVolume, spawn, SHCMD("wpctl set-volume -l 1.5 @DEFAULT_AUDIO_SINK@ 5%+ && kill -44 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86MonBrightnessUp, spawn, SHCMD("brightnessctl set +5% && kill -54 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86MonBrightnessDown, spawn, SHCMD("brightnessctl set 5%- && kill -54 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioPlay, spawn, SHCMD("playerctl play-pause") },
        { 0, XKB_KEY_XF86AudioNext, spawn, SHCMD("playerctl next") },
        { 0, XKB_KEY_XF86AudioPrev, spawn, SHCMD("playerctl previous") },

        /* Window Manager Stuff */
        { MODKEY, XKB_KEY_Left, focusdir, {.ui = 0} },
        { MODKEY, XKB_KEY_Right, focusdir, {.ui = 1} },
        { MODKEY, XKB_KEY_Up, focusstack, {.i = -1} },
        { MODKEY, XKB_KEY_Down, focusstack, {.i = +1} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Left, swapdir, {.ui = 0} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Right, swapdir, {.ui = 1} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Up, swapdir, {.ui = 2} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Down, swapdir, {.ui = 3} },
        { MODKEY, XKB_KEY_plus, incnmaster, {.i = +1} },
        { MODKEY, XKB_KEY_minus, incnmaster, {.i = -1} },
        { MODKEY|WLR_MODIFIER_CTRL, XKB_KEY_Right, setmfact, {.f = +0.05f} },
        { MODKEY|WLR_MODIFIER_CTRL, XKB_KEY_Left, setmfact, {.f = -0.05f} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Return, zoom, {0} },
        { MODKEY, XKB_KEY_Tab, view, {0} },
        { MODKEY, XKB_KEY_q, killclient, {0} },
        { MODKEY, XKB_KEY_t, setlayout, {.v = &layouts[0]} },
        { MODKEY, XKB_KEY_f, setlayout, {.v = &layouts[1]} },
        { MODKEY, XKB_KEY_m, setlayout, {.v = &layouts[2]} },
        { MODKEY, XKB_KEY_space, togglefloating, {0} },
        { MODKEY, XKB_KEY_0, view, {.ui = ~0} },
        { MODKEY, XKB_KEY_o, focusmon, {.i = WLR_DIRECTION_LEFT} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_O, tagmon, {.i = WLR_DIRECTION_LEFT} },
        TAGKEYS(XKB_KEY_1, XKB_KEY_exclam, 0),
        TAGKEYS(XKB_KEY_2, XKB_KEY_quotedbl, 1),
        TAGKEYS(XKB_KEY_3, XKB_KEY_periodcentered, 2),
        TAGKEYS(XKB_KEY_4, XKB_KEY_dollar, 3),
        TAGKEYS(XKB_KEY_5, XKB_KEY_percent, 4),
        TAGKEYS(XKB_KEY_6, XKB_KEY_ampersand, 5),
        TAGKEYS(XKB_KEY_7, XKB_KEY_slash, 6),
        TAGKEYS(XKB_KEY_8, XKB_KEY_parenleft, 7),
        TAGKEYS(XKB_KEY_9, XKB_KEY_parenright, 8),
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Q, spawn, SHCMD("pkill -x someblocks && pkill -x dwl") },

        /* Change TTYs */
        #define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
        CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
        CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
    };

    static const Key lockedkeys[] = {
        { 0, XKB_KEY_XF86AudioMute, spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle && kill -44 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioLowerVolume, spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%- && kill -44 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioRaiseVolume, spawn, SHCMD("wpctl set-volume -l 1.5 @DEFAULT_AUDIO_SINK@ 5%+ && kill -44 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86MonBrightnessUp, spawn, SHCMD("brightnessctl set +5% && kill -54 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86MonBrightnessDown, spawn, SHCMD("brightnessctl set 5%- && kill -54 $(pidof someblocks)") },
        { 0, XKB_KEY_XF86AudioPlay, spawn, SHCMD("playerctl play-pause") },
        { 0, XKB_KEY_XF86AudioNext, spawn, SHCMD("playerctl next") },
        { 0, XKB_KEY_XF86AudioPrev, spawn, SHCMD("playerctl previous") },

        CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
        CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
    };

/* Mouse actions */
    static const Button buttons[] = {
        { ClkLtSymbol, 0, BTN_LEFT, setlayout, {.v = &layouts[0]} },
        { ClkLtSymbol, 0, BTN_RIGHT, setlayout, {.v = &layouts[1]} },
        { ClkLtSymbol, 0, BTN_MIDDLE, setlayout, {.v = &layouts[2]} },
        { ClkTitle, 0, BTN_LEFT, zoom, {0} },
        { ClkStatus, 0, BTN_LEFT, spawn, SHCMD("killall bemenu || j4-dmenu-desktop --no-generic --skip-i3-exec-check -b --dmenu bemenu -t foot") },
        { ClkClient, MODKEY, BTN_LEFT, moveresize, {.ui = CurMove} },
        { ClkClient, MODKEY, BTN_MIDDLE, togglefloating, {0} },
        { ClkClient, MODKEY|WLR_MODIFIER_CTRL, BTN_LEFT, moveresize, {.ui = CurResize} },
        { ClkTagBar, 0, BTN_LEFT, view, {0} },
        { ClkTagBar, 0, BTN_MIDDLE, toggleview, {0} },
        { ClkTagBar, 0, BTN_RIGHT, movetagandview, {0} },
        { ClkTagBar, MODKEY, BTN_LEFT, toggletag, {0} },
    };
