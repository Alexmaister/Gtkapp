#include <gtk/gtk.h>
#include <gdk/gdkkeysyms-compat.h>

int main (int argc, char * argv[])
{
	GtkWidget *window;
	GtkWidget *vbox;

	GtkWidget *menubar;
	GtkWidget *fileMenu;
	GtkWidget *fileMi;
	GtkWidget *quitMi;

	GtkWidget *impoMenu;
	GtkWidget *impoMi;
	GtkWidget *feedMi;
	GtkWidget *mailMi;
	GtkWidget *bookMi;
	//For mnemonics
	GtkAccelGroup *accel_group = NULL;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW(window), "SimpleMenu");
	gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size (GTK_WINDOW(window), 500, 500);

	vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

	gtk_container_add (GTK_CONTAINER(window), vbox);

	accel_group = gtk_accel_group_new ();
	gtk_window_add_accel_group (GTK_WINDOW(window), accel_group);

	menubar = gtk_menu_bar_new ();
	fileMenu = gtk_menu_new ();
	impoMenu = gtk_menu_new ();
	
	fileMi = gtk_menu_item_new_with_mnemonic ("_File"); //Alt+F to open file menu
	quitMi = gtk_menu_item_new_with_label ("Quit");
	impoMi = gtk_menu_item_new_with_label ("Import");
	feedMi = gtk_menu_item_new_with_label ("Import news feed");
	bookMi = gtk_menu_item_new_with_label ("Import bookmarks ..");
	mailMi = gtk_menu_item_new_with_label ("Mail to..");

	gtk_widget_add_accelerator (quitMi, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM(fileMi), fileMenu);
	gtk_menu_shell_append (GTK_MENU_SHELL(fileMenu), impoMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(fileMenu), quitMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), fileMi);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM(impoMi), impoMenu);
	gtk_menu_shell_append (GTK_MENU_SHELL(impoMenu), feedMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(impoMenu), bookMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(impoMenu), mailMi);
	


	gtk_box_pack_start (GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	g_signal_connect (G_OBJECT(window), "destroy", 
			G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect (G_OBJECT(quitMi), "activate", 
			G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}
