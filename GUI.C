#include <stdio.h>
#include <gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data) {
    fprintf(stderr, "Activate callback called\n");
    
    GtkWidget *window;
    
    // Create the window
    window = gtk_application_window_new(app);
    if (!window) {
        fprintf(stderr, "Failed to create window\n");
        return;
    }
    
    // Set window properties
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK 4");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    
    // Add a label to ensure something is visible
    GtkWidget *label = gtk_label_new("Hello, GTK 4!");
    if (!label) {
        fprintf(stderr, "Failed to create label\n");
        return;
    }
    
    gtk_window_set_child(GTK_WINDOW(window), label);
    
    // Make the window visible
    gtk_window_present(GTK_WINDOW(window));
    
    fprintf(stderr, "Window presented\n");
}

int main(int argc, char **argv) {
    fprintf(stderr, "Application starting\n");
    
    GtkApplication *app;
    int status;

    // Create the application
    app = gtk_application_new("org.example.hello", G_APPLICATION_DEFAULT_FLAGS);
    if (!app) {
        fprintf(stderr, "Failed to create application\n");
        return 1;
    }
    
    // Connect the activate signal
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    
    // Run the application
    status = g_application_run(G_APPLICATION(app), argc, argv);
    
    fprintf(stderr, "Application run completed with status: %d\n", status);
    
    // Clean up
    g_object_unref(app);

    return status;
}