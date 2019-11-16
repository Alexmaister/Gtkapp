#include <gtk/gtk.h>

void mainfunction (GtkApplication *app, gpointer user_data);
void button_clicked (GtkWidget *button, gpointer data);

int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	//gt_application_new p1: name to identifier app must be org.app.title format, p2:specific flags for the app
	app = gtk_application_new ("org.maister.gtkapp", G_APPLICATION_FLAGS_NONE);
	//g_signal_connect p1:GtkApp, p2:signal must be activate name, p3: function to connect, 
	g_signal_connect (app, "activate", G_CALLBACK (mainfunction), NULL);
	//g_application_run : launch the app and return the end status, p1:app, p2,p3 : command line args
	status = g_application_run (G_APPLICATION (app), argc, argv);
	//g_object_unref unref the app  and free memory
	g_object_unref (app);
	return status;
}

void mainfunction (GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

	//Create window from app
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "GTKAPPLICATION");
	gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);

	//Create button container and add to window
	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add (GTK_CONTAINER (window), button_box);

	//Create button and add to button container
	button = gtk_button_new_with_label ("Click me");
	g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL);
	//g_signal_connect_swapped is used to can close all window in other case only the button was destroyed
	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
	gtk_container_add (GTK_CONTAINER (button_box), button);
	gtk_widget_show_all (window);

}

void button_clicked (GtkWidget *button, gpointer data)
{
	g_print ("Hello my friends");
}
