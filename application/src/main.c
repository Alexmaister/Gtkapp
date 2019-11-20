#include <gtk/gtk.h>

#include "../include/app.h"

 int main (int argc, char *argv[]) 
  { 
      return g_application_run (G_APPLICATION (app_new ()), argc, argv); 
  }
