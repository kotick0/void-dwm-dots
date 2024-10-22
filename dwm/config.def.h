/* CONFIG BY UWU KOTICK_XXX_2016 */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=12" };
static const char dmenufont[]       = "JetBrains Mono:size=12";
static const char col_gray1[]       = "#74596E";
static const char col_gray2[]       = "#8D868B";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#AD7DB5";
static const char col_brpink[]	    = "#f7b4ff";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_brpink },
};

/* tagging */
static const char *tags[] = { "λ", "II", "III", "IV", "V" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "|0.0|",      tile },    /* first entry is default */
	{ "|><|",       NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands - misc. */
static const char *termcmd[]  =    { "alacritty", NULL };
static const char *rofidruncmd[] = {"rofi", "-show", "drun", NULL};
static const char *browser[] =     {"flatpak", "run", "io.gitlab.librewolf-community", NULL};
/* Volume control */
static const char *pavucntrl[] = {"pavucontrol", "--tab=3", NULL};
static const char *volUp[] =     { "wpctl", "set-volume", "-l", "1.5", "@DEFAULT_AUDIO_SINK@", "5%+", NULL };
static const char *volDown[] =   { "wpctl", "set-volume", "-l", "1.5", "@DEFAULT_AUDIO_SINK@", "5%-", NULL };
static const char *volMute[] =   { "wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL };
/*Backlight control*/
static const char *lightUp[]   = { "light", "-A", "5", NULL };
static const char *lightDown[] = { "light", "-U", "5", NULL };
/* Dmenu shit */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };



static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = rofidruncmd } },
	{ MODKEY,             		XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_w,      spawn,      	   {.v = browser } },
	{ MODKEY,			XK_s,	   spawn,	   {.v = pavucntrl } },
      /*{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },*/
      /*{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },*/
      /*{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },*/
      /*{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },*/
	{ MODKEY,                       XK_j,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_k,      setmfact,       {.f = +0.05} },
      /*{ MODKEY,                       XK_Return, zoom,           {0} },*/
      /*{ MODKEY,                       XK_Tab,    view,           {0} },*/
	{ MODKEY,             		XK_q,      killclient,     {0} },
      /*{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },*/
      /*{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },*/
      /*{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },*/
      /*{ MODKEY,                       XK_space,  setlayout,      {0} },*/
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
/* Volume control binds */

	{ 0,                       0x1008FF11, spawn, {.v = volDown } },
	{ 0,                       0x1008FF12, spawn, {.v = volMute } },
	{ 0,                       0x1008FF13, spawn, {.v = volUp  } },
/*Backlight control binds*/
	{ 0,			   XK_F9, spawn, {.v = lightUp } },
	{ 0,			   XK_F8, spawn, {.v = lightDown } },
	

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
