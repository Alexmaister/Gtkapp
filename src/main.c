#include <gtk/gtk.h>

//void mainfunction (GtkApplication *app, gpointer user_data);
void button_clicked (GtkWidget *button, gpointer data);

int main(int argc, char *argv[])
{
	GtkBuilder *builder;
	GObject *window;
	GObject *button;
	GError *error = NULL;

	gtk_init(&argc, &argv);

	//Construct a GtkBuilder instance and load UI file
	builder = gtk_builder_new ();
	//Path from program is located
	if (gtk_builder_add_from_file (builder, "../src/view/view.ui", &error) == 0)
	{
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}

	window = gtk_builder_get_object (builder, "window");
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	button = gtk_builder_get_object (builder, "button1");
	g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL);

	button = gtk_builder_get_object (builder, "button2");
	g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL);
	
	button = gtk_builder_get_object (builder, "quit");
	g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

	gtk_main();

	return 0;
//	//gt_application_new p1: name to identifier app must be org.app.title format, p2:specific flags for the app
//	app = gtk_application_new ("org.maister.gtkapp", G_APPLICATION_FLAGS_NONE);
//	//g_signal_connect p1:GtkApp, p2:signal must be activate name, p3: function to connect, 
//	g_signal_connect (app, "activate", G_CALLBACK (mainfunction), NULL);
//	//g_application_run : launch the app and return the end status, p1:app, p2,p3 : command line args
//	status = g_application_run (G_APPLICATION (app), argc, argv);
//	//g_object_unref unref the app  and free memory
//	g_object_unref (app);
//	return status;
}

//void mainfunction (GtkApplication *app, gpointer user_data)
//{
//	GtkWidget *window;
//	GtkWidget *button;
//	GtkWidget *grid;
//
//	//Create window from app
//	window = gtk_application_window_new (app);
//	gtk_window_set_title (GTK_WINDOW (window), "GTKAPPLICATION");
//	gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
//	gtk_container_set_border_width (GTK_CONTAINER(window), 10);
//
//	//Create grid and pack into window
//	grid = gtk_grid_new ();
//	gtk_container_add (GTK_CONTAINER (window), grid);
//
//	//Create button and add to button container
//	button = gtk_button_new_with_label ("Click me");
//	g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL);
//	//g_signal_connect_swapped is used to can close all window in other case only the button was destroyed
//	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
//
//	//Place button in grid cell (0,0) and fill q cell hor and ver
//	gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);
//
//	//Create two button additional
//	button = gtk_button_new_with_label ("Click me2");
//	g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL);
//
//	//Place first in (1,0) and fill 
//	gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);
//	
//	button = gtk_button_new_with_label ("Click me3");
//	g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL);
//	
//	//Second in (0,1) and span 2 columns
//	gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);
//	
//	gtk_widget_show_all (window);
//
//}

void button_clicked (GtkWidget *button, gpointer data)
{
	g_print ("Hello my friends");
}
