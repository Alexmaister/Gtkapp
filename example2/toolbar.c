#include <gtk/gtk.h>

int main (int argc, char* argv[])
{
	GtkWidget *window;
	GtkWidget *vbox;

	GtkWidget *toolbar;
	GtkToolItem *newTb;
	GtkToolItem *openTb;
	GtkToolItem *saveTb;
	GtkToolItem *sep;
	GtkToolItem *exitTb;


	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size (GTK_WINDOW (window), 500, 300);
	gtk_window_set_title (GTK_WINDOW (window), "Toolbar");

	//gtk_vbox_new isdeprecated
	vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add (GTK_CONTAINER (window), vbox);

	//GtkStock are deprecated
	toolbar = gtk_toolbar_new ();
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	//gtk_tool_button_new_from_stock is deprecated
	//newTb = gtk_tool_button_new_from_stock (GTK_STOCK_NEW);
	newTb = gtk_tool_button_new (gtk_image_new_from_icon_name("document-new", 10), "new");
	gtk_toolbar_insert (GTK_TOOLBAR (toolbar), newTb, -1);


	openTb = gtk_tool_button_new (gtk_image_new_from_icon_name("document-open", 10), "open");
	gtk_toolbar_insert (GTK_TOOLBAR (toolbar), openTb, -1);

	saveTb = gtk_tool_button_new (gtk_image_new_from_icon_name ("document-save", 10), "save");
	gtk_toolbar_insert (GTK_TOOLBAR (toolbar), saveTb, -1);

	sep = gtk_separator_tool_item_new ();
	gtk_toolbar_insert (GTK_TOOLBAR (toolbar), sep, -1);

	exitTb = gtk_tool_button_new (gtk_image_new_from_icon_name ("document-quit", 10), "quit");
	gtk_toolbar_insert (GTK_TOOLBAR (toolbar), exitTb, -1);

	gtk_box_pack_start (GTK_BOX (vbox), toolbar, FALSE, FALSE, 5);

	g_signal_connect (G_OBJECT (exitTb), "clicked",
			G_CALLBACK (gtk_main_quit), NULL);
	g_signal_connect (G_OBJECT (window), "destroy", 
			G_CALLBACK (gtk_main_quit), NULL);

	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}
