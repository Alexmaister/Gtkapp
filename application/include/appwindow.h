#ifndef __APPWIN_H
#define __APPWIN_H

#include <gtk/gtk.h>
#include "../include/app.h"

#define APP_WINDOW_TYPE (app_window_get_type())
G_DECLARE_FINAL_TYPE (AppWindow, app_window, APP, WINDOW, GtkApplicationWindow)

AppWindow * app_window_new (App *app);
void app_window_open(AppWindow *win, GFile *file);

#endif /*__APPWIN_H*/
