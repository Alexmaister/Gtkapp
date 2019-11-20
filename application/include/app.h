#ifndef __APP_H
#define __APP_H

#include <gtk/gtk.h>

#define APP_TYPE (app_get_type ())

//Declaramos tipo app para API como subclase de GtkApplication
G_DECLARE_FINAL_TYPE (App, app, APP, APPLICATION, GtkApplication)

App * app_new  (void);

#endif /*__APP_H*/
