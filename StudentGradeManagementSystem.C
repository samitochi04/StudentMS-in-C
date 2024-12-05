#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

// Global variables for GTK
GtkWidget *window;
GtkWidget *grid;
GtkWidget *name_entry;
GtkWidget *score_entry;
GtkWidget *add_button;
GtkWidget *display_button;
GtkWidget *average_button;
GtkWidget *result_label;

char studentNames[100][50];
int studentScores[100];
int studentCount = 0;

static void add_student_clicked(GtkWidget *widget, gpointer data) {
    const gchar *name = gtk_editable_get_text(GTK_EDITABLE(name_entry));
    const gchar *score_str = gtk_editable_get_text(GTK_EDITABLE(score_entry));
    int score = atoi(score_str);

    if (strlen(name) > 0 && score >= 0) {
        strcpy(studentNames[studentCount], name);
        studentScores[studentCount] = score;
        studentCount++;

        char result_text[200];
        snprintf(result_text, sizeof(result_text), "Added: %s (Score: %d)", name, score);
        gtk_label_set_text(GTK_LABEL(result_label), result_text);

        // Clear entries
        gtk_editable_set_text(GTK_EDITABLE(name_entry), "");
        gtk_editable_set_text(GTK_EDITABLE(score_entry), "");
    }
}

static void display_students_clicked(GtkWidget *widget, gpointer data) {
    if (studentCount == 0) {
        gtk_label_set_text(GTK_LABEL(result_label), "No students to display.");
        return;
    }

    char result_text[1000] = "Students:\n";
    for (int i = 0; i < studentCount; i++) {
        char student_line[100];
        snprintf(student_line, sizeof(student_line), "%s (Score: %d)\n", 
                 studentNames[i], studentScores[i]);
        strcat(result_text, student_line);
    }
    gtk_label_set_text(GTK_LABEL(result_label), result_text);
}

static void calculate_average_clicked(GtkWidget *widget, gpointer data) {
    if (studentCount == 0) {
        gtk_label_set_text(GTK_LABEL(result_label), "No students to calculate average.");
        return;
    }

    int sum = 0;
    for (int i = 0; i < studentCount; i++) {
        sum += studentScores[i];
    }
    int average = sum / studentCount;

    char result_text[200];
    snprintf(result_text, sizeof(result_text), "Average Score: %d", average);
    gtk_label_set_text(GTK_LABEL(result_label), result_text);
}

static void activate(GtkApplication *app, gpointer user_data) {
    // Create main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Student Grade Management System");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);

    // Name input
    GtkWidget *name_label = gtk_label_new("Student Name:");
    gtk_grid_attach(GTK_GRID(grid), name_label, 0, 0, 1, 1);
    name_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 0, 1, 1);

    // Score input
    GtkWidget *score_label = gtk_label_new("Student Score:");
    gtk_grid_attach(GTK_GRID(grid), score_label, 0, 1, 1, 1);
    score_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), score_entry, 1, 1, 1, 1);

    // Add student button
    add_button = gtk_button_new_with_label("Add Student");
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_student_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 2, 1, 1);

    // Display students button
    display_button = gtk_button_new_with_label("Display Students");
    g_signal_connect(display_button, "clicked", G_CALLBACK(display_students_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), display_button, 1, 2, 1, 1);

    // Calculate average button
    average_button = gtk_button_new_with_label("Calculate Average");
    g_signal_connect(average_button, "clicked", G_CALLBACK(calculate_average_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), average_button, 0, 3, 2, 1);

    // Result label
    result_label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 4, 2, 1);

    // Show window
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.studentgrademanager", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

//  gcc -o StudentGradeManagementSystem StudentGradeManagementSystem.C `pkg-config --cflags --libs gtk4`
// ./StudentGradeManagementSystem
// cd /c/Users/temmo/Desktop/MYDOCs/LEARNING/PL/C

