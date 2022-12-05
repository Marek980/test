#include <gtk/gtk.h>

static void printHello(GtkWidget *widget, gpointer data) {
    g_print("Hello!\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "gtkPacking");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    
    grid = gtk_grid_new();
    
    gtk_container_add(GTK_CONTAINER(window), grid);
    
    button = gtk_button_new_with_label("Button 1");
    g_signal_connect(button, "clicked", G_CALLBACK(printHello), NULL);
    
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
    
    button = gtk_button_new_with_label("Button 2");
    g_signal_connect(button, "clicked", G_CALLBACK(printHello), NULL);
    
    gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);
    
    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);
    
    gtk_widget_show_all(window);
}

int main(int argc, char** argv) {
    
    GtkApplication *app;
    int status;
    
    app = gtk_application_new("com.rikuz.gtkPacking", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}
