/*********************************************************************
 * dwm customization adjusted for Zeppe-Lin.                         *
 * See dwm LICENSE file for copyright and license details.           *
 *                                                                   *
 * Copy this file (or config.def.h from sources) to config.h and     *
 * adjust conform to your needs to override this customization.      *
 *********************************************************************/

/*********************************************************************
 * Appearance.
 */

static const char          font[]             = "Iosevka Term:style=Regular:size=10";
#if 0
static const char          font[]             = "Sans Mono:size=9";
static const char          font[]             = "xos4 Terminus:style=Regular:size=9";
#endif

/* Trinity colorscheme. */
static const char          normbordercolor[]  = "#112314";  // window borders color
static const char          normbgcolor[]      = "#000000";  // background color
static const char          normfgcolor[]      = "#2e5e37";  // text color in status bar
static const char          selbordercolor[]   = "#2e5e37";  // active window border color
static const char          selbgcolor[]       = "#2e5e37";  // window title/tags background color
static const char          selfgcolor[]       = "#55af66";  // window title/tags foreground color

/* Transparency. */
#define DEFAULT_OPACITY  0.80

static const unsigned int  borderpx           = 2;          // border pixel of windows
static const unsigned int  snap               = 32;         // snap pixel
static const bool          showbar            = true;       // false means no bar
static const bool          topbar             = false;      // false means bottom bar
static const double        defaultopacity     = DEFAULT_OPACITY;

/*********************************************************************
 * Layout(s).
 */

static const float         mfact              = 0.55;       // factor of master area size [0.05..0.95]
static const int           nmaster            = 1;          // number of clients in master area
static const bool          resizehints        = false;      // true means respect size hints in tiled resizals

static const Layout layouts[] = {
/* Symbol       Arrange function
 */
 { "[]=",       tile            }, // idx:0  key:Mod+t      // first entry is default
 { "<1/1>",     NULL            }, // idx:1  key:Mod+f      // no layout function means floating behaviour
 { "[1/1]",     monocle         }, // idx:2  key:Mod+m
 { "TTT",       bstack          }, // idx:3  key:Mod+s
 { "===",       bstackhoriz     }, // idx:4  key:Mod+h
 { "###",       gaplessgrid     }, // idx:5  key:Mod+g
};

/*********************************************************************
 * Tags.
 */

/* Number of tags per monitor. */
#define TAGS    9

/* Max tag length is 22 (excludes tag number with semicolon).
 * If you want to change it, look at struct definition in dwm.c. */
static CustomTagLayout tags[][TAGS] = {
  /*
   * Monitor 0.
   */

  /*
   * Tag name  Layout idx (see "layouts" above)
   */
  {{"1/",     2}, // monocle
   {"2/",     0},
   {"3/",     5}, // gaplessgrid
   {"4/",     0},
   {"5",       0},
   {"6",       0},
   {"7",       0},
   {"8/",     0},
   {"9/",     2}, // monocle

   /*
    * Don't exceed "Number of tags per monitor" or change TAGS
    * definition value (declared above) if you want more tags.
    */
  }
  
  /*
   * Monitor 1.
   */

  /* ... */
};

static const Rule rules[] = {
  /*
   * Fixed Monitor.
   */

  /* class                instance          title                     role                      tag mask  isfloating  iscentered  monitor
   */
  { "Firefox",            NULL,             NULL,                     NULL,                     0,        false,      false,      0  },
  { "Navigator",          NULL,             NULL,                     NULL,                     0,        false,      false,      0  },

  { "Claws-mail",         NULL,             NULL,                     NULL,                     2,        false,      false,      0  },
  { "Claws-mail",         "claws-mail",     "Input password",         NULL,                     2,        true,       true,       0  },

  { "Sylpheed",           NULL,             NULL,                     NULL,                     2,        false,      false,      0  },
  { "Sylpheed",           "sylpheed",       "Input password",         NULL,                     2,        true,       true,       0  },
  { "Sylpheed",           "sylpheed",       "Warning",                NULL,                     2,        true,       true,       0  },
  { "Sylpheed",           "sylpheed",       "About",                  NULL,                     2,        true,       true,       0  },
  { "Sylpheed",           "sylpheed",       "Command line options",   NULL,                     2,        true,       true,       0  },
  { "Sylpheed",           "sylpheed",       "Plug-in manager",        NULL,                     2,        true,       true,       0  },
  { "Sylpheed",           "log_window",     "Protocol log",           NULL,                     2,        true,       true,       0  },

  { "tox",                "tox",            NULL,                     NULL,                     4,        false,      false,      0  },
  { "irc",                "tox",            NULL,                     NULL,                     4,        false,      false,      0  },

  { "rss_zeppelin",       "st",             "newsboat",               NULL,                     8,        false,      false,      0  },
  { "rss_infosec",        "st",             "newsboat",               NULL,                     8,        false,      false,      0  },

  { "Qemu-system-x86_64", "qemu",           "QEMU",                   NULL,                     128,      false,      false,      0  },

  { "moc",                "moc",            "mocp",                   NULL,                     256,      false,      false,      0  },
  { "Jukebox",            "jukebox",        NULL,                     NULL,                     256,      false,      false,      0  },
  { "Jukebox",            "jukebox",        "Progress",               "Progress",               256,      true,       true,       0  },

  /*
   * Current active monitor.
   */

  /* class                instance          title                     role                      tag mask  isfloating  iscentered  monitor
   */
  { "Ktsuss",             "ktsuss",         NULL,                     NULL,                     0,        true,       true,       -1 },
  { "Zim",                "zim",            "Zim - Web Server",       NULL,                     0,        true,       true,       -1 },
  { "todo.txt",           "todo.txt",       NULL,                     NULL,                     0,        true,       true,       -1 },
  { "notes.txt",          "notes.txt",      NULL,                     NULL,                     0,        true,       true,       -1 },
  { "mixer",              "mixer",          "mixer",                  NULL,                     0,        true,       true,       -1 },
  { "Sxiv",               "xbackground-w",  "sxiv",                   NULL,                     0,        true,       true,       -1 },
};

/*********************************************************************
 * Commands definition.
 */

/* Helper for spawning shell commands in the pre dwm-5.0 fashion. */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *drun_cmd[] = {
  "dmenu_run",
    "-p", "Run:",
    "-fn", font,
    "-nb", normbgcolor,
    "-nf", normfgcolor,
    "-sb", selbgcolor,
    "-sf", selfgcolor,
    NULL,
};
static const char *pass_cmd[] = {
  "passmenu",
    "-p", "Password:",
    "-fn", font,
    "-nb", normbgcolor,
    "-nf", normfgcolor,
    "-sb", selbgcolor,
    "-sf", selfgcolor,
    NULL
};
static const char *lock_cmd[] = { "slock", NULL };
static const char *term_cmd[] = { "st", NULL };

#define STR_HELPER(x)  #x
#define STR(x)         STR_HELPER(x)
static const char *transset_cmd[] = { "transset", "-a", "-t", STR(DEFAULT_OPACITY), NULL };

/* Music player settings. */
static const char *player_play_cmd[] = { "jukebox", "-cmd", "PlayPause", NULL };
static const char *player_stop_cmd[] = { "jukebox", "-cmd", "Stop",      NULL };
static const char *player_prev_cmd[] = { "jukebox", "-cmd", "PrevSong",  NULL };
static const char *player_next_cmd[] = { "jukebox", "-cmd", "NextSong",  NULL };
static const char *player_vol_inc[]  = { "jukebox", "-cmd", "IncVolume", NULL };
static const char *player_vol_dec[]  = { "jukebox", "-cmd", "DecVolume", NULL };
static const char *player_vol_mute[] = { "jukebox", "-cmd", "TogMute",   NULL };

/* Mixer settings. */
#ifdef __DragonFly__
static const char *mixer_mute_cmd[] = { "mixer", "vol", "0",   NULL };
static const char *mixer_dec_dec[]  = { "mixer", "vol", "-10", NULL };
static const char *mixer_inc_cmd[]  = { "mixer", "vol", "+10", NULL };
#else
static const char *mixer_mute_cmd[] = { "amixer", "sset", "Master", "toggle", NULL };
static const char *mixer_dec_cmd[]  = { "amixer", "sset", "Master", "1-",     NULL };
static const char *mixer_inc_cmd[]  = { "amixer", "sset", "Master", "1+",     NULL };
#endif

/* Notebook's backlight settings. */
static const char *backlight_dec_cmd[] = { "xbacklight", "-dec", "10", NULL };
static const char *backlight_inc_cmd[] = { "xbacklight", "-inc", "10", NULL };

/*********************************************************************
 * Keys definition.
 */

/* Mod4Mask - Windows key, Mod1Mask - Alt. */
#define MODKEY Mod4Mask

/* Multimedia keyboard definitions. */
#include <X11/XF86keysym.h>

static Key keys[] = {
/* Modifier                     Key                       Function          Argument
 */
 { MODKEY,                      XK_r,                     spawn,            {.v = drun_cmd}         },
 { MODKEY,                      XK_p,                     spawn,            {.v = pass_cmd}         },

 { MODKEY,                      XK_l,                     spawn,            {.v = lock_cmd}         },
 { MODKEY|ShiftMask,            XK_Return,                spawn,            {.v = term_cmd}         },

 { MODKEY,                      XK_b,                     togglebar,        {0}                     },

 { MODKEY,                      XK_n,                     nametag,          {0}                     },

 { MODKEY,                      XK_j,                     focusstack,       {.i = +1}               },
 { MODKEY,                      XK_k,                     focusstack,       {.i = -1}               },

 { MODKEY,                      XK_F1,                    focusnstack,      {.i = 1}                },
 { MODKEY,                      XK_F2,                    focusnstack,      {.i = 2}                },
 { MODKEY,                      XK_F3,                    focusnstack,      {.i = 3}                },
 { MODKEY,                      XK_F4,                    focusnstack,      {.i = 4}                },
 { MODKEY,                      XK_F5,                    focusnstack,      {.i = 5}                },
 { MODKEY,                      XK_F6,                    focusnstack,      {.i = 6}                },
 { MODKEY,                      XK_F7,                    focusnstack,      {.i = 7}                },
 { MODKEY,                      XK_F8,                    focusnstack,      {.i = 8}                },
 { MODKEY,                      XK_F9,                    focusnstack,      {.i = 9}                },

 { MODKEY,                      XK_i,                     incnmaster,       {.i = +1}               },
 { MODKEY,                      XK_d,                     incnmaster,       {.i = -1}               },
 { MODKEY|ShiftMask,            XK_h,                     setmfact,         {.f = -0.01}            },
 { MODKEY|ShiftMask,            XK_l,                     setmfact,         {.f = +0.01}            },

 { MODKEY,                      XK_Return,                zoom,             {0}                     },
 { MODKEY,                      XK_Tab,                   view,             {0}                     },
 { MODKEY,                      XK_c,                     killclient,       {0}                     },
 { MODKEY,                      XK_t,                     setlayout,        {.v = &layouts[0]}      },
 { MODKEY,                      XK_f,                     setlayout,        {.v = &layouts[1]}      },
 { MODKEY,                      XK_m,                     setlayout,        {.v = &layouts[2]}      },
 { MODKEY,                      XK_s,                     setlayout,        {.v = &layouts[3]}      },
 { MODKEY,                      XK_h,                     setlayout,        {.v = &layouts[4]}      },
 { MODKEY,                      XK_g,                     setlayout,        {.v = &layouts[5]}      },
 { MODKEY,                      XK_space,                 setlayout,        {0}                     },
 { MODKEY|ShiftMask,            XK_space,                 togglefloating,   {0}                     },
 { MODKEY,                      XK_0,                     view,             {.ui = ~0}              },
 { MODKEY|ShiftMask,            XK_0,                     tag,              {.ui = ~0}              },
 { MODKEY,                      XK_o,                     winview,          {0},                    },
 { MODKEY|ShiftMask,            XK_f,                     togglefullscr,    {0}                     },
 { MODKEY,                      XK_comma,                 focusmon,         {.i = -1}               },
 { MODKEY,                      XK_period,                focusmon,         {.i = +1}               },
 { MODKEY|ShiftMask,            XK_comma,                 tagmon,           {.i = -1}               },
 { MODKEY|ShiftMask,            XK_period,                tagmon,           {.i = +1}               },

 { MODKEY|ShiftMask,            XK_q,                     quit,             {0}                     },

#define TAGKEYS(KEY,TAG) \
 { MODKEY,                      KEY,                      view,             {.ui = 1 << TAG}        }, \
 { MODKEY|ControlMask,          KEY,                      toggleview,       {.ui = 1 << TAG}        }, \
 { MODKEY|ShiftMask,            KEY,                      tag,              {.ui = 1 << TAG}        }, \
 { MODKEY|ControlMask|ShiftMask,KEY,                      toggletag,        {.ui = 1 << TAG}        },

        TAGKEYS(                XK_1,                                                     0)
        TAGKEYS(                XK_2,                                                     1)
        TAGKEYS(                XK_3,                                                     2)
        TAGKEYS(                XK_4,                                                     3)
        TAGKEYS(                XK_5,                                                     4)
        TAGKEYS(                XK_6,                                                     5)
        TAGKEYS(                XK_7,                                                     6)
        TAGKEYS(                XK_8,                                                     7)
        TAGKEYS(                XK_9,                                                     8)

/* Multimedia keyboard shortcuts. */

/* Media player. */
 { 0,                           XF86XK_AudioPlay,         spawn,            {.v = player_play_cmd}  },
 { 0,                           XF86XK_AudioStop,         spawn,            {.v = player_stop_cmd}  },
 { 0,                           XF86XK_AudioPrev,         spawn,            {.v = player_prev_cmd}  },
 { 0,                           XF86XK_AudioNext,         spawn,            {.v = player_next_cmd}  },
 { MODKEY,                      XF86XK_AudioMute,         spawn,            {.v = player_vol_mute}  },
 { MODKEY,                      XF86XK_AudioLowerVolume,  spawn,            {.v = player_vol_dec}   },
 { MODKEY,                      XF86XK_AudioRaiseVolume,  spawn,            {.v = player_vol_inc}   },
/* Mixer. */
 { 0,                           XF86XK_AudioMute,         spawn,            {.v = mixer_mute_cmd}   },
 { 0,                           XF86XK_AudioLowerVolume,  spawn,            {.v = mixer_dec_cmd}    },
 { 0,                           XF86XK_AudioRaiseVolume,  spawn,            {.v = mixer_inc_cmd}    },
/* Brightness. */
 { 0,                           XF86XK_MonBrightnessUp,   spawn,            {.v = backlight_inc_cmd}},
 { 0,                           XF86XK_MonBrightnessDown, spawn,            {.v = backlight_dec_cmd}},
/* Transparency. */
 { ControlMask|Mod4Mask,        XK_t,                     spawn,            {.v = transset_cmd}     },
};

/*
 * Button definitions.
 * Click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin.
 */
static Button buttons[] = {
/* Click                Event mask      Button            Function          Argument
 */
 { ClkLtSymbol,         0,              Button1,          setlayout,        {0}                     },
 { ClkLtSymbol,         0,              Button3,          setlayout,        {.v = &layouts[2]}      },
#ifdef WINTITLE
 { ClkWinTitle,         0,              Button2,          zoom,             {0}                     },
#endif
 { ClkStatusText,       0,              Button2,          spawn,            {.v = term_cmd}         },
 { ClkClientWin,        MODKEY,         Button1,          movemouse,        {0}                     },
 { ClkClientWin,        MODKEY,         Button2,          togglefloating,   {0}                     },
 { ClkClientWin,        MODKEY,         Button3,          resizemouse,      {0}                     },
 { ClkTagBar,           0,              Button1,          view,             {0}                     },
 { ClkTagBar,           0,              Button3,          toggleview,       {0}                     },
 { ClkTagBar,           MODKEY,         Button1,          tag,              {0}                     },
 { ClkTagBar,           MODKEY,         Button3,          toggletag,        {0}                     },
};

#undef STR_HELPER
#undef STR

/* vim:sw=2:ts=2:sts=2:et:cc=140
 * End of file. */
