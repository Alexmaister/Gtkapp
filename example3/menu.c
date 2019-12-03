#include <gtk/gtk.h>
#include <gdk/gdkkeysyms-compat.h>

#define RIGHT_CLICK 3

void toggle_statusbar (GtkWidget *widget, gpointer statusbar);
int show_popup (GtkWidget *widget, GdkEvent *event);

int main (int argc, char * argv[])
{
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *ebox;//Event box to take events

	GtkWidget *menubar;
	GtkWidget *fileMenu;
	GtkWidget *fileMi;
	GtkWidget *quitMi;

	GtkWidget *impoMenu;
	GtkWidget *impoMi;
	GtkWidget *feedMi;
	GtkWidget *mailMi;
	GtkWidget *bookMi;

	GtkWidget *tog_stat;
	GtkWidget *statusbar;
	//For mnemonics
	GtkAccelGroup *accel_group = NULL;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW(window), "SimpleMenu");
	gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size (GTK_WINDOW(window), 500, 500);

	vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

	ebox = gtk_event_box_new ();

	gtk_container_add (GTK_CONTAINER(ebox), vbox);
	gtk_container_add (GTK_CONTAINER(window), ebox);

	accel_group = gtk_accel_group_new ();
	gtk_window_add_accel_group (GTK_WINDOW(window), accel_group);

	statusbar = gtk_statusbar_new();

	menubar = gtk_menu_bar_new ();
	fileMenu = gtk_menu_new ();
	impoMenu = gtk_menu_new ();
	
	fileMi = gtk_menu_item_new_with_mnemonic ("_File"); //Alt+F to open file menu
	quitMi = gtk_menu_item_new_with_label ("Quit");
	impoMi = gtk_menu_item_new_with_label ("Import");
	feedMi = gtk_menu_item_new_with_label ("Import news feed");
	bookMi = gtk_menu_item_new_with_label ("Import bookmarks ..");
	mailMi = gtk_menu_item_new_with_label ("Mail to..");
	
	tog_stat = gtk_check_menu_item_new_with_label ("View statusbar");
	gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM(tog_stat), TRUE);

	gtk_widget_add_accelerator (quitMi, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM(fileMi), fileMenu);
	gtk_menu_shell_append (GTK_MENU_SHELL(fileMenu), impoMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(fileMenu), quitMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), fileMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(fileMenu), tog_stat);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM(impoMi), impoMenu);
	gtk_menu_shell_append (GTK_MENU_SHELL(impoMenu), feedMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(impoMenu), bookMi);
	gtk_menu_shell_append (GTK_MENU_SHELL(impoMenu), mailMi);
	


	gtk_box_pack_start (GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
	gtk_box_pack_end (GTK_BOX(vbox), statusbar, FALSE, TRUE, 0);

	g_signal_connect (G_OBJECT(window), "destroy", 
			G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect (G_OBJECT(quitMi), "activate", 
			G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect (G_OBJECT(tog_stat), "activate",
			G_CALLBACK(toggle_statusbar), statusbar);
	g_signal_connect_swapped (G_OBJECT(ebox), "button-press-event",
			G_CALLBACK(show_popup), fileMenu);

	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}

void toggle_statusbar (GtkWidget *widget, gpointer statusbar)
{
	if (gtk_check_menu_item_get_active (GTK_CHECK_MENU_ITEM(widget)))
	{
		gtk_widget_show (statusbar);
	}
	else
	{
		gtk_widget_hide (statusbar);
	}

}

int show_popup (GtkWidget *widget, GdkEvent *event)
{
	int PRESS = FALSE;
	if (event->type == GDK_BUTTON_PRESS)
	{
		GdkEventButton *bevent = (GdkEventButton *) event;

		if (bevent->button == RIGHT_CLICK)
		{
			gtk_menu_popup_at_pointer (GTK_MENU(widget), event);
		
			PRESS = TRUE;
		}

	}

	return PRESS;
}
